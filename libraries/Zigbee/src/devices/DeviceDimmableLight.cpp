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

#include "DeviceDimmableLight.h"
#include "../ZigbeeAfLock.h"

extern "C" {
#include "af.h"
}

DeviceDimmableLight::DeviceDimmableLight(const char* device_name, uint8_t endpoint_id) :
  DeviceOnOffLight(device_name, endpoint_id),
  level(0)
{
}

uint8_t DeviceDimmableLight::GetLevel()
{
  return this->level;
}

void DeviceDimmableLight::SetLevel(uint8_t level)
{
  uint8_t normalized_level = NormalizeLevel(level);
  if (this->level == normalized_level) {
    return;
  }

  this->level = normalized_level;
  {
    ZigbeeAfLock lock;
    sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                        ZCL_LEVEL_CONTROL_CLUSTER_ID,
                                        ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                                        &normalized_level,
                                        ZCL_INT8U_ATTRIBUTE_TYPE);
  }
  CallDeviceChangeCallback();
}

uint8_t DeviceDimmableLight::GetBrightness()
{
  return LevelToPercent(this->level);
}

void DeviceDimmableLight::SetBrightness(uint8_t percent)
{
  SetLevel(PercentToLevel(percent));
}

void DeviceDimmableLight::RestorePersistedState()
{
  DeviceOnOffLight::RestorePersistedState();

  uint8_t value = 0;
  ZigbeeAfLock lock;
  sl_zigbee_af_status_t status = sl_zigbee_af_read_server_attribute(this->endpoint_id,
                                                                    ZCL_LEVEL_CONTROL_CLUSTER_ID,
                                                                    ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                                                                    &value,
                                                                    sizeof(value));
  if (status == SL_ZIGBEE_ZCL_STATUS_SUCCESS) {
    this->level = NormalizeLevel(value);
  }
}

void DeviceDimmableLight::HandleAttributeChange(uint16_t cluster_id,
                                                uint16_t attribute_id,
                                                uint8_t size,
                                                uint8_t* value)
{
  DeviceOnOffLight::HandleAttributeChange(cluster_id, attribute_id, size, value);

  if (cluster_id == ZCL_LEVEL_CONTROL_CLUSTER_ID
      && attribute_id == ZCL_CURRENT_LEVEL_ATTRIBUTE_ID
      && size >= 1) {
    uint8_t new_level = NormalizeLevel(*value);
    if (this->level != new_level) {
      this->level = new_level;
      CallDeviceChangeCallback();
    }
  }
}

uint8_t DeviceDimmableLight::NormalizeLevel(uint8_t level)
{
  if (level > LEVEL_CONTROL_MAX_LEVEL) {
    return LEVEL_CONTROL_MAX_LEVEL;
  }
  return level;
}

uint8_t DeviceDimmableLight::PercentToLevel(uint8_t percent)
{
  if (percent >= LEVEL_PERCENT_MAX) {
    return LEVEL_CONTROL_MAX_LEVEL;
  }
  uint16_t level = static_cast<uint16_t>(percent) * LEVEL_CONTROL_MAX_LEVEL;
  return static_cast<uint8_t>((level + (LEVEL_PERCENT_MAX / 2)) / LEVEL_PERCENT_MAX);
}

uint8_t DeviceDimmableLight::LevelToPercent(uint8_t level)
{
  uint8_t normalized_level = NormalizeLevel(level);
  if (normalized_level >= LEVEL_CONTROL_MAX_LEVEL) {
    return LEVEL_PERCENT_MAX;
  }
  uint16_t percent = static_cast<uint16_t>(normalized_level) * LEVEL_PERCENT_MAX;
  return static_cast<uint8_t>((percent + (LEVEL_CONTROL_MAX_LEVEL / 2)) / LEVEL_CONTROL_MAX_LEVEL);
}
