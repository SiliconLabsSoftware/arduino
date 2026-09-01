/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2026 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "MatterBindingManager.h"
#include <app/AttributeAccessInterfaceRegistry.h>
#include <app/CASESessionManager.h>
#include <app/server/Server.h>
#include <controller/InvokeInteraction.h>
#include <lib/support/CodeUtils.h>

using namespace ::chip;
using namespace ::chip::app;
using namespace ::chip::app::Clusters;

namespace {
// Builds and sends the OnOff command identified by commandId through `send`,
// which forwards it either to Controller::InvokeCommandRequest (unicast) or
// Controller::InvokeGroupCommandRequest (group) - the two call sites only
// differ in how the resulting command object is transmitted.
template <typename SendFn>
void SendOnOffCommand(CommandId commandId, SendFn&& send)
{
  switch (commandId) {
    case OnOff::Commands::Toggle::Id: {
      OnOff::Commands::Toggle::Type command;
      send(command);
      break;
    }
    case OnOff::Commands::On::Id: {
      OnOff::Commands::On::Type command;
      send(command);
      break;
    }
    case OnOff::Commands::Off::Id: {
      OnOff::Commands::Off::Type command;
      send(command);
      break;
    }
    default:
      ChipLogError(DeviceLayer, "Matter binding: unsupported bound command 0x%08lx", static_cast<unsigned long>(commandId));
      break;
  }
}

// Owns the pair of CHIP session-establishment callbacks for one outstanding
// unicast bound-command dispatch. Heap-allocated per dispatch (rather than
// reused as a manager member) because several bindings can be in flight for
// the same local endpoint at once, each needing its own callback identity and
// its own copy of "which remote endpoint/command this is for".
struct PendingCommand {
  PendingCommand(EndpointId remote, CommandId command) :
    remote_endpoint(remote),
    command_id(command)
  {
    ;
  }

  EndpointId remote_endpoint;
  CommandId command_id;
  Callback::Callback<OnDeviceConnected> on_connected{ &MatterBindingManager::handle_device_connected, this };
  Callback::Callback<OnDeviceConnectionFailure> on_failure{ &MatterBindingManager::handle_device_connection_failure, this };
};
} // namespace

/***************************************************************************//**
 * Constructor for MatterBindingAttributeAccess
 ******************************************************************************/
MatterBindingAttributeAccess::MatterBindingAttributeAccess(EndpointId endpoint) :
  AttributeAccessInterface(MakeOptional(endpoint), Binding::Id)
{
  ;
}

/***************************************************************************//**
 * Serves the Binding cluster's `Binding` list attribute
 ******************************************************************************/
CHIP_ERROR MatterBindingAttributeAccess::Read(const ConcreteReadAttributePath& path, AttributeValueEncoder& encoder)
{
  if (path.mAttributeId != Binding::Attributes::Binding::Id) {
    return CHIP_NO_ERROR; // Let ember handle every other attribute of this cluster
  }

  if (!MatterBindingManager::instance().is_table_ready()) {
    // Table hasn't finished loading from persistent storage yet - report an
    // empty list rather than touching it early.
    return encoder.EncodeEmptyList();
  }

  EndpointId local_endpoint = path.mEndpointId;
  return encoder.EncodeList([local_endpoint](const auto& listEncoder) -> CHIP_ERROR {
    for (auto& entry : chip::BindingTable::GetInstance()) {
      if (entry.local != local_endpoint) {
        continue;
      }

      Binding::Structs::TargetStruct::Type value;
      value.fabricIndex = entry.fabricIndex;
      value.cluster = FromStdOptional(entry.clusterId);

      if (entry.type == MATTER_UNICAST_BINDING) {
        value.node = MakeOptional(entry.nodeId);
        value.group = NullOptional;
        value.endpoint = MakeOptional(entry.remote);
      } else if (entry.type == MATTER_MULTICAST_BINDING) {
        value.node = NullOptional;
        value.group = MakeOptional(entry.groupId);
        value.endpoint = NullOptional;
      } else {
        continue;
      }

      ReturnErrorOnFailure(listEncoder.Encode(value));
    }
    return CHIP_NO_ERROR;
  });
}

/***************************************************************************//**
 * Handles writes to the Binding cluster's `Binding` list attribute - a
 * controller (e.g. Home Assistant, chip-tool) uses this to configure which
 * remote node/endpoint or group this endpoint's commands should be relayed to.
 ******************************************************************************/
CHIP_ERROR MatterBindingAttributeAccess::Write(const ConcreteDataAttributePath& path, AttributeValueDecoder& decoder)
{
  if (path.mAttributeId != Binding::Attributes::Binding::Id) {
    return CHIP_NO_ERROR; // Let ember handle every other attribute of this cluster
  }

  if (!MatterBindingManager::instance().is_table_ready()) {
    // Table hasn't finished loading from persistent storage yet - ask the
    // controller to retry rather than writing into a table that isn't linked
    // to storage yet (a write now would be silently lost).
    return CHIP_IM_GLOBAL_STATUS(Busy);
  }

  auto add_entry = [](EndpointId local_endpoint, const Binding::Structs::TargetStruct::Type& target) -> CHIP_ERROR {
                     EmberBindingTableEntry entry;
                     if (target.group.HasValue()) {
                       entry = EmberBindingTableEntry::ForGroup(target.fabricIndex, target.group.Value(), local_endpoint,
                                                                target.cluster.std_optional());
                     } else if (target.node.HasValue() && target.endpoint.HasValue()) {
                       entry = EmberBindingTableEntry::ForNode(target.fabricIndex, target.node.Value(), local_endpoint, target.endpoint.Value(),
                                                               target.cluster.std_optional());
                     } else {
                       return CHIP_IM_GLOBAL_STATUS(ConstraintError);
                     }
                     return chip::BindingTable::GetInstance().Add(entry);
                   };

  if (!path.IsListOperation() || path.mListOp == ConcreteDataAttributePath::ListOperation::ReplaceAll) {
    Binding::Attributes::Binding::TypeInfo::DecodableType new_list;
    ReturnErrorOnFailure(decoder.Decode(new_list));

    FabricIndex accessing_fabric = decoder.AccessingFabricIndex();

    // Replace only the accessing fabric's entries for this endpoint - a
    // ReplaceAll write must not touch bindings owned by another fabric
    // (multi-admin), matching the fabric-scoped-list semantics the Read()
    // path above already applies.
    auto& table = chip::BindingTable::GetInstance();
    auto iter = table.begin();
    while (iter != table.end()) {
      if (iter->local == path.mEndpointId && iter->fabricIndex == accessing_fabric) {
        ReturnErrorOnFailure(table.RemoveAt(iter));
      } else {
        ++iter;
      }
    }

    auto list_iter = new_list.begin();
    while (list_iter.Next()) {
      // Unlike the single-struct AppendItem case below, the decoder does not
      // auto-populate each list item's fabric index, so stamp it here.
      Binding::Structs::TargetStruct::DecodableType target = list_iter.GetValue();
      target.SetFabricIndex(accessing_fabric);
      ReturnErrorOnFailure(add_entry(path.mEndpointId, target));
    }
    return list_iter.GetStatus();
  }

  if (path.mListOp == ConcreteDataAttributePath::ListOperation::AppendItem) {
    Binding::Structs::TargetStruct::DecodableType item;
    ReturnErrorOnFailure(decoder.Decode(item));
    return add_entry(path.mEndpointId, item);
  }

  return CHIP_IM_GLOBAL_STATUS(UnsupportedWrite);
}

/***************************************************************************//**
 * Constructor for MatterBindingManager
 ******************************************************************************/
MatterBindingManager::MatterBindingManager() :
  initialized(false),
  table_ready(false)
{
  ;
}

/***************************************************************************//**
 * Returns the MatterBindingManager singleton
 ******************************************************************************/
MatterBindingManager& MatterBindingManager::instance()
{
  static MatterBindingManager sInstance;
  return sInstance;
}

/***************************************************************************//**
 * Loads the persistent binding table once the Matter server is running
 ******************************************************************************/
void MatterBindingManager::begin()
{
  if (this->initialized) {
    return;
  }
  this->initialized = true;

  // The binding table's persistent storage backend is only available once the
  // Matter server has started - defer to the CHIP event queue so this runs
  // after Matter.begin() has finished bringing the server up. table_ready
  // only flips once this has actually completed - every entry point that
  // touches the BindingTable (notify_bound_cluster_changed, and the Binding
  // attribute's Read()/Write()) gates on it, so an early access can't hit a
  // table that isn't linked to persistent storage / loaded yet.
  PlatformMgr().ScheduleWork([](intptr_t) {
    chip::Server& server = chip::Server::GetInstance();
    chip::BindingTable::GetInstance().SetPersistentStorage(&server.GetPersistentStorage());
    CHIP_ERROR err = chip::BindingTable::GetInstance().LoadFromStorage();
    if (err != CHIP_NO_ERROR) {
      ChipLogError(DeviceLayer, "Matter binding: failed to load the binding table: %" CHIP_ERROR_FORMAT, err.Format());
    }
    MatterBindingManager::instance().table_ready = true;
  }, 0);
}

/***************************************************************************//**
 * Dispatches commandId of clusterId to every binding table entry registered
 * against localEndpoint
 ******************************************************************************/
void MatterBindingManager::notify_bound_cluster_changed(EndpointId local_endpoint, ClusterId cluster_id, CommandId command_id)
{
  if (!this->table_ready) {
    // The binding table hasn't finished loading from persistent storage yet
    // (begin() was just called) - nothing to dispatch to, and touching the
    // table before it's linked to storage isn't safe.
    return;
  }

  for (auto& entry : chip::BindingTable::GetInstance()) {
    if (entry.local != local_endpoint) {
      continue;
    }
    if (entry.clusterId.has_value() && entry.clusterId.value() != cluster_id) {
      continue;
    }

    if (entry.type == MATTER_UNICAST_BINDING) {
      this->dispatch_unicast(entry, command_id);
    } else if (entry.type == MATTER_MULTICAST_BINDING) {
      this->dispatch_group(entry, command_id);
    }
  }
}

/***************************************************************************//**
 * Establishes (or reuses) a CASE session to a unicast binding target, then
 * sends the bound command once connected
 ******************************************************************************/
void MatterBindingManager::dispatch_unicast(const EmberBindingTableEntry& entry, CommandId command_id)
{
  PendingCommand* pending = new (std::nothrow) PendingCommand(entry.remote, command_id);
  if (pending == nullptr) {
    ChipLogError(DeviceLayer, "Matter binding: out of memory dispatching bound command");
    return;
  }

  chip::Server::GetInstance().GetCASESessionManager()->FindOrEstablishSession(
    ScopedNodeId(entry.nodeId, entry.fabricIndex),
    &pending->on_connected,
    &pending->on_failure);
}

/***************************************************************************//**
 * Sends the bound command to every member of a multicast (group) binding
 * target - no session establishment needed for group messaging
 ******************************************************************************/
void MatterBindingManager::dispatch_group(const EmberBindingTableEntry& entry, CommandId command_id)
{
  Messaging::ExchangeManager& exchange_mgr = chip::Server::GetInstance().GetExchangeManager();
  SendOnOffCommand(command_id, [&](auto& command) {
    CHIP_ERROR err = Controller::InvokeGroupCommandRequest(&exchange_mgr, entry.fabricIndex, entry.groupId, command);
    if (err != CHIP_NO_ERROR) {
      ChipLogError(DeviceLayer, "Matter binding: failed to send group command: %" CHIP_ERROR_FORMAT, err.Format());
    }
  });
}

/***************************************************************************//**
 * CASESessionManager success callback - sends the pending command once the
 * session to the bound node is ready
 ******************************************************************************/
void MatterBindingManager::handle_device_connected(void* context, Messaging::ExchangeManager& exchange_mgr, const SessionHandle& session_handle)
{
  PendingCommand* pending = static_cast<PendingCommand*>(context);

  auto on_success = [](const ConcreteCommandPath&, const StatusIB&, const auto&) {
                      ChipLogProgress(DeviceLayer, "Matter binding: bound command succeeded");
                    };
  auto on_failure = [](CHIP_ERROR error) {
                      ChipLogError(DeviceLayer, "Matter binding: bound command failed: %" CHIP_ERROR_FORMAT, error.Format());
                    };

  SendOnOffCommand(pending->command_id, [&](auto& command) {
    CHIP_ERROR err = Controller::InvokeCommandRequest(&exchange_mgr, session_handle, pending->remote_endpoint, command,
                                                      on_success, on_failure);
    if (err != CHIP_NO_ERROR) {
      ChipLogError(DeviceLayer, "Matter binding: failed to send bound command: %" CHIP_ERROR_FORMAT, err.Format());
    }
  });

  delete(pending);
}

/***************************************************************************//**
 * CASESessionManager failure callback - the bound command is simply dropped,
 * matching how a real Matter light switch behaves when its bound peer is
 * unreachable
 ******************************************************************************/
void MatterBindingManager::handle_device_connection_failure(void* context, const ScopedNodeId& peer_id, CHIP_ERROR error)
{
  ChipLogError(DeviceLayer, "Matter binding: failed to connect to bound node 0x" ChipLogFormatX64 ": %" CHIP_ERROR_FORMAT,
               ChipLogValueX64(peer_id.GetNodeId()), error.Format());
  delete(static_cast<PendingCommand*>(context));
}
