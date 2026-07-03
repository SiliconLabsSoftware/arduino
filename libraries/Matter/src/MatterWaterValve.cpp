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

#include "MatterWaterValve.h"
#include <app/CommandHandlerInterface.h>
#include <app/CommandHandlerInterfaceRegistry.h>
#include <lib/support/CodeUtils.h>

using namespace ::chip;
using namespace ::chip::Platform;
using namespace ::chip::Credentials;
using namespace ::chip::app::Clusters;
using namespace ::chip::app::Clusters::ValveConfigurationAndControl;
using namespace ::chip::app::DataModel;

const EmberAfDeviceType gWaterValveDeviceTypes[] = { { DEVICE_TYPE_WATER_VALVE, DEVICE_VERSION_DEFAULT } };

constexpr CommandId waterValveIncomingCommands[] = {
  app::Clusters::ValveConfigurationAndControl::Commands::Open::Id,
  app::Clusters::ValveConfigurationAndControl::Commands::Close::Id,
  kInvalidCommandId,
};

// Handles the Valve Configuration and Control cluster's Open and Close commands.
class WaterValveCommandHandler : public app::CommandHandlerInterface {
public:
  WaterValveCommandHandler(EndpointId endpoint, DeviceWaterValve* device) :
    app::CommandHandlerInterface(MakeOptional(endpoint), ValveConfigurationAndControl::Id),
    device(device)
  {
    ;
  }

  void InvokeCommand(HandlerContext& handlerContext) override
  {
    HandleCommand<Commands::Open::DecodableType>(
      handlerContext, [this](HandlerContext& ctx, const Commands::Open::DecodableType& req) {
      if (req.openDuration.HasValue() && !req.openDuration.Value().IsNull()) {
        this->device->Open(true, req.openDuration.Value().Value());
      } else {
        this->device->Open(false, 0);
      }
      ctx.mCommandHandler.AddStatus(ctx.mRequestPath, Protocols::InteractionModel::Status::Success);
    });
    HandleCommand<Commands::Close::DecodableType>(
      handlerContext, [this](HandlerContext& ctx, const Commands::Close::DecodableType& req) {
      (void)req;
      this->device->Close();
      ctx.mCommandHandler.AddStatus(ctx.mRequestPath, Protocols::InteractionModel::Status::Success);
    });
  }

private:
  DeviceWaterValve* device;
};

// Valve Configuration and Control cluster attributes
DECLARE_DYNAMIC_ATTRIBUTE_LIST_BEGIN(waterValveConfigurationAndControlAttrs)
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::OpenDuration::Id, INT32U, 4, 0),          /* Open Duration */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::DefaultOpenDuration::Id, INT32U, 4, ATTRIBUTE_MASK_WRITABLE), /* Default Open Duration */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::RemainingDuration::Id, INT32U, 4, 0),     /* Remaining Duration */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::CurrentState::Id, ENUM8, 1, 0),           /* Current State */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::TargetState::Id, ENUM8, 1, 0),            /* Target State */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::ValveFault::Id, BITMAP16, 2, 0),          /* Valve Fault */
DECLARE_DYNAMIC_ATTRIBUTE(ValveConfigurationAndControl::Attributes::FeatureMap::Id, BITMAP32, 4, 0),          /* FeatureMap */
DECLARE_DYNAMIC_ATTRIBUTE_LIST_END();                                                                          /* ClusterRevision auto added by LIST_END */

// Water valve endpoint cluster list
DECLARE_DYNAMIC_CLUSTER_LIST_BEGIN(waterValveEndpointClusters)
DECLARE_DYNAMIC_CLUSTER(ValveConfigurationAndControl::Id, waterValveConfigurationAndControlAttrs, ZAP_CLUSTER_MASK(SERVER), waterValveIncomingCommands, nullptr),
DECLARE_DYNAMIC_CLUSTER(Descriptor::Id, descriptorAttrs, ZAP_CLUSTER_MASK(SERVER), nullptr, nullptr),
DECLARE_DYNAMIC_CLUSTER(BridgedDeviceBasicInformation::Id, bridgedDeviceBasicAttrs, ZAP_CLUSTER_MASK(SERVER), nullptr, nullptr),
DECLARE_DYNAMIC_CLUSTER(Identify::Id, identifyAttrs, ZAP_CLUSTER_MASK(SERVER), identifyIncomingCommands, nullptr)
DECLARE_DYNAMIC_CLUSTER_LIST_END;

/***************************************************************************//**
 * Constructor for MatterWaterValve
 ******************************************************************************/
MatterWaterValve::MatterWaterValve() :
  water_valve_device(nullptr),
  device_endpoint(nullptr),
  endpoint_dataversion_storage(nullptr),
  command_handler(nullptr),
  initialized(false)
{
  ;
}

/***************************************************************************//**
 * Destructor for MatterWaterValve
 ******************************************************************************/
MatterWaterValve::~MatterWaterValve()
{
  this->end();
}

/***************************************************************************//**
 * Initializes the MatterWaterValve instance
 *
 * @return true if the initialization succeeded, false otherwise
 ******************************************************************************/
bool MatterWaterValve::begin()
{
  if (this->initialized) {
    return false;
  }

  // Create new device
  DeviceWaterValve* new_water_valve_device = new (std::nothrow)DeviceWaterValve("Water Valve");
  if (new_water_valve_device == nullptr) {
    return false;
  }
  new_water_valve_device->SetReachable(true);
  new_water_valve_device->SetProductName("Water Valve");

  // Set the device instance pointer in the base class
  this->base_matter_device = new_water_valve_device;

  // Create new endpoint
  EmberAfEndpointType* new_endpoint = (EmberAfEndpointType*)malloc(sizeof(EmberAfEndpointType));
  if (new_endpoint == nullptr) {
    delete(new_water_valve_device);
    return false;
  }
  new_endpoint->cluster = waterValveEndpointClusters;
  new_endpoint->clusterCount = ArraySize(waterValveEndpointClusters);
  new_endpoint->endpointSize = 0;

  // Create data version storage for the endpoint
  size_t dataversion_size = ArraySize(waterValveEndpointClusters) * sizeof(DataVersion);
  DataVersion* new_sensor_data_version = (DataVersion*)malloc(dataversion_size);
  if (new_sensor_data_version == nullptr) {
    delete(new_water_valve_device);
    free(new_endpoint);
    return false;
  }

  // Add new endpoint
  int result = AddDeviceEndpoint(new_water_valve_device,
                                 new_endpoint,
                                 Span<const EmberAfDeviceType>(gWaterValveDeviceTypes),
                                 Span<DataVersion>(new_sensor_data_version, ArraySize(waterValveEndpointClusters)),
                                 1);
  if (result < 0) {
    delete(new_water_valve_device);
    free(new_endpoint);
    free(new_sensor_data_version);
    return false;
  }

  this->water_valve_device = new_water_valve_device;
  this->device_endpoint = new_endpoint;
  this->endpoint_dataversion_storage = new_sensor_data_version;

  // Register the Valve Configuration and Control cluster's Open/Close command handler -
  // this can't be serviced through the plain ember external-attribute mechanism.
  EndpointId assigned_endpoint_id = new_water_valve_device->GetEndpointId();
  this->command_handler = new (std::nothrow)WaterValveCommandHandler(assigned_endpoint_id, new_water_valve_device);
  if (this->command_handler != nullptr) {
    app::CommandHandlerInterfaceRegistry::Instance().RegisterCommandHandler(this->command_handler);
  }

  this->initialized = true;
  return true;
}

/***************************************************************************//**
 * Deinitializes the MatterWaterValve instance
 ******************************************************************************/
void MatterWaterValve::end()
{
  if (!this->initialized) {
    return;
  }
  if (this->command_handler != nullptr) {
    (void)app::CommandHandlerInterfaceRegistry::Instance().UnregisterCommandHandler(this->command_handler);
    delete(this->command_handler);
    this->command_handler = nullptr;
  }
  (void)RemoveDeviceEndpoint(this->water_valve_device);
  free(this->device_endpoint);
  free(this->endpoint_dataversion_storage);
  delete(this->water_valve_device);
  this->initialized = false;
}

/***************************************************************************//**
 * Opens the valve indefinitely, or until the DefaultOpenDuration times it out if one is set
 ******************************************************************************/
void MatterWaterValve::open()
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->Open(false, 0);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Opens the valve for the given duration in seconds, after which it closes automatically -
 * requires the sketch to keep calling set_remaining_duration() to run the countdown down to 0
 *
 * @param[in] duration_seconds the duration in seconds after which the valve should close
 ******************************************************************************/
void MatterWaterValve::open(uint32_t duration_seconds)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->Open(true, duration_seconds);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Closes the valve
 ******************************************************************************/
void MatterWaterValve::close()
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->Close();
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the valve's current state
 *
 * @return the current valve state
 ******************************************************************************/
MatterWaterValve::valve_state_t MatterWaterValve::get_current_state()
{
  return (valve_state_t)this->water_valve_device->GetCurrentState();
}

/***************************************************************************//**
 * Gets the valve's target state
 *
 * @return the target valve state
 ******************************************************************************/
MatterWaterValve::valve_state_t MatterWaterValve::get_target_state()
{
  return (valve_state_t)this->water_valve_device->GetTargetState();
}

/***************************************************************************//**
 * Gets the duration in seconds used for the current/last timed open operation
 * The value is 0 if the valve was opened indefinitely.
 *
 * @return the open duration in seconds
 ******************************************************************************/
uint32_t MatterWaterValve::get_open_duration()
{
  return this->water_valve_device->GetOpenDuration();
}

/***************************************************************************//**
 * Gets the default open duration in seconds used when Open is called without an explicit duration
 * The value is 0 if no default duration is configured (the valve opens indefinitely by default).
 *
 * @return the default open duration in seconds
 ******************************************************************************/
uint32_t MatterWaterValve::get_default_open_duration()
{
  return this->water_valve_device->GetDefaultOpenDuration();
}

/***************************************************************************//**
 * Sets the default open duration in seconds used when Open is called without an explicit duration
 *
 * @param[in] duration_seconds the default open duration in seconds, 0 to disable it
 ******************************************************************************/
void MatterWaterValve::set_default_open_duration(uint32_t duration_seconds)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->SetDefaultOpenDuration(duration_seconds);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the remaining duration in seconds of the current timed open operation
 *
 * @return the remaining duration in seconds
 ******************************************************************************/
uint32_t MatterWaterValve::get_remaining_duration()
{
  return this->water_valve_device->GetRemainingDuration();
}

/***************************************************************************//**
 * Sets the remaining duration in seconds of the current timed open operation
 * Reaching 0 while the valve is open with a timed duration active automatically closes it -
 * call this periodically from the sketch's loop() to run the countdown started by open(duration_seconds).
 *
 * @param[in] remaining_duration_seconds the remaining duration in seconds
 ******************************************************************************/
void MatterWaterValve::set_remaining_duration(uint32_t remaining_duration_seconds)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->SetRemainingDuration(remaining_duration_seconds);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the valve's currently reported fault bitmap
 *
 * @return the valve fault bitmap, a combination of the valve_fault_t values
 ******************************************************************************/
uint16_t MatterWaterValve::get_valve_fault()
{
  return this->water_valve_device->GetValveFault();
}

/***************************************************************************//**
 * Sets the valve's fault bitmap
 *
 * @param[in] valve_fault the valve fault bitmap to set, a combination of the valve_fault_t values
 ******************************************************************************/
void MatterWaterValve::set_valve_fault(uint16_t valve_fault)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_valve_device->SetValveFault(valve_fault);
  PlatformMgr().UnlockChipStack();
}
