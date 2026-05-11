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

#include "Zigbee.h"

extern "C" {
#include "af.h"
#include "sl_zigbee_system_common.h"
#include "zigbee_app_framework_event.h"
#include "network-steering.h"
#include "network-formation.h"
#include "identify.h"
#include "stack-info.h"
#include "nvm3_default.h"
#include "nvm3_generic.h"
}

ZigbeeClass Zigbee;

static sl_zigbee_af_event_t network_steering_retry_event;

static void networkSteeringRetryEventHandler(sl_zigbee_af_event_t* event)
{
  (void)event;
  if (!Zigbee.isJoinedToNetwork()) {
    sl_zigbee_af_network_steering_start();
  }
}

static void initNetworkSteeringRetryEvent()
{
  static bool network_steering_retry_event_initialized = false;
  if (!network_steering_retry_event_initialized) {
    sl_zigbee_af_event_init(&network_steering_retry_event, networkSteeringRetryEventHandler);
    network_steering_retry_event_initialized = true;
  }
}

static void scheduleNetworkSteeringRetry()
{
  static constexpr uint32_t kNetworkSteeringRetryDelayMs = 250;
  initNetworkSteeringRetryEvent();
  sl_zigbee_af_event_set_delay_ms(&network_steering_retry_event, kNetworkSteeringRetryDelayMs);
}

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

// Callbacks from the Identify plugin when a remote Identify command changes state
extern "C" void sl_zigbee_af_identify_start_feedback_cb(uint8_t endpoint, uint16_t identify_time)
{
  ZigbeeDevice* dev = zigbee_endpoint_get_device(endpoint);
  if (dev) {
    dev->HandleIdentifyStart(identify_time);
  }
}

extern "C" void sl_zigbee_af_identify_stop_feedback_cb(uint8_t endpoint)
{
  ZigbeeDevice* dev = zigbee_endpoint_get_device(endpoint);
  if (dev) {
    dev->HandleIdentifyStop();
  }
}

// Called by the Zigbee framework once the stack is fully initialized
extern "C" void sl_zigbee_af_main_init_cb(void)
{
  initNetworkSteeringRetryEvent();
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
    scheduleNetworkSteeringRetry();
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

bool ArduinoZigbeeAppliance::get_identify_in_progress()
{
  if (this->base_zigbee_device) {
    return this->base_zigbee_device->GetIdentifyInProgress();
  }
  return false;
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

void ZigbeeClass::setFirmwareVersion(const char* version)
{
  if (version == nullptr) {
    return;
  }

  uint8_t zcl_string[17];
  uint8_t len = strlen(version);
  if (len > 16) len = 16;
  zcl_string[0] = len;
  memcpy(&zcl_string[1], version, len);
  for (uint8_t endpoint_id = 1; endpoint_id <= kTotalDynamicEndpoints; endpoint_id++) {
    sl_zigbee_af_write_server_attribute(endpoint_id,
                                        ZCL_BASIC_CLUSTER_ID,
                                        ZCL_SW_BUILD_ID_ATTRIBUTE_ID,
                                        zcl_string,
                                        ZCL_CHAR_STRING_ATTRIBUTE_TYPE);
  }
}

void ZigbeeClass::setFirmwareVersion(uint32_t file_version)
{
  uint8_t application_version = (file_version <= 0xFF) ? file_version : (file_version >> 24);
  for (uint8_t endpoint_id = 1; endpoint_id <= kTotalDynamicEndpoints; endpoint_id++) {
    sl_zigbee_af_write_server_attribute(endpoint_id,
                                        ZCL_BASIC_CLUSTER_ID,
                                        ZCL_APPLICATION_VERSION_ATTRIBUTE_ID,
                                        &application_version,
                                        ZCL_INT8U_ATTRIBUTE_TYPE);
  }

  for (uint8_t endpoint_id = 1; endpoint_id <= kTotalDynamicEndpoints; endpoint_id++) {
    sl_zigbee_af_write_client_attribute(endpoint_id,
                                        ZCL_OTA_BOOTLOAD_CLUSTER_ID,
                                        ZCL_CURRENT_FILE_VERSION_ATTRIBUTE_ID,
                                        reinterpret_cast<uint8_t*>(&file_version),
                                        ZCL_INT32U_ATTRIBUTE_TYPE);
  }
}

void ZigbeeClass::begin()
{
  if (this->started) {
    return;
  }
  this->started = true;
  initNetworkSteeringRetryEvent();

  for (uint8_t i = 0; i < kTotalDynamicEndpoints; i++) {
    sl_zigbee_af_endpoint_enable_disable(i + 1, false);
  }

  if (!this->isJoinedToNetwork()) {
    sl_zigbee_af_network_steering_start();
  }
}

uint32_t ZigbeeClass::channelToMask(uint8_t channel)
{
  if (channel < kMinPairingChannel || channel > kMaxPairingChannel) {
    return 0;
  }
  return 1UL << channel;
}

bool ZigbeeClass::isValidPairingChannelMask(uint32_t channel_mask)
{
  return (channel_mask & kAllPairingChannelsMask) != 0;
}

uint32_t ZigbeeClass::sanitizePairingChannelMask(uint32_t channel_mask)
{
  return channel_mask & kAllPairingChannelsMask;
}

bool ZigbeeClass::setPairingChannel(uint8_t channel)
{
  uint32_t channel_mask = channelToMask(channel);
  if (channel_mask == 0) {
    return false;
  }
  return this->setPairingChannelMask(channel_mask);
}

bool ZigbeeClass::setPairingChannelMask(uint32_t primary_channel_mask, uint32_t secondary_channel_mask)
{
  primary_channel_mask = sanitizePairingChannelMask(primary_channel_mask);
  secondary_channel_mask = sanitizePairingChannelMask(secondary_channel_mask);
  if (!isValidPairingChannelMask(primary_channel_mask) && !isValidPairingChannelMask(secondary_channel_mask)) {
    return false;
  }

  sli_zigbee_af_network_steering_set_channel_mask(primary_channel_mask, false);
  sli_zigbee_af_network_steering_set_channel_mask(secondary_channel_mask, true);

  if (this->started && !this->isJoinedToNetwork()) {
    sl_zigbee_af_network_steering_stop();
    scheduleNetworkSteeringRetry();
  }
  return true;
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
  this->leaveNetwork();
  sl_zigbee_token_factory_reset(false, false);
  nvm3_eraseAll(nvm3_defaultHandle);
  NVIC_SystemReset();
}

uint8_t ZigbeeClass::allocateEndpoint(ZigbeeEndpointType type)
{
  uint8_t start = type * kEndpointsPerType;
  for (uint8_t i = start; i < start + kEndpointsPerType; i++) {
    if (!this->endpoint_allocated[i]) {
      this->endpoint_allocated[i] = true;
      uint8_t ep_id = i + 1;
      sl_zigbee_af_endpoint_enable_disable(ep_id, true);
      return ep_id;
    }
  }
  return 0;
}

void ZigbeeClass::freeEndpoint(uint8_t endpoint_id)
{
  uint8_t index = endpoint_id - 1;
  if (index < kTotalDynamicEndpoints && this->endpoint_allocated[index]) {
    this->endpoint_allocated[index] = false;
    sl_zigbee_af_endpoint_enable_disable(endpoint_id, false);
  }
}
