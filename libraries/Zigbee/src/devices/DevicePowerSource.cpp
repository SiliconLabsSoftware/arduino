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

#include "DevicePowerSource.h"
#include "ZigbeeEndpoint.h"
#include "../ZigbeeAfLock.h"

extern "C" {
#include "af.h"
#include "af-storage.h"
#include "app/framework/plugin/reporting/reporting.h"
}

namespace {
void AttributeReportMessageSentCallback(sl_zigbee_outgoing_message_type_t type,
                                        uint16_t index_or_destination,
                                        sl_zigbee_aps_frame_t* aps_frame,
                                        uint16_t msg_len,
                                        uint8_t* message,
                                        sl_status_t status)
{
  (void)type;
  (void)index_or_destination;
  (void)msg_len;
  (void)message;

  if (aps_frame == nullptr) {
    return;
  }

  ZigbeeDevice* device = zigbee_endpoint_get_device(aps_frame->sourceEndpoint);
  if (device == nullptr) {
    return;
  }

  DevicePowerSource* power_source = static_cast<DevicePowerSource*>(device);
  power_source->HandleAttributeReportSent(status);
}
} // namespace

DevicePowerSource::DevicePowerSource(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id),
  battery_percentage_remaining(0),
  attribute_report_pending(false),
  attribute_report_completed(false),
  attribute_report_status(SL_STATUS_FAIL)
{
  uint8_t power_source = SL_ZIGBEE_ZCL_POWER_SOURCE_BATTERY;
  ZigbeeAfLock lock;
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_BASIC_CLUSTER_ID,
                                      ZCL_POWER_SOURCE_ATTRIBUTE_ID,
                                      &power_source,
                                      ZCL_ENUM8_ATTRIBUTE_TYPE);
}

uint8_t DevicePowerSource::GetBatteryPercentageRemaining()
{
  return this->battery_percentage_remaining;
}

bool DevicePowerSource::SendAttributeReport()
{
  uint8_t report_data[4];
  report_data[0] = static_cast<uint8_t>(ZCL_BATTERY_PERCENTAGE_REMAINING_ATTRIBUTE_ID & 0xFF);
  report_data[1] = static_cast<uint8_t>((ZCL_BATTERY_PERCENTAGE_REMAINING_ATTRIBUTE_ID >> 8) & 0xFF);
  report_data[2] = ZCL_INT8U_ATTRIBUTE_TYPE;
  report_data[3] = this->battery_percentage_remaining;

  return this->SendAttributeReportWithCallback(report_data, sizeof(report_data));
}

bool DevicePowerSource::GetAttributeReportSent()
{
  return this->attribute_report_completed && (this->attribute_report_status == SL_STATUS_OK);
}

bool DevicePowerSource::SetReportingInterval(uint16_t min_interval_s, uint16_t max_interval_s)
{
  sl_zigbee_af_plugin_reporting_entry_t entry = {};
  entry.direction = SL_ZIGBEE_ZCL_REPORTING_DIRECTION_REPORTED;
  entry.endpoint = this->endpoint_id;
  entry.clusterId = ZCL_POWER_CONFIG_CLUSTER_ID;
  entry.attributeId = ZCL_BATTERY_PERCENTAGE_REMAINING_ATTRIBUTE_ID;
  entry.mask = CLUSTER_MASK_SERVER;
  entry.manufacturerCode = 0;
  entry.data.reported.minInterval = min_interval_s;
  entry.data.reported.maxInterval = max_interval_s;
  entry.data.reported.reportableChange = 0;

  ZigbeeAfLock lock;
  return sl_zigbee_af_reporting_configure_reported_attribute(&entry) == SL_ZIGBEE_ZCL_STATUS_SUCCESS;
}

void DevicePowerSource::HandleAttributeReportSent(uint32_t status)
{
  this->attribute_report_status = status;
  this->attribute_report_completed = true;
  this->attribute_report_pending = false;
}

void DevicePowerSource::SetBatteryPercentageRemaining(uint8_t value)
{
  this->battery_percentage_remaining = value;
  {
    ZigbeeAfLock lock;
    sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                        ZCL_POWER_CONFIG_CLUSTER_ID,
                                        ZCL_BATTERY_PERCENTAGE_REMAINING_ATTRIBUTE_ID,
                                        &value,
                                        ZCL_INT8U_ATTRIBUTE_TYPE);
  }
  CallDeviceChangeCallback();
}

void DevicePowerSource::HandleAttributeChange(uint16_t cluster_id,
                                              uint16_t attribute_id,
                                              uint8_t size,
                                              uint8_t* value)
{
  (void)size;
  if (cluster_id == ZCL_POWER_CONFIG_CLUSTER_ID && attribute_id == ZCL_BATTERY_PERCENTAGE_REMAINING_ATTRIBUTE_ID) {
    uint8_t new_value = *value;
    if (this->battery_percentage_remaining != new_value) {
      this->battery_percentage_remaining = new_value;
      CallDeviceChangeCallback();
    }
  }
}

bool DevicePowerSource::SendAttributeReportWithCallback(uint8_t* report_data, uint8_t report_data_length)
{
  if (this->attribute_report_pending) {
    return false;
  }

  this->attribute_report_pending = true;
  this->attribute_report_completed = false;
  this->attribute_report_status = SL_STATUS_FAIL;

  ZigbeeAfLock lock;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_global_server_to_client_report_attributes(ZCL_POWER_CONFIG_CLUSTER_ID,
                                                                      report_data,
                                                                      report_data_length);

  sl_status_t status = sl_zigbee_af_send_command_unicast_to_bindings_with_cb(AttributeReportMessageSentCallback);
  if (status == SL_STATUS_OK) {
    return true;
  }

  this->attribute_report_pending = false;
  this->attribute_report_completed = false;
  this->attribute_report_status = SL_STATUS_FAIL;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_global_server_to_client_report_attributes(ZCL_POWER_CONFIG_CLUSTER_ID,
                                                                      report_data,
                                                                      report_data_length);

  status = sl_zigbee_af_send_command_unicast_with_cb(SL_ZIGBEE_OUTGOING_DIRECT,
                                                     0x0000,
                                                     AttributeReportMessageSentCallback);
  if (status == SL_STATUS_OK) {
    return true;
  }

  this->attribute_report_pending = false;
  this->attribute_report_completed = false;
  this->attribute_report_status = SL_STATUS_FAIL;
  return false;
}
