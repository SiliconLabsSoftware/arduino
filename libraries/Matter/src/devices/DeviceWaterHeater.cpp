/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2025 Silicon Laboratories Inc. www.silabs.com
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

#include "DeviceWaterHeater.h"

DeviceWaterHeater::DeviceWaterHeater(const char* device_name,
                                     int16_t local_temperature,
                                     int16_t heating_setpoint) :
  Device(device_name),
  local_temperature(local_temperature),
  heating_setpoint(heating_setpoint),
  system_mode(0),
  abs_min_heating_setpoint(700),
  min_heating_setpoint(1600),
  abs_max_heating_setpoint(3200),
  max_heating_setpoint(3000),
  heater_types(0x01), // Immersion element 1 by default
  heat_demand(0),
  tank_volume(100),
  tank_percentage(100),
  boost_state(0)
{
  this->SetDeviceType(device_type_t::kDeviceType_WaterHeater);
}

int16_t DeviceWaterHeater::GetLocalTemperatureValue()
{
  return this->local_temperature;
}

void DeviceWaterHeater::SetLocalTemperatureValue(int16_t local_temp)
{
  bool changed = this->local_temperature != local_temp;
  ChipLogProgress(DeviceLayer, "WaterHeaterDevice[%s]: new local temp='%d'", this->device_name, local_temp);
  this->local_temperature = local_temp;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_LocalTemperatureValue);
    CallDeviceChangeCallback();
  }
}

int16_t DeviceWaterHeater::GetHeatingSetpointValue()
{
  return this->heating_setpoint;
}

void DeviceWaterHeater::SetHeatingSetpointValue(int16_t heating_setpoint)
{
  bool changed = this->heating_setpoint != heating_setpoint;

  if (heating_setpoint < this->abs_min_heating_setpoint) {
    heating_setpoint = this->abs_min_heating_setpoint;
  }
  if (heating_setpoint > this->abs_max_heating_setpoint) {
    heating_setpoint = this->abs_max_heating_setpoint;
  }

  ChipLogProgress(DeviceLayer, "WaterHeaterDevice[%s]: new heating setpoint='%d'", this->device_name, heating_setpoint);
  this->heating_setpoint = heating_setpoint;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_HeatingSetpointValue);
    CallDeviceChangeCallback();
  }
}

uint8_t DeviceWaterHeater::GetSystemMode()
{
  return this->system_mode;
}

void DeviceWaterHeater::SetSystemMode(uint8_t system_mode)
{
  bool changed = this->system_mode != system_mode;
  ChipLogProgress(DeviceLayer, "WaterHeaterDevice[%s]: new system mode='%u'", this->device_name, system_mode);
  this->system_mode = system_mode;

  // Derive the currently active heat sources from the system mode - when the
  // water heater is heating, assume all of its available heater types are engaged.
  uint8_t new_heat_demand = (system_mode != 0) ? this->heater_types : 0;
  bool heat_demand_changed = this->heat_demand != new_heat_demand;
  this->heat_demand = new_heat_demand;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_SystemModeValue);
    CallDeviceChangeCallback();
  }
  if (heat_demand_changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_HeatDemandValue);
    CallDeviceChangeCallback();
  }
}

uint8_t DeviceWaterHeater::GetControlSequenceOfOperation()
{
  return this->thermostat_control_sequence_of_operation;
}

uint32_t DeviceWaterHeater::GetThermostatClusterFeatureMap()
{
  return this->thermostat_cluster_feature_map;
}

uint16_t DeviceWaterHeater::GetThermostatClusterRevision()
{
  return this->thermostat_cluster_revision;
}

void DeviceWaterHeater::SetAbsMinHeatingSetpoint(int16_t abs_min_heating_setpoint)
{
  if (abs_min_heating_setpoint > this->min_heating_setpoint) {
    return;
  }
  this->abs_min_heating_setpoint = abs_min_heating_setpoint;
}

int16_t DeviceWaterHeater::GetAbsMinHeatingSetpoint()
{
  return this->abs_min_heating_setpoint;
}

void DeviceWaterHeater::SetMinHeatingSetpoint(int16_t min_heating_setpoint)
{
  if (min_heating_setpoint < this->abs_min_heating_setpoint) {
    return;
  }
  this->min_heating_setpoint = min_heating_setpoint;
}

int16_t DeviceWaterHeater::GetMinHeatingSetpoint()
{
  return this->min_heating_setpoint;
}

void DeviceWaterHeater::SetAbsMaxHeatingSetpoint(int16_t abs_max_heating_setpoint)
{
  if (this->max_heating_setpoint > abs_max_heating_setpoint) {
    return;
  }
  this->abs_max_heating_setpoint = abs_max_heating_setpoint;
}

int16_t DeviceWaterHeater::GetAbsMaxHeatingSetpoint()
{
  return this->abs_max_heating_setpoint;
}

void DeviceWaterHeater::SetMaxHeatingSetpoint(int16_t max_heating_setpoint)
{
  if (max_heating_setpoint > this->abs_max_heating_setpoint) {
    return;
  }
  this->max_heating_setpoint = max_heating_setpoint;
}

int16_t DeviceWaterHeater::GetMaxHeatingSetpoint()
{
  return this->max_heating_setpoint;
}

uint8_t DeviceWaterHeater::GetHeaterTypes()
{
  return this->heater_types;
}

void DeviceWaterHeater::SetHeaterTypes(uint8_t heater_types)
{
  this->heater_types = heater_types;
}

uint8_t DeviceWaterHeater::GetHeatDemand()
{
  return this->heat_demand;
}

uint16_t DeviceWaterHeater::GetTankVolume()
{
  return this->tank_volume;
}

void DeviceWaterHeater::SetTankVolume(uint16_t tank_volume)
{
  bool changed = this->tank_volume != tank_volume;
  this->tank_volume = tank_volume;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_TankVolumeValue);
    CallDeviceChangeCallback();
  }
}

uint8_t DeviceWaterHeater::GetTankPercentage()
{
  return this->tank_percentage;
}

void DeviceWaterHeater::SetTankPercentage(uint8_t tank_percentage)
{
  if (tank_percentage > 100) {
    tank_percentage = 100;
  }

  bool changed = this->tank_percentage != tank_percentage;
  this->tank_percentage = tank_percentage;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_TankPercentageValue);
    CallDeviceChangeCallback();
  }
}

uint8_t DeviceWaterHeater::GetBoostState()
{
  return this->boost_state;
}

void DeviceWaterHeater::SetBoostState(uint8_t boost_state)
{
  bool changed = this->boost_state != boost_state;
  ChipLogProgress(DeviceLayer, "WaterHeaterDevice[%s]: new boost state='%u'", this->device_name, boost_state);
  this->boost_state = boost_state;

  if (changed) {
    this->HandleWaterHeaterDeviceStatusChanged(kChanged_BoostStateValue);
    CallDeviceChangeCallback();
  }
}

uint32_t DeviceWaterHeater::GetWaterHeaterManagementClusterFeatureMap()
{
  return this->water_heater_management_cluster_feature_map;
}

uint16_t DeviceWaterHeater::GetWaterHeaterManagementClusterRevision()
{
  return this->water_heater_management_cluster_revision;
}

CHIP_ERROR DeviceWaterHeater::HandleReadEmberAfAttribute(ClusterId clusterId,
                                                         chip::AttributeId attributeId,
                                                         uint8_t* buffer,
                                                         uint16_t maxReadLength)
{
  if (!this->reachable) {
    return CHIP_ERROR_INTERNAL;
  }

  using namespace ::chip::app::Clusters;
  ChipLogProgress(DeviceLayer, "HandleReadWaterHeaterAttribute: clusterId=%lu attrId=%ld", clusterId, attributeId);

  if (clusterId == chip::app::Clusters::BridgedDeviceBasicInformation::Id) {
    return this->HandleReadBridgedDeviceBasicAttribute(clusterId, attributeId, buffer, maxReadLength);
  }

  if (clusterId == chip::app::Clusters::Thermostat::Id) {
    using namespace ::chip::app::Clusters::Thermostat::Attributes;
    if ((attributeId == LocalTemperature::Id) && (maxReadLength == 2)) {
      int16_t localTemp = this->GetLocalTemperatureValue();
      memcpy(buffer, &localTemp, sizeof(localTemp));
    } else if ((attributeId == OccupiedHeatingSetpoint::Id) && (maxReadLength == 2)) {
      int16_t heatingSetpoint = this->GetHeatingSetpointValue();
      memcpy(buffer, &heatingSetpoint, sizeof(heatingSetpoint));
    } else if ((attributeId == SystemMode::Id) && (maxReadLength == 1)) {
      uint8_t systemMode = this->GetSystemMode();
      memcpy(buffer, &systemMode, sizeof(systemMode));
    } else if ((attributeId == ControlSequenceOfOperation::Id) && (maxReadLength == 1)) {
      uint8_t seq_op = this->GetControlSequenceOfOperation();
      memcpy(buffer, &seq_op, sizeof(seq_op));
    } else if ((attributeId == AbsMinHeatSetpointLimit::Id) && (maxReadLength == 2)) {
      int16_t abs_min_heat_setpoint = this->GetAbsMinHeatingSetpoint();
      memcpy(buffer, &abs_min_heat_setpoint, sizeof(abs_min_heat_setpoint));
    } else if ((attributeId == AbsMaxHeatSetpointLimit::Id) && (maxReadLength == 2)) {
      int16_t abs_max_heat_setpoint = this->GetAbsMaxHeatingSetpoint();
      memcpy(buffer, &abs_max_heat_setpoint, sizeof(abs_max_heat_setpoint));
    } else if ((attributeId == MinHeatSetpointLimit::Id) && (maxReadLength == 2)) {
      int16_t min_heat_setpoint = this->GetMinHeatingSetpoint();
      memcpy(buffer, &min_heat_setpoint, sizeof(min_heat_setpoint));
    } else if ((attributeId == MaxHeatSetpointLimit::Id) && (maxReadLength == 2)) {
      int16_t max_heat_setpoint = this->GetMaxHeatingSetpoint();
      memcpy(buffer, &max_heat_setpoint, sizeof(max_heat_setpoint));
    } else if ((attributeId == FeatureMap::Id) && (maxReadLength == 4)) {
      uint32_t featureMap = this->GetThermostatClusterFeatureMap();
      memcpy(buffer, &featureMap, sizeof(featureMap));
    } else if ((attributeId == ClusterRevision::Id) && (maxReadLength == 2)) {
      uint16_t clusterRevision = this->GetThermostatClusterRevision();
      memcpy(buffer, &clusterRevision, sizeof(clusterRevision));
    } else {
      return CHIP_ERROR_INVALID_ARGUMENT;
    }
    return CHIP_NO_ERROR;
  }

  if (clusterId == chip::app::Clusters::WaterHeaterManagement::Id) {
    using namespace ::chip::app::Clusters::WaterHeaterManagement::Attributes;
    if ((attributeId == HeaterTypes::Id) && (maxReadLength == 1)) {
      uint8_t heaterTypes = this->GetHeaterTypes();
      memcpy(buffer, &heaterTypes, sizeof(heaterTypes));
    } else if ((attributeId == HeatDemand::Id) && (maxReadLength == 1)) {
      uint8_t heatDemand = this->GetHeatDemand();
      memcpy(buffer, &heatDemand, sizeof(heatDemand));
    } else if ((attributeId == TankVolume::Id) && (maxReadLength == 2)) {
      uint16_t tankVolume = this->GetTankVolume();
      memcpy(buffer, &tankVolume, sizeof(tankVolume));
    } else if ((attributeId == TankPercentage::Id) && (maxReadLength == 1)) {
      uint8_t tankPercentage = this->GetTankPercentage();
      memcpy(buffer, &tankPercentage, sizeof(tankPercentage));
    } else if ((attributeId == BoostState::Id) && (maxReadLength == 1)) {
      uint8_t boostState = this->GetBoostState();
      memcpy(buffer, &boostState, sizeof(boostState));
    } else if ((attributeId == WaterHeaterManagement::Attributes::FeatureMap::Id) && (maxReadLength == 4)) {
      uint32_t featureMap = this->GetWaterHeaterManagementClusterFeatureMap();
      memcpy(buffer, &featureMap, sizeof(featureMap));
    } else if ((attributeId == WaterHeaterManagement::Attributes::ClusterRevision::Id) && (maxReadLength == 2)) {
      uint16_t clusterRevision = this->GetWaterHeaterManagementClusterRevision();
      memcpy(buffer, &clusterRevision, sizeof(clusterRevision));
    } else {
      return CHIP_ERROR_INVALID_ARGUMENT;
    }
    return CHIP_NO_ERROR;
  }

  return CHIP_ERROR_INVALID_ARGUMENT;
}

CHIP_ERROR DeviceWaterHeater::HandleWriteEmberAfAttribute(ClusterId clusterId,
                                                          chip::AttributeId attributeId,
                                                          uint8_t* buffer)
{
  if (!this->reachable) {
    return CHIP_ERROR_INTERNAL;
  }

  using namespace ::chip::app::Clusters;
  ChipLogProgress(DeviceLayer, "HandleWriteWaterHeaterAttribute: clusterId=%lu attrId=%ld", clusterId, attributeId);

  if (clusterId != chip::app::Clusters::Thermostat::Id) {
    return CHIP_ERROR_INVALID_ARGUMENT;
  }

  using namespace ::chip::app::Clusters::Thermostat::Attributes;
  if (attributeId == OccupiedHeatingSetpoint::Id) {
    this->SetHeatingSetpointValue(*((int16_t*)buffer));
  } else if (attributeId == SystemMode::Id) {
    this->SetSystemMode(*buffer);
  } else {
    return CHIP_ERROR_INVALID_ARGUMENT;
  }

  return CHIP_NO_ERROR;
}

void DeviceWaterHeater::HandleWaterHeaterDeviceStatusChanged(Changed_t itemChangedMask)
{
  using namespace ::chip::app::Clusters;

  if (itemChangedMask & kChanged_HeatingSetpointValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, Thermostat::Id, Thermostat::Attributes::OccupiedHeatingSetpoint::Id);
  }
  if (itemChangedMask & kChanged_LocalTemperatureValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, Thermostat::Id, Thermostat::Attributes::LocalTemperature::Id);
  }
  if (itemChangedMask & kChanged_SystemModeValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, Thermostat::Id, Thermostat::Attributes::SystemMode::Id);
  }
  if (itemChangedMask & kChanged_HeatDemandValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, WaterHeaterManagement::Id, WaterHeaterManagement::Attributes::HeatDemand::Id);
  }
  if (itemChangedMask & kChanged_TankVolumeValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, WaterHeaterManagement::Id, WaterHeaterManagement::Attributes::TankVolume::Id);
  }
  if (itemChangedMask & kChanged_TankPercentageValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, WaterHeaterManagement::Id, WaterHeaterManagement::Attributes::TankPercentage::Id);
  }
  if (itemChangedMask & kChanged_BoostStateValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, WaterHeaterManagement::Id, WaterHeaterManagement::Attributes::BoostState::Id);
  }
}
