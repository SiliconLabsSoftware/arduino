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

#include "DeviceWaterValve.h"

// The Matter spec requires OpenDuration/DefaultOpenDuration/RemainingDuration to be at least 1s when
// set, so "no duration configured" (internal 0) must be reported/accepted as null on the wire, using
// the ZCL convention of an all-ones value to represent null for unsigned integer attributes.
static constexpr uint32_t kNullDurationValue = 0xFFFFFFFFu;

DeviceWaterValve::DeviceWaterValve(const char* device_name) :
  Device(device_name),
  current_state(VALVE_STATE_CLOSED),
  target_state(VALVE_STATE_CLOSED),
  open_duration(0),
  default_open_duration(0),
  remaining_duration(0),
  valve_fault(0)
{
  this->SetDeviceType(device_type_t::kDeviceType_WaterValve);
}

uint8_t DeviceWaterValve::GetCurrentState()
{
  return this->current_state;
}

uint8_t DeviceWaterValve::GetTargetState()
{
  return this->target_state;
}

uint32_t DeviceWaterValve::GetOpenDuration()
{
  return this->open_duration;
}

uint32_t DeviceWaterValve::GetDefaultOpenDuration()
{
  return this->default_open_duration;
}

void DeviceWaterValve::SetDefaultOpenDuration(uint32_t default_open_duration)
{
  bool changed = this->default_open_duration != default_open_duration;
  this->default_open_duration = default_open_duration;

  if (changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_DefaultOpenDurationValue);
    CallDeviceChangeCallback();
  }
}

uint32_t DeviceWaterValve::GetRemainingDuration()
{
  return this->remaining_duration;
}

void DeviceWaterValve::SetRemainingDuration(uint32_t remaining_duration)
{
  bool changed = this->remaining_duration != remaining_duration;
  this->remaining_duration = remaining_duration;

  if (changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_RemainingDurationValue);
    CallDeviceChangeCallback();
  }

  // A running timed-open countdown reaching zero closes the valve automatically.
  if ((remaining_duration == 0) && (this->current_state == VALVE_STATE_OPEN) && (this->open_duration != 0)) {
    this->Close();
  }
}

uint16_t DeviceWaterValve::GetValveFault()
{
  return this->valve_fault;
}

void DeviceWaterValve::SetValveFault(uint16_t valve_fault)
{
  bool changed = this->valve_fault != valve_fault;
  ChipLogProgress(DeviceLayer, "WaterValveDevice[%s]: new valve fault='%u'", this->device_name, valve_fault);
  this->valve_fault = valve_fault;

  if (changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_ValveFaultValue);
    CallDeviceChangeCallback();
  }
}

void DeviceWaterValve::Open(bool has_duration, uint32_t open_duration_seconds)
{
  ChipLogProgress(DeviceLayer, "WaterValveDevice[%s]: opening", this->device_name);

  uint32_t new_open_duration = 0;
  if (has_duration) {
    new_open_duration = open_duration_seconds;
  } else if (this->default_open_duration != 0) {
    new_open_duration = this->default_open_duration;
  }

  bool open_duration_changed = this->open_duration != new_open_duration;
  this->open_duration = new_open_duration;

  bool remaining_duration_changed = this->remaining_duration != new_open_duration;
  this->remaining_duration = new_open_duration;

  bool current_state_changed = this->current_state != VALVE_STATE_OPEN;
  this->current_state = VALVE_STATE_OPEN;

  bool target_state_changed = this->target_state != VALVE_STATE_OPEN;
  this->target_state = VALVE_STATE_OPEN;

  if (current_state_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_CurrentStateValue);
  }
  if (target_state_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_TargetStateValue);
  }
  if (open_duration_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_OpenDurationValue);
  }
  if (remaining_duration_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_RemainingDurationValue);
  }
  CallDeviceChangeCallback();
}

void DeviceWaterValve::Close()
{
  ChipLogProgress(DeviceLayer, "WaterValveDevice[%s]: closing", this->device_name);

  bool current_state_changed = this->current_state != VALVE_STATE_CLOSED;
  this->current_state = VALVE_STATE_CLOSED;

  bool target_state_changed = this->target_state != VALVE_STATE_CLOSED;
  this->target_state = VALVE_STATE_CLOSED;

  bool open_duration_changed = this->open_duration != 0;
  this->open_duration = 0;

  bool remaining_duration_changed = this->remaining_duration != 0;
  this->remaining_duration = 0;

  if (current_state_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_CurrentStateValue);
  }
  if (target_state_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_TargetStateValue);
  }
  if (open_duration_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_OpenDurationValue);
  }
  if (remaining_duration_changed) {
    this->HandleWaterValveDeviceStatusChanged(kChanged_RemainingDurationValue);
  }
  CallDeviceChangeCallback();
}

uint32_t DeviceWaterValve::GetValveConfigurationAndControlClusterFeatureMap()
{
  return this->valve_configuration_and_control_cluster_feature_map;
}

uint16_t DeviceWaterValve::GetValveConfigurationAndControlClusterRevision()
{
  return this->valve_configuration_and_control_cluster_revision;
}

CHIP_ERROR DeviceWaterValve::HandleReadEmberAfAttribute(ClusterId clusterId,
                                                        chip::AttributeId attributeId,
                                                        uint8_t* buffer,
                                                        uint16_t maxReadLength)
{
  if (!this->reachable) {
    return CHIP_ERROR_INTERNAL;
  }

  using namespace ::chip::app::Clusters;
  ChipLogProgress(DeviceLayer, "HandleReadWaterValveAttribute: clusterId=%lu attrId=%ld", clusterId, attributeId);

  if (clusterId == chip::app::Clusters::BridgedDeviceBasicInformation::Id) {
    return this->HandleReadBridgedDeviceBasicAttribute(clusterId, attributeId, buffer, maxReadLength);
  }

  if (clusterId == chip::app::Clusters::ValveConfigurationAndControl::Id) {
    using namespace ::chip::app::Clusters::ValveConfigurationAndControl::Attributes;
    if ((attributeId == OpenDuration::Id) && (maxReadLength == 4)) {
      uint32_t openDuration = this->GetOpenDuration();
      uint32_t wireOpenDuration = (openDuration == 0) ? kNullDurationValue : openDuration;
      memcpy(buffer, &wireOpenDuration, sizeof(wireOpenDuration));
    } else if ((attributeId == DefaultOpenDuration::Id) && (maxReadLength == 4)) {
      uint32_t defaultOpenDuration = this->GetDefaultOpenDuration();
      uint32_t wireDefaultOpenDuration = (defaultOpenDuration == 0) ? kNullDurationValue : defaultOpenDuration;
      memcpy(buffer, &wireDefaultOpenDuration, sizeof(wireDefaultOpenDuration));
    } else if ((attributeId == RemainingDuration::Id) && (maxReadLength == 4)) {
      uint32_t remainingDuration = this->GetRemainingDuration();
      uint32_t wireRemainingDuration = (remainingDuration == 0) ? kNullDurationValue : remainingDuration;
      memcpy(buffer, &wireRemainingDuration, sizeof(wireRemainingDuration));
    } else if ((attributeId == CurrentState::Id) && (maxReadLength == 1)) {
      uint8_t currentState = this->GetCurrentState();
      memcpy(buffer, &currentState, sizeof(currentState));
    } else if ((attributeId == TargetState::Id) && (maxReadLength == 1)) {
      uint8_t targetState = this->GetTargetState();
      memcpy(buffer, &targetState, sizeof(targetState));
    } else if ((attributeId == ValveFault::Id) && (maxReadLength == 2)) {
      uint16_t valveFault = this->GetValveFault();
      memcpy(buffer, &valveFault, sizeof(valveFault));
    } else if ((attributeId == ValveConfigurationAndControl::Attributes::FeatureMap::Id) && (maxReadLength == 4)) {
      uint32_t featureMap = this->GetValveConfigurationAndControlClusterFeatureMap();
      memcpy(buffer, &featureMap, sizeof(featureMap));
    } else if ((attributeId == ValveConfigurationAndControl::Attributes::ClusterRevision::Id) && (maxReadLength == 2)) {
      uint16_t clusterRevision = this->GetValveConfigurationAndControlClusterRevision();
      memcpy(buffer, &clusterRevision, sizeof(clusterRevision));
    } else {
      return CHIP_ERROR_INVALID_ARGUMENT;
    }
    return CHIP_NO_ERROR;
  }

  return CHIP_ERROR_INVALID_ARGUMENT;
}

CHIP_ERROR DeviceWaterValve::HandleWriteEmberAfAttribute(ClusterId clusterId,
                                                         chip::AttributeId attributeId,
                                                         uint8_t* buffer)
{
  if (!this->reachable) {
    return CHIP_ERROR_INTERNAL;
  }

  using namespace ::chip::app::Clusters;
  ChipLogProgress(DeviceLayer, "HandleWriteWaterValveAttribute: clusterId=%lu attrId=%ld", clusterId, attributeId);

  if (clusterId != chip::app::Clusters::ValveConfigurationAndControl::Id) {
    return CHIP_ERROR_INVALID_ARGUMENT;
  }

  using namespace ::chip::app::Clusters::ValveConfigurationAndControl::Attributes;
  if (attributeId == DefaultOpenDuration::Id) {
    uint32_t wireDefaultOpenDuration = *((uint32_t*)buffer);
    this->SetDefaultOpenDuration((wireDefaultOpenDuration == kNullDurationValue) ? 0 : wireDefaultOpenDuration);
  } else {
    return CHIP_ERROR_INVALID_ARGUMENT;
  }

  return CHIP_NO_ERROR;
}

void DeviceWaterValve::HandleWaterValveDeviceStatusChanged(Changed_t itemChangedMask)
{
  using namespace ::chip::app::Clusters;

  if (itemChangedMask & kChanged_CurrentStateValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::CurrentState::Id);
  }
  if (itemChangedMask & kChanged_TargetStateValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::TargetState::Id);
  }
  if (itemChangedMask & kChanged_OpenDurationValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::OpenDuration::Id);
  }
  if (itemChangedMask & kChanged_DefaultOpenDurationValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::DefaultOpenDuration::Id);
  }
  if (itemChangedMask & kChanged_RemainingDurationValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::RemainingDuration::Id);
  }
  if (itemChangedMask & kChanged_ValveFaultValue) {
    ScheduleMatterReportingCallback(this->endpoint_id, ValveConfigurationAndControl::Id, ValveConfigurationAndControl::Attributes::ValveFault::Id);
  }
}
