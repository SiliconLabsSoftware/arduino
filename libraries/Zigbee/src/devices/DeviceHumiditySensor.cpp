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

#include "DeviceHumiditySensor.h"

extern "C" {
#include "af.h"
}

DeviceHumiditySensor::DeviceHumiditySensor(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id),
  measured_value(0)
{
}

uint16_t DeviceHumiditySensor::GetMeasuredValue()
{
  return this->measured_value;
}

void DeviceHumiditySensor::SetMeasuredValue(uint16_t value)
{
  this->measured_value = value;
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID,
                                      ZCL_RELATIVE_HUMIDITY_MEASURED_VALUE_ATTRIBUTE_ID,
                                      (uint8_t*)&value,
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
  CallDeviceChangeCallback();
}

void DeviceHumiditySensor::SetMinMeasuredValue(uint16_t value)
{
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID,
                                      ZCL_RELATIVE_HUMIDITY_MIN_MEASURED_VALUE_ATTRIBUTE_ID,
                                      (uint8_t*)&value,
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
}

void DeviceHumiditySensor::SetMaxMeasuredValue(uint16_t value)
{
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID,
                                      ZCL_RELATIVE_HUMIDITY_MAX_MEASURED_VALUE_ATTRIBUTE_ID,
                                      (uint8_t*)&value,
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
}

void DeviceHumiditySensor::HandleAttributeChange(uint16_t cluster_id,
                                                  uint16_t attribute_id,
                                                  uint8_t size,
                                                  uint8_t* value)
{
  (void)size;
  if (cluster_id == ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID
      && attribute_id == ZCL_RELATIVE_HUMIDITY_MEASURED_VALUE_ATTRIBUTE_ID) {
    uint16_t new_value = *((uint16_t*)value);
    if (this->measured_value != new_value) {
      this->measured_value = new_value;
      CallDeviceChangeCallback();
    }
  }
}
