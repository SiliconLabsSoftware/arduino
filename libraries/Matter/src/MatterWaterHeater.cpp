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

#include "MatterWaterHeater.h"
#include <app/AttributeAccessInterface.h>
#include <app/AttributeAccessInterfaceRegistry.h>
#include <app/CommandHandlerInterface.h>
#include <app/CommandHandlerInterfaceRegistry.h>
#include <lib/support/CodeUtils.h>

using namespace ::chip;
using namespace ::chip::Platform;
using namespace ::chip::Credentials;
using namespace ::chip::app::Clusters;
using namespace ::chip::app::Clusters::WaterHeaterMode;
using namespace ::chip::app::DataModel;

const EmberAfDeviceType gWaterHeaterDeviceTypes[] = { { DEVICE_TYPE_WATER_HEATER, DEVICE_VERSION_DEFAULT } };

constexpr CommandId waterHeaterThermostatIncomingCommands[] = {
  app::Clusters::Thermostat::Commands::SetpointRaiseLower::Id,
  kInvalidCommandId,
};

constexpr CommandId waterHeaterModeIncomingCommands[] = {
  app::Clusters::WaterHeaterMode::Commands::ChangeToMode::Id,
  kInvalidCommandId,
};

constexpr CommandId waterHeaterManagementIncomingCommands[] = {
  app::Clusters::WaterHeaterManagement::Commands::Boost::Id,
  app::Clusters::WaterHeaterManagement::Commands::CancelBoost::Id,
  kInvalidCommandId,
};

// Fixed list of operation modes exposed by the Water Heater Mode cluster's
// SupportedModes attribute - matches MatterWaterHeater::operation_mode_t.
namespace {
const Structs::ModeTagStruct::Type kOffModeTags[]    = { { NullOptional, static_cast<uint16_t>(ModeTag::kOff) } };
const Structs::ModeTagStruct::Type kManualModeTags[] = { { NullOptional, static_cast<uint16_t>(ModeTag::kManual) } };
const Structs::ModeTagStruct::Type kEcoModeTags[]    = { { NullOptional, static_cast<uint16_t>(ModeTag::kTimed) } };

const Structs::ModeOptionStruct::Type kWaterHeaterModeOptions[] = {
  { CharSpan::fromCharString("Off"), MatterWaterHeater::OPERATION_MODE_OFF, List<const Structs::ModeTagStruct::Type>(kOffModeTags) },
  { CharSpan::fromCharString("Manual"), MatterWaterHeater::OPERATION_MODE_MANUAL, List<const Structs::ModeTagStruct::Type>(kManualModeTags) },
  { CharSpan::fromCharString("Eco"), MatterWaterHeater::OPERATION_MODE_ECO, List<const Structs::ModeTagStruct::Type>(kEcoModeTags) },
};
} // namespace

// Serves the Water Heater Mode cluster's SupportedModes list attribute, which cannot
// be represented through the plain ember external-attribute buffer mechanism used for
// every other attribute in this library.
class WaterHeaterModeAttributeAccess : public app::AttributeAccessInterface {
public:
  explicit WaterHeaterModeAttributeAccess(EndpointId endpoint) :
    app::AttributeAccessInterface(MakeOptional(endpoint), WaterHeaterMode::Id)
  {
    ;
  }

  CHIP_ERROR Read(const app::ConcreteReadAttributePath& path, app::AttributeValueEncoder& encoder) override
  {
    if (path.mAttributeId != Attributes::SupportedModes::Id) {
      return CHIP_NO_ERROR; // Let ember handle every other attribute of this cluster
    }
    return encoder.EncodeList([](const auto& listEncoder) -> CHIP_ERROR {
      for (auto& option : kWaterHeaterModeOptions) {
        ReturnErrorOnFailure(listEncoder.Encode(option));
      }
      return CHIP_NO_ERROR;
    });
  }
};

// Handles the Water Heater Mode cluster's ChangeToMode command.
class WaterHeaterModeCommandHandler : public app::CommandHandlerInterface {
public:
  WaterHeaterModeCommandHandler(EndpointId endpoint, DeviceWaterHeater* device) :
    app::CommandHandlerInterface(MakeOptional(endpoint), WaterHeaterMode::Id),
    device(device)
  {
    ;
  }

  void InvokeCommand(HandlerContext& handlerContext) override
  {
    HandleCommand<Commands::ChangeToMode::DecodableType>(
      handlerContext, [this](HandlerContext& ctx, const Commands::ChangeToMode::DecodableType& req) {
      Commands::ChangeToModeResponse::Type response;
      bool mode_supported = false;
      for (auto& option : kWaterHeaterModeOptions) {
        if (option.mode == req.newMode) {
          mode_supported = true;
          break;
        }
      }

      if (!mode_supported) {
        response.status = 1; // UnsupportedMode
      } else {
        this->device->SetCurrentMode(req.newMode);
        response.status = 0; // Success
      }

      ctx.mCommandHandler.AddResponse(ctx.mRequestPath, response);
    });
  }

private:
  DeviceWaterHeater* device;
};

// Handles the Water Heater Management cluster's Boost and CancelBoost commands.
// Home Assistant's Matter water_heater entity relies on these two commands (rather
// than the Water Heater Mode cluster) to implement its "high demand"/"eco" modes.
class WaterHeaterManagementCommandHandler : public app::CommandHandlerInterface {
public:
  WaterHeaterManagementCommandHandler(EndpointId endpoint, DeviceWaterHeater* device) :
    app::CommandHandlerInterface(MakeOptional(endpoint), WaterHeaterManagement::Id),
    device(device)
  {
    ;
  }

  void InvokeCommand(HandlerContext& handlerContext) override
  {
    HandleCommand<WaterHeaterManagement::Commands::Boost::DecodableType>(
      handlerContext, [this](HandlerContext& ctx, const WaterHeaterManagement::Commands::Boost::DecodableType& req) {
      (void)req;
      this->device->SetBoostState(1); // Active
      ctx.mCommandHandler.AddStatus(ctx.mRequestPath, Protocols::InteractionModel::Status::Success);
    });
    HandleCommand<WaterHeaterManagement::Commands::CancelBoost::DecodableType>(
      handlerContext, [this](HandlerContext& ctx, const WaterHeaterManagement::Commands::CancelBoost::DecodableType& req) {
      (void)req;
      this->device->SetBoostState(0); // Inactive
      ctx.mCommandHandler.AddStatus(ctx.mRequestPath, Protocols::InteractionModel::Status::Success);
    });
  }

private:
  DeviceWaterHeater* device;
};

// Thermostat cluster attributes
DECLARE_DYNAMIC_ATTRIBUTE_LIST_BEGIN(waterHeaterThermostatAttrs)
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::LocalTemperature::Id, INT16S, 2, 0),                                /* Local Temperature */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::ControlSequenceOfOperation::Id, INT8U, 1, 0),                       /* Control Sequence Of Operation */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::SystemMode::Id, INT8U, 1, ATTRIBUTE_MASK_WRITABLE),                 /* System Mode */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::OccupiedHeatingSetpoint::Id, INT16S, 2, ATTRIBUTE_MASK_WRITABLE),   /* Occupied Heating Setpoint */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::AbsMinHeatSetpointLimit::Id, INT16S, 2, 0),                         /* Absolute Minimum Heating Setpoint */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::AbsMaxHeatSetpointLimit::Id, INT16S, 2, 0),                         /* Absolute Maximum Heating Setpoint */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::MinHeatSetpointLimit::Id, INT16S, 2, 0),                            /* Minimum Heating Setpoint */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::MaxHeatSetpointLimit::Id, INT16S, 2, 0),                            /* Maximum Heating Setpoint */
DECLARE_DYNAMIC_ATTRIBUTE(Thermostat::Attributes::FeatureMap::Id, BITMAP32, 4, 0),                                    /* FeatureMap */
DECLARE_DYNAMIC_ATTRIBUTE_LIST_END();                                                                                 /* ClusterRevision auto added by LIST_END */

// Water Heater Management cluster attributes
DECLARE_DYNAMIC_ATTRIBUTE_LIST_BEGIN(waterHeaterManagementAttrs)
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::HeaterTypes::Id, INT8U, 1, 0),                           /* Heater Types */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::HeatDemand::Id, INT8U, 1, 0),                            /* Heat Demand */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::TankVolume::Id, INT16U, 2, 0),                           /* Tank Volume */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::TankPercentage::Id, INT8U, 1, 0),                        /* Tank Percentage */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::BoostState::Id, INT8U, 1, 0),                            /* Boost State */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterManagement::Attributes::FeatureMap::Id, BITMAP32, 4, 0),                         /* FeatureMap */
DECLARE_DYNAMIC_ATTRIBUTE_LIST_END();                                                                                 /* ClusterRevision auto added by LIST_END */

// Water Heater Mode cluster attributes
DECLARE_DYNAMIC_ATTRIBUTE_LIST_BEGIN(waterHeaterModeAttrs)
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterMode::Attributes::SupportedModes::Id, ARRAY, 0, 0),                              /* Supported Modes - served by WaterHeaterModeAttributeAccess */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterMode::Attributes::CurrentMode::Id, INT8U, 1, 0),                                 /* Current Mode */
DECLARE_DYNAMIC_ATTRIBUTE(WaterHeaterMode::Attributes::FeatureMap::Id, BITMAP32, 4, 0),                               /* FeatureMap */
DECLARE_DYNAMIC_ATTRIBUTE_LIST_END();                                                                                 /* ClusterRevision auto added by LIST_END */

// Water heater endpoint cluster list
DECLARE_DYNAMIC_CLUSTER_LIST_BEGIN(waterHeaterEndpointClusters)
DECLARE_DYNAMIC_CLUSTER(Thermostat::Id, waterHeaterThermostatAttrs, ZAP_CLUSTER_MASK(SERVER), waterHeaterThermostatIncomingCommands, nullptr),
DECLARE_DYNAMIC_CLUSTER(WaterHeaterManagement::Id, waterHeaterManagementAttrs, ZAP_CLUSTER_MASK(SERVER), waterHeaterManagementIncomingCommands, nullptr),
DECLARE_DYNAMIC_CLUSTER(WaterHeaterMode::Id, waterHeaterModeAttrs, ZAP_CLUSTER_MASK(SERVER), waterHeaterModeIncomingCommands, nullptr),
DECLARE_DYNAMIC_CLUSTER(Descriptor::Id, descriptorAttrs, ZAP_CLUSTER_MASK(SERVER), nullptr, nullptr),
DECLARE_DYNAMIC_CLUSTER(BridgedDeviceBasicInformation::Id, bridgedDeviceBasicAttrs, ZAP_CLUSTER_MASK(SERVER), nullptr, nullptr)
DECLARE_DYNAMIC_CLUSTER_LIST_END;

/***************************************************************************//**
 * Constructor for MatterWaterHeater
 ******************************************************************************/
MatterWaterHeater::MatterWaterHeater() :
  water_heater_device(nullptr),
  device_endpoint(nullptr),
  endpoint_dataversion_storage(nullptr),
  mode_attribute_access(nullptr),
  mode_command_handler(nullptr),
  management_command_handler(nullptr),
  initialized(false)
{
  ;
}

/***************************************************************************//**
 * Destructor for MatterWaterHeater
 ******************************************************************************/
MatterWaterHeater::~MatterWaterHeater()
{
  this->end();
}

/***************************************************************************//**
 * Initializes the MatterWaterHeater instance
 *
 * @return true if the initialization succeeded, false otherwise
 ******************************************************************************/
bool MatterWaterHeater::begin()
{
  if (this->initialized) {
    return false;
  }

  // Create new device
  DeviceWaterHeater* new_water_heater_device = new (std::nothrow)DeviceWaterHeater("Water Heater", 20, 20);
  if (new_water_heater_device == nullptr) {
    return false;
  }
  new_water_heater_device->SetReachable(true);
  new_water_heater_device->SetProductName("Water Heater");

  // Set the device instance pointer in the base class
  this->base_matter_device = new_water_heater_device;

  // Create new endpoint
  EmberAfEndpointType* new_endpoint = (EmberAfEndpointType*)malloc(sizeof(EmberAfEndpointType));
  if (new_endpoint == nullptr) {
    delete(new_water_heater_device);
    return false;
  }
  new_endpoint->cluster = waterHeaterEndpointClusters;
  new_endpoint->clusterCount = ArraySize(waterHeaterEndpointClusters);
  new_endpoint->endpointSize = 0;

  // Create data version storage for the endpoint
  size_t dataversion_size = ArraySize(waterHeaterEndpointClusters) * sizeof(DataVersion);
  DataVersion* new_sensor_data_version = (DataVersion*)malloc(dataversion_size);
  if (new_sensor_data_version == nullptr) {
    delete(new_water_heater_device);
    free(new_endpoint);
    return false;
  }

  // Add new endpoint
  int result = AddDeviceEndpoint(new_water_heater_device,
                                 new_endpoint,
                                 Span<const EmberAfDeviceType>(gWaterHeaterDeviceTypes),
                                 Span<DataVersion>(new_sensor_data_version, ArraySize(waterHeaterEndpointClusters)),
                                 1);
  if (result < 0) {
    delete(new_water_heater_device);
    free(new_endpoint);
    free(new_sensor_data_version);
    return false;
  }

  this->water_heater_device = new_water_heater_device;
  this->device_endpoint = new_endpoint;
  this->endpoint_dataversion_storage = new_sensor_data_version;

  // Register the Water Heater Mode cluster's list attribute and command handler -
  // these can't be serviced through the plain ember external-attribute mechanism.
  EndpointId assigned_endpoint_id = new_water_heater_device->GetEndpointId();
  this->mode_attribute_access = new (std::nothrow)WaterHeaterModeAttributeAccess(assigned_endpoint_id);
  this->mode_command_handler = new (std::nothrow)WaterHeaterModeCommandHandler(assigned_endpoint_id, new_water_heater_device);
  if (this->mode_attribute_access != nullptr) {
    app::AttributeAccessInterfaceRegistry::Instance().Register(this->mode_attribute_access);
  }
  if (this->mode_command_handler != nullptr) {
    app::CommandHandlerInterfaceRegistry::Instance().RegisterCommandHandler(this->mode_command_handler);
  }

  // Register the Water Heater Management cluster's Boost/CancelBoost command handler.
  this->management_command_handler = new (std::nothrow)WaterHeaterManagementCommandHandler(assigned_endpoint_id, new_water_heater_device);
  if (this->management_command_handler != nullptr) {
    app::CommandHandlerInterfaceRegistry::Instance().RegisterCommandHandler(this->management_command_handler);
  }

  this->initialized = true;
  return true;
}

/***************************************************************************//**
 * Deinitializes the MatterWaterHeater instance
 ******************************************************************************/
void MatterWaterHeater::end()
{
  if (!this->initialized) {
    return;
  }
  if (this->mode_attribute_access != nullptr) {
    app::AttributeAccessInterfaceRegistry::Instance().Unregister(this->mode_attribute_access);
    delete(this->mode_attribute_access);
    this->mode_attribute_access = nullptr;
  }
  if (this->mode_command_handler != nullptr) {
    (void)app::CommandHandlerInterfaceRegistry::Instance().UnregisterCommandHandler(this->mode_command_handler);
    delete(this->mode_command_handler);
    this->mode_command_handler = nullptr;
  }
  if (this->management_command_handler != nullptr) {
    (void)app::CommandHandlerInterfaceRegistry::Instance().UnregisterCommandHandler(this->management_command_handler);
    delete(this->management_command_handler);
    this->management_command_handler = nullptr;
  }
  (void)RemoveDeviceEndpoint(this->water_heater_device);
  free(this->device_endpoint);
  free(this->endpoint_dataversion_storage);
  delete(this->water_heater_device);
  this->initialized = false;
}

/***************************************************************************//**
 * Gets the water heater's currently set raw local temperature value
 * The value is in celsius x 100.
 *
 * @return the locally measured raw temperature value
 ******************************************************************************/
int16_t MatterWaterHeater::get_local_temperature_raw()
{
  return this->water_heater_device->GetLocalTemperatureValue();
}

/***************************************************************************//**
 * Sets the water heater's locally measured raw temperature value
 * The accepted value is in celsius x 100.
 *
 * @param[in] local_temp the locally measured raw temperature value to set
 ******************************************************************************/
void MatterWaterHeater::set_local_temperature_raw(int16_t local_temp)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetLocalTemperatureValue(local_temp);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Sets the water heater's raw heating setpoint value
 * The accepted value is in celsius x 100.
 *
 * @param[in] heating_setpoint the raw heating setpoint to be set
 ******************************************************************************/
void MatterWaterHeater::set_heating_setpoint_raw(int16_t heating_setpoint)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetHeatingSetpointValue(heating_setpoint);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's currently set raw heating setpoint value
 * The value is in celsius x 100.
 *
 * @return the currently set raw heating setpoint value
 ******************************************************************************/
int16_t MatterWaterHeater::get_heating_setpoint_raw()
{
  return this->water_heater_device->GetHeatingSetpointValue();
}

/***************************************************************************//**
 * Gets the water heater's currently set local temperature value in celsius
 *
 * @return the locally measured temperature value
 ******************************************************************************/
float MatterWaterHeater::get_local_temperature()
{
  return (float)this->get_local_temperature_raw() / 100.0f;
}

/***************************************************************************//**
 * Sets the water heater's locally measured temperature value in celsius
 *
 * @param[in] local_temp the locally measured temperature value to set
 ******************************************************************************/
void MatterWaterHeater::set_local_temperature(float local_temp)
{
  uint16_t raw_temp = (int16_t)(local_temp * 100.0f);
  this->set_local_temperature_raw(raw_temp);
}

/***************************************************************************//**
 * Gets the water heater's currently set heating setpoint value in celsius
 *
 * @return the currently set heating setpoint value
 ******************************************************************************/
float MatterWaterHeater::get_heating_setpoint()
{
  return (float)this->get_heating_setpoint_raw() / 100.0f;
}

/***************************************************************************//**
 * Sets the water heater's heating setpoint value in celsius
 *
 * @param[in] heating_setpoint the heating setpoint to be set
 ******************************************************************************/
void MatterWaterHeater::set_heating_setpoint(float heating_setpoint)
{
  uint16_t raw_temp = (int16_t)(heating_setpoint * 100.0f);
  this->set_heating_setpoint_raw(raw_temp);
}

/***************************************************************************//**
 * Sets the water heater's absolute minimum heating setpoint value in celsius
 * This is the heating device's physical limit which cannot be changed.
 *
 * @param[in] abs_min_heating_setpoint the absolute minimum value heating can be set to
 ******************************************************************************/
void MatterWaterHeater::set_absolute_minimum_heating_setpoint(float abs_min_heating_setpoint)
{
  uint16_t raw_temp = (int16_t)(abs_min_heating_setpoint * 100.0f);
  this->water_heater_device->SetAbsMinHeatingSetpoint(raw_temp);
}

/***************************************************************************//**
 * Sets the water heater's minimum heating setpoint value in celsius
 * This limit may be changed by the user to enforce heating policies.
 * Cannot be lower than the absolute minimum value.
 *
 * @param[in] min_heating_setpoint the minimum value heating can be set to
 ******************************************************************************/
void MatterWaterHeater::set_minimum_heating_setpoint(float min_heating_setpoint)
{
  uint16_t raw_temp = (int16_t)(min_heating_setpoint * 100.0f);
  this->water_heater_device->SetMinHeatingSetpoint(raw_temp);
}

/***************************************************************************//**
 * Sets the water heater's absolute maximum heating setpoint value in celsius
 * This is the heating device's physical limit which cannot be changed.
 *
 * @param[in] abs_max_heating_setpoint the absolute maximum value heating can be set to
 ******************************************************************************/
void MatterWaterHeater::set_absolute_maximum_heating_setpoint(float abs_max_heating_setpoint)
{
  uint16_t raw_temp = (int16_t)(abs_max_heating_setpoint * 100.0f);
  this->water_heater_device->SetAbsMaxHeatingSetpoint(raw_temp);
}

/***************************************************************************//**
 * Sets the water heater's maximum heating setpoint value in celsius
 * This limit may be changed by the user to enforce heating policies.
 * Cannot be higher than the absolute maximum value.
 *
 * @param[in] max_heating_setpoint the maximum value heating can be set to
 ******************************************************************************/
void MatterWaterHeater::set_maximum_heating_setpoint(float max_heating_setpoint)
{
  uint16_t raw_temp = (int16_t)(max_heating_setpoint * 100.0f);
  this->water_heater_device->SetMaxHeatingSetpoint(raw_temp);
}

/***************************************************************************//**
 * Gets the water heater's absolute minimum heating setpoint value in celsius
 * This is the heating device's physical limit which cannot be changed.
 *
 * @return the absolute minimum value heating can be set to
 ******************************************************************************/
float MatterWaterHeater::get_absolute_minimum_heating_setpoint()
{
  return (float)this->water_heater_device->GetAbsMinHeatingSetpoint() / 100.0f;
}

/***************************************************************************//**
 * Gets the water heater's minimum heating setpoint value in celsius
 * This limit may be changed by the user to enforce heating policies.
 * Cannot be lower than the absolute minimum value.
 *
 * @return the minimum value heating can be set to
 ******************************************************************************/
float MatterWaterHeater::get_minimum_heating_setpoint()
{
  return (float)this->water_heater_device->GetMinHeatingSetpoint() / 100.0f;
}

/***************************************************************************//**
 * Gets the water heater's absolute maximum heating setpoint value in celsius
 * This is the heating device's physical limit which cannot be changed.
 *
 * @return the absolute maximum value heating can be set to
 ******************************************************************************/
float MatterWaterHeater::get_absolute_maximum_heating_setpoint()
{
  return (float)this->water_heater_device->GetAbsMaxHeatingSetpoint() / 100.0f;
}

/***************************************************************************//**
 * Gets the water heater's maximum heating setpoint value in celsius
 * This limit may be changed by the user to enforce heating policies.
 * Cannot be higher than the absolute maximum value.
 *
 * @return the maximum value heating can be set to
 ******************************************************************************/
float MatterWaterHeater::get_maximum_heating_setpoint()
{
  return (float)this->water_heater_device->GetMaxHeatingSetpoint() / 100.0f;
}

/***************************************************************************//**
 * Gets the water heater's currently set system mode
 *
 * @return the currently set system mode
 ******************************************************************************/
MatterWaterHeater::water_heater_mode_t MatterWaterHeater::get_system_mode()
{
  return (water_heater_mode_t)this->water_heater_device->GetSystemMode();
}

/***************************************************************************//**
 * Sets the water heater's system mode
 *
 * @param[in] system_mode the system mode to be set
 ******************************************************************************/
void MatterWaterHeater::set_system_mode(MatterWaterHeater::water_heater_mode_t system_mode)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetSystemMode((uint8_t)system_mode);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's available heat source types
 * The value is a bitmap of the heater_type_t values.
 *
 * @return the currently configured heater types bitmap
 ******************************************************************************/
uint8_t MatterWaterHeater::get_heater_types()
{
  return this->water_heater_device->GetHeaterTypes();
}

/***************************************************************************//**
 * Sets the water heater's available heat source types
 * The value is a bitmap of the heater_type_t values.
 *
 * @param[in] heater_types the heater types bitmap to set
 ******************************************************************************/
void MatterWaterHeater::set_heater_types(uint8_t heater_types)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetHeaterTypes(heater_types);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's currently active heat sources
 * The value is a bitmap of the heater_type_t values that are currently engaged.
 *
 * @return the currently active heat sources bitmap
 ******************************************************************************/
uint8_t MatterWaterHeater::get_heat_demand()
{
  return this->water_heater_device->GetHeatDemand();
}

/***************************************************************************//**
 * Gets the water heater's tank volume in liters
 *
 * @return the tank volume in liters
 ******************************************************************************/
uint16_t MatterWaterHeater::get_tank_volume()
{
  return this->water_heater_device->GetTankVolume();
}

/***************************************************************************//**
 * Sets the water heater's tank volume in liters
 *
 * @param[in] tank_volume the tank volume in liters to set
 ******************************************************************************/
void MatterWaterHeater::set_tank_volume(uint16_t tank_volume)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetTankVolume(tank_volume);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's currently available hot water as a percentage of the tank volume
 *
 * @return the tank percentage (0-100)
 ******************************************************************************/
uint8_t MatterWaterHeater::get_tank_percentage()
{
  return this->water_heater_device->GetTankPercentage();
}

/***************************************************************************//**
 * Sets the water heater's currently available hot water as a percentage of the tank volume
 *
 * @param[in] tank_percentage the tank percentage (0-100) to set
 ******************************************************************************/
void MatterWaterHeater::set_tank_percentage(uint8_t tank_percentage)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetTankPercentage(tank_percentage);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's currently set boost state
 *
 * @return the currently set boost state
 ******************************************************************************/
MatterWaterHeater::boost_state_t MatterWaterHeater::get_boost_state()
{
  return (boost_state_t)this->water_heater_device->GetBoostState();
}

/***************************************************************************//**
 * Sets the water heater's boost state
 *
 * @param[in] boost_state the boost state to be set
 ******************************************************************************/
void MatterWaterHeater::set_boost_state(MatterWaterHeater::boost_state_t boost_state)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetBoostState((uint8_t)boost_state);
  PlatformMgr().UnlockChipStack();
}

/***************************************************************************//**
 * Gets the water heater's currently set operation mode
 *
 * @return the currently set operation mode
 ******************************************************************************/
MatterWaterHeater::operation_mode_t MatterWaterHeater::get_operation_mode()
{
  return (operation_mode_t)this->water_heater_device->GetCurrentMode();
}

/***************************************************************************//**
 * Sets the water heater's operation mode
 *
 * @param[in] operation_mode the operation mode to be set
 ******************************************************************************/
void MatterWaterHeater::set_operation_mode(MatterWaterHeater::operation_mode_t operation_mode)
{
  if (!this->initialized) {
    return;
  }
  PlatformMgr().LockChipStack();
  this->water_heater_device->SetCurrentMode((uint8_t)operation_mode);
  PlatformMgr().UnlockChipStack();
}
