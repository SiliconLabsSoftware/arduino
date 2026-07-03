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

#pragma once

#include "MatterDevice.h"

class DeviceWaterValve : public Device
{
public:
  enum Changed_t{
    kChanged_CurrentStateValue        = kChanged_Last << 1,
    kChanged_TargetStateValue         = kChanged_Last << 2,
    kChanged_OpenDurationValue        = kChanged_Last << 3,
    kChanged_DefaultOpenDurationValue = kChanged_Last << 4,
    kChanged_RemainingDurationValue   = kChanged_Last << 5,
    kChanged_ValveFaultValue          = kChanged_Last << 6,
  } Changed;

  // ValveStateEnum values
  enum valve_state_t {
    VALVE_STATE_CLOSED       = 0,
    VALVE_STATE_OPEN         = 1,
    VALVE_STATE_TRANSITIONING = 2
  };

  DeviceWaterValve(const char* device_name);

  uint8_t GetCurrentState();
  uint8_t GetTargetState();

  uint32_t GetOpenDuration();
  uint32_t GetDefaultOpenDuration();
  void SetDefaultOpenDuration(uint32_t default_open_duration);
  uint32_t GetRemainingDuration();
  void SetRemainingDuration(uint32_t remaining_duration);

  uint16_t GetValveFault();
  void SetValveFault(uint16_t valve_fault);

  // Opens the valve. If has_duration is false the valve stays open until Close()
  // is called or the DefaultOpenDuration attribute times it out.
  void Open(bool has_duration, uint32_t open_duration_seconds);
  void Close();

  uint32_t GetValveConfigurationAndControlClusterFeatureMap();
  uint16_t GetValveConfigurationAndControlClusterRevision();

  CHIP_ERROR HandleReadEmberAfAttribute(ClusterId clusterId,
                                        chip::AttributeId attributeId,
                                        uint8_t* buffer,
                                        uint16_t maxReadLength) override;

  CHIP_ERROR HandleWriteEmberAfAttribute(ClusterId clusterId,
                                         chip::AttributeId attributeId,
                                         uint8_t* buffer) override;

private:
  void HandleWaterValveDeviceStatusChanged(Changed_t itemChangedMask);

  uint8_t current_state;
  uint8_t target_state;
  uint32_t open_duration;         // 0 means "no timed duration" (open indefinitely)
  uint32_t default_open_duration; // 0 means "no default duration" configured
  uint32_t remaining_duration;
  uint16_t valve_fault;

  static const uint32_t valve_configuration_and_control_cluster_feature_map = 0u;
  static const uint16_t valve_configuration_and_control_cluster_revision    = 1u;
};
