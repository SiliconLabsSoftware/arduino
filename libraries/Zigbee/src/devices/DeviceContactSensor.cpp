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

#include "DeviceContactSensor.h"
#include "../ZigbeeAfLock.h"

extern "C" {
#include "sl_status.h"
#include "af.h"
#include "af-types.h"
#include "zap-id.h"
#include "zap-type.h"
#include "app/framework/plugin/ias-zone-server/ias-zone-server.h"
}

DeviceContactSensor::DeviceContactSensor(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id),
  state_value(false)
{
}

bool DeviceContactSensor::GetStateValue()
{
  return this->state_value;
}

void DeviceContactSensor::RestoreEnrollmentState()
{
  ZigbeeAfLock lock;

  uint8_t cie_address[EUI64_SIZE];
  uint8_t zone_id = 0xFF;
  uint8_t zone_state = SL_ZIGBEE_ZCL_IAS_ZONE_STATE_NOT_ENROLLED;
  sl_zigbee_af_status_t res;

  res = sl_zigbee_af_read_server_attribute(this->endpoint_id,
                                           ZCL_IAS_ZONE_CLUSTER_ID,
                                           ZCL_IAS_CIE_ADDRESS_ATTRIBUTE_ID,
                                           cie_address,
                                           sizeof(cie_address));
  if (res != SL_ZIGBEE_ZCL_STATUS_SUCCESS) {
    return;
  }

  res = sl_zigbee_af_read_server_attribute(this->endpoint_id,
                                           ZCL_IAS_ZONE_CLUSTER_ID,
                                           ZCL_ZONE_ID_ATTRIBUTE_ID,
                                           &zone_id,
                                           sizeof(zone_id));
  if (res != SL_ZIGBEE_ZCL_STATUS_SUCCESS) {
    return;
  }

  if (!hasValidIasCieAddress(cie_address) || zone_id == 0xFF) {
    return;
  }

  zone_state = SL_ZIGBEE_ZCL_IAS_ZONE_STATE_ENROLLED;
  (void)sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                            ZCL_IAS_ZONE_CLUSTER_ID,
                                            ZCL_ZONE_STATE_ATTRIBUTE_ID,
                                            &zone_state,
                                            ZCL_ENUM8_ATTRIBUTE_TYPE);
}

void DeviceContactSensor::SetStateValue(bool state_value)
{
  if (this->state_value != state_value) {
    this->state_value = state_value;
    {
      ZigbeeAfLock lock;
      RestoreEnrollmentState();
      // For IAS Zone contact switches, Alarm1 represents an open contact
      uint16_t zone_status = state_value ? SL_ZIGBEE_AF_IAS_ZONE_STATUS_ALARM1 : 0;
      (void)sl_zigbee_af_ias_zone_server_update_zone_status(this->endpoint_id, zone_status, 0);
    }
    CallDeviceChangeCallback();
  }
}

void DeviceContactSensor::HandleAttributeChange(uint16_t cluster_id,
                                                uint16_t attribute_id,
                                                uint8_t size,
                                                uint8_t* value)
{
  (void)size;
  if (cluster_id == ZCL_IAS_ZONE_CLUSTER_ID && attribute_id == ZCL_ZONE_STATUS_ATTRIBUTE_ID) {
    uint16_t new_status = *((uint16_t*)value);
    bool new_state = (new_status & SL_ZIGBEE_AF_IAS_ZONE_STATUS_ALARM1) != 0;
    if (this->state_value != new_state) {
      this->state_value = new_state;
      CallDeviceChangeCallback();
    }
  }
}

bool DeviceContactSensor::hasValidIasCieAddress(const uint8_t* cie_address)
{
  for (uint8_t i = 0; i < EUI64_SIZE; i++) {
    if (cie_address[i] != 0xFF) {
      return true;
    }
  }
  return false;
}
