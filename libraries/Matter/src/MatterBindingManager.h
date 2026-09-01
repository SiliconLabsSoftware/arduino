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

#ifndef MATTER_BINDING_MANAGER_H
#define MATTER_BINDING_MANAGER_H

#include "Matter.h"
#include <app/AttributeAccessInterface.h>
#include <app/util/binding-table.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <platform/CHIPDeviceLayer.h>
#include <atomic>

using namespace chip;
using namespace ::chip::DeviceLayer;

// Serves the standard Matter Binding cluster's list-type `Binding` attribute,
// backed by chip::BindingTable. One instance is created per endpoint that opts
// into binding support (see MatterSwitch::beginWithBinding()).
class MatterBindingAttributeAccess : public chip::app::AttributeAccessInterface {
public:
  explicit MatterBindingAttributeAccess(chip::EndpointId endpoint);

  CHIP_ERROR Read(const chip::app::ConcreteReadAttributePath& path, chip::app::AttributeValueEncoder& encoder) override;
  CHIP_ERROR Write(const chip::app::ConcreteDataAttributePath& path, chip::app::AttributeValueDecoder& decoder) override;
};

// Dispatches locally-triggered cluster commands (e.g. OnOff Toggle) to every
// target listed in the standard Matter Binding cluster's table for a given
// local endpoint - the "switch controls a bound light directly" behavior.
//
// The vendored SDK ships the Binding cluster's ZAP-generated metadata (it's
// part of the generic codegen template used for every example) but not the
// official `bindings` cluster server plugin or `BindingManager` - neither the
// source nor precompiled object code for those is present. This class instead
// builds the same behavior directly out of pieces that *are* already available
// (either precompiled into the SDK static library, or header-only templates
// compiled fresh with the sketch): chip::BindingTable, chip::CASESessionManager,
// chip::Server, chip::app::CommandSender and Controller::InvokeCommandRequest /
// InvokeGroupCommandRequest. No SDK vendoring is required.
class MatterBindingManager {
public:
  static MatterBindingManager& instance();

  // Idempotent. Schedules loading the persistent binding table once the
  // Matter server is up - safe to call multiple times / before the server
  // has started.
  void begin();

  // True once the deferred load triggered by begin() has actually completed
  // (BindingTable is linked to persistent storage and populated). Every entry
  // point that touches the BindingTable gates on this to avoid a window right
  // after begin() where the table isn't ready yet.
  bool is_table_ready() const
  {
    return this->table_ready;
  }

  // Sends commandId (e.g. OnOff::Commands::Toggle::Id) of clusterId to every
  // binding table entry registered against localEndpoint.
  void notify_bound_cluster_changed(chip::EndpointId local_endpoint, chip::ClusterId cluster_id, chip::CommandId command_id);

  // Internal - public only so the free-standing CHIP callback trampolines can
  // reach them. Not part of the public API.
  static void handle_device_connected(void* context, chip::Messaging::ExchangeManager& exchange_mgr, const chip::SessionHandle& session_handle);
  static void handle_device_connection_failure(void* context, const chip::ScopedNodeId& peer_id, CHIP_ERROR error);

private:
  MatterBindingManager();

  void dispatch_unicast(const EmberBindingTableEntry& entry, chip::CommandId command_id);
  void dispatch_group(const EmberBindingTableEntry& entry, chip::CommandId command_id);

  bool initialized;
  std::atomic<bool> table_ready;
};

#endif // MATTER_BINDING_MANAGER_H
