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

#include "DeviceOnOffLight.h"

extern "C" {
#include "af.h"
}

DeviceOnOffLight::DeviceOnOffLight(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id),
  onoff(false)
{
}

bool DeviceOnOffLight::IsOn()
{
  return this->onoff;
}

void DeviceOnOffLight::SetOnOff(bool onoff)
{
  if (this->onoff == onoff) {
    return;
  }
  this->onoff = onoff;
  uint8_t val = onoff ? 1 : 0;
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_ON_OFF_CLUSTER_ID,
                                      ZCL_ON_OFF_ATTRIBUTE_ID,
                                      &val,
                                      ZCL_BOOLEAN_ATTRIBUTE_TYPE);
  CallDeviceChangeCallback();
}

void DeviceOnOffLight::Toggle()
{
  SetOnOff(!this->onoff);
}

void DeviceOnOffLight::HandleAttributeChange(uint16_t cluster_id,
                                             uint16_t attribute_id,
                                             uint8_t size,
                                             uint8_t* value)
{
  (void)size;
  if (cluster_id == ZCL_ON_OFF_CLUSTER_ID && attribute_id == ZCL_ON_OFF_ATTRIBUTE_ID) {
    bool new_state = (*value != 0);
    if (this->onoff != new_state) {
      this->onoff = new_state;
      CallDeviceChangeCallback();
    }
  }
}
