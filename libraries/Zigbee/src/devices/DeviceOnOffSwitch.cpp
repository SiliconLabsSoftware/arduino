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

#include "DeviceOnOffSwitch.h"

extern "C" {
#include "af.h"
}

DeviceOnOffSwitch::DeviceOnOffSwitch(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id)
{
}

void DeviceOnOffSwitch::SendOn()
{
  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_on_off_cluster_on();
  sl_zigbee_af_send_command_unicast_to_bindings();
  sl_zigbee_af_fill_command_on_off_cluster_on();
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceOnOffSwitch::SendOff()
{
  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_on_off_cluster_off();
  sl_zigbee_af_send_command_unicast_to_bindings();
  sl_zigbee_af_fill_command_on_off_cluster_off();
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceOnOffSwitch::SendToggle()
{
  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_on_off_cluster_toggle();
  sl_zigbee_af_send_command_unicast_to_bindings();
  sl_zigbee_af_fill_command_on_off_cluster_toggle();
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceOnOffSwitch::HandleAttributeChange(uint16_t cluster_id,
                                              uint16_t attribute_id,
                                              uint8_t size,
                                              uint8_t* value)
{
  (void)cluster_id;
  (void)attribute_id;
  (void)size;
  (void)value;
}
