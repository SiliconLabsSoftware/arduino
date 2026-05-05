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

#include "Zigbee.h"

extern "C" {
#include "af.h"
#include "sl_zigbee_system_common.h"
#include "network-steering.h"
#include "network-formation.h"
#include "stack-info.h"
#include "nvm3_default.h"
#include "nvm3_generic.h"
}

ZigbeeClass Zigbee;

// Callback from EmberZNet when an attribute changes due to a remote ZCL command
extern "C" void sl_zigbee_af_post_attribute_change_cb(uint8_t endpoint,
                                                      sl_zigbee_af_cluster_id_t cluster_id,
                                                      sl_zigbee_af_attribute_id_t attribute_id,
                                                      uint8_t mask,
                                                      uint16_t manufacturer_code,
                                                      uint8_t type,
                                                      uint8_t size,
                                                      uint8_t* value)
{
  (void)mask;
  (void)manufacturer_code;
  (void)type;

  ZigbeeDevice* dev = zigbee_endpoint_get_device(endpoint);
  if (dev) {
    dev->HandleAttributeChange(cluster_id, attribute_id, size, value);
  }
}

// Called by the Zigbee framework once the stack is fully initialized
extern "C" void sl_zigbee_af_main_init_cb(void)
{
}

// Callback from the network steering plugin when steering completes
extern "C" void sl_zigbee_af_network_steering_complete_cb(sl_status_t status,
                                                          uint8_t total_beacons,
                                                          uint8_t join_attempts,
                                                          uint8_t final_state)
{
  (void)total_beacons;
  (void)join_attempts;
  (void)final_state;

  if (status != SL_STATUS_OK) {
    sl_zigbee_af_network_steering_start();
  }
}

// ArduinoZigbeeAppliance base class implementation

ArduinoZigbeeAppliance::ArduinoZigbeeAppliance() :
  base_zigbee_device(nullptr)
{
}

ArduinoZigbeeAppliance::~ArduinoZigbeeAppliance()
{
}

bool ArduinoZigbeeAppliance::is_online()
{
  if (!this->base_zigbee_device) {
    return false;
  }
  return this->base_zigbee_device->IsOnline();
}

void ArduinoZigbeeAppliance::set_device_name(const char* device_name)
{
  (void)device_name;
}

void ArduinoZigbeeAppliance::set_device_change_callback(void (*cb)(void))
{
  if (this->base_zigbee_device) {
    this->base_zigbee_device->SetDeviceChangeCallback(cb);
  }
}

// ZigbeeClass implementation

void ZigbeeClass::setVendorName(const char* name)
{
  uint8_t zcl_string[33];
  uint8_t len = strlen(name);
  if (len > 32) len = 32;
  zcl_string[0] = len;
  memcpy(&zcl_string[1], name, len);
  sl_zigbee_af_write_server_attribute(1, ZCL_BASIC_CLUSTER_ID, ZCL_MANUFACTURER_NAME_ATTRIBUTE_ID,
                                      zcl_string, ZCL_CHAR_STRING_ATTRIBUTE_TYPE);
}

void ZigbeeClass::setProductName(const char* name)
{
  uint8_t zcl_string[33];
  uint8_t len = strlen(name);
  if (len > 32) len = 32;
  zcl_string[0] = len;
  memcpy(&zcl_string[1], name, len);
  sl_zigbee_af_write_server_attribute(1, ZCL_BASIC_CLUSTER_ID, ZCL_MODEL_IDENTIFIER_ATTRIBUTE_ID,
                                      zcl_string, ZCL_CHAR_STRING_ATTRIBUTE_TYPE);
}

void ZigbeeClass::begin()
{
  if (this->started) {
    return;
  }
  this->started = true;

  // Disable all dynamic endpoints - they'll be enabled individually when devices call begin()
  for (uint8_t i = 0; i < kMaxDynamicEndpoints; i++) {
    sl_zigbee_af_endpoint_enable_disable(kFirstEndpointId + i, false);
  }

  if (!this->isJoinedToNetwork()) {
    sl_zigbee_af_network_steering_start();
  }
}

bool ZigbeeClass::isJoinedToNetwork()
{
  return (sl_zigbee_af_network_state() == SL_ZIGBEE_JOINED_NETWORK);
}

uint8_t ZigbeeClass::getChannel()
{
  return sl_zigbee_af_get_radio_channel();
}

uint16_t ZigbeeClass::getPanId()
{
  return sl_zigbee_af_get_pan_id();
}

uint16_t ZigbeeClass::getNodeId()
{
  return sl_zigbee_af_get_node_id();
}

void ZigbeeClass::leaveNetwork()
{
  sl_zigbee_network_status_t state = sl_zigbee_af_network_state();
  if (state == SL_ZIGBEE_JOINED_NETWORK) {
    sl_zigbee_leave_network(SL_ZIGBEE_LEAVE_NWK_WITH_NO_OPTION);
  }
}

void ZigbeeClass::factoryReset()
{
  nvm3_eraseAll(nvm3_defaultHandle);
  NVIC_SystemReset();
}

uint8_t ZigbeeClass::allocateEndpoint()
{
  for (uint8_t i = 0; i < kMaxDynamicEndpoints; i++) {
    if (!this->endpoint_allocated[i]) {
      this->endpoint_allocated[i] = true;
      uint8_t ep_id = kFirstEndpointId + i;
      sl_zigbee_af_endpoint_enable_disable(ep_id, true);
      return ep_id;
    }
  }
  return 0;
}

void ZigbeeClass::freeEndpoint(uint8_t endpoint_id)
{
  uint8_t index = endpoint_id - kFirstEndpointId;
  if (index < kMaxDynamicEndpoints && this->endpoint_allocated[index]) {
    this->endpoint_allocated[index] = false;
    sl_zigbee_af_endpoint_enable_disable(endpoint_id, false);
  }
}
