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
#include "ZigbeeEndpoint.h"

extern "C" {
#include "af.h"
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

  DeviceHumiditySensor* sensor = static_cast<DeviceHumiditySensor*>(device);
  sensor->HandleAttributeReportSent(status);
}

} // namespace

DeviceHumiditySensor::DeviceHumiditySensor(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id),
  measured_value(0),
  attribute_report_pending(false),
  attribute_report_completed(false),
  attribute_report_status(SL_STATUS_FAIL)
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

bool DeviceHumiditySensor::SendAttributeReport()
{
  uint8_t report_data[5];
  report_data[0] = static_cast<uint8_t>(ZCL_RELATIVE_HUMIDITY_MEASURED_VALUE_ATTRIBUTE_ID & 0xFF);
  report_data[1] = static_cast<uint8_t>((ZCL_RELATIVE_HUMIDITY_MEASURED_VALUE_ATTRIBUTE_ID >> 8) & 0xFF);
  report_data[2] = ZCL_INT16U_ATTRIBUTE_TYPE;
  report_data[3] = static_cast<uint8_t>(this->measured_value & 0xFF);
  report_data[4] = static_cast<uint8_t>((this->measured_value >> 8) & 0xFF);

  return this->SendAttributeReportWithCallback(report_data, sizeof(report_data));
}

bool DeviceHumiditySensor::GetAttributeReportSent()
{
  return this->attribute_report_completed && (this->attribute_report_status == SL_STATUS_OK);
}

void DeviceHumiditySensor::HandleAttributeReportSent(uint32_t status)
{
  this->attribute_report_status = status;
  this->attribute_report_completed = true;
  this->attribute_report_pending = false;
}

bool DeviceHumiditySensor::SendAttributeReportWithCallback(uint8_t* report_data, uint8_t report_data_length)
{
  if (this->attribute_report_pending) {
    return false;
  }

  this->attribute_report_pending = true;
  this->attribute_report_completed = false;
  this->attribute_report_status = SL_STATUS_FAIL;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);
  sl_zigbee_af_fill_command_global_server_to_client_report_attributes(ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID,
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
  sl_zigbee_af_fill_command_global_server_to_client_report_attributes(ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID,
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
