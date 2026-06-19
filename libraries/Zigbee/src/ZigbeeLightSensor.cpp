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

#include "ZigbeeLightSensor.h"

#include <math.h>

ZigbeeLightSensor::ZigbeeLightSensor() :
  sensor_device(nullptr),
  initialized(false)
{
}

ZigbeeLightSensor::~ZigbeeLightSensor()
{
  end();
}

bool ZigbeeLightSensor::begin()
{
  uint8_t ep = Zigbee.allocateEndpoint(ZIGBEE_LIGHT_SENSOR);
  if (ep == 0) {
    return false;
  }
  return begin(ep);
}

bool ZigbeeLightSensor::begin(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->sensor_device = new DeviceLightSensor("Zigbee Light Sensor", endpoint_id);
  if (!this->sensor_device) {
    return false;
  }

  this->base_zigbee_device = this->sensor_device;

  if (!zigbee_endpoint_register(this->sensor_device)) {
    delete this->sensor_device;
    this->sensor_device = nullptr;
    this->base_zigbee_device = nullptr;
    return false;
  }

  this->sensor_device->SetOnline(true);
  this->initialized = true;
  return true;
}

void ZigbeeLightSensor::end()
{
  if (!this->initialized) {
    return;
  }
  Zigbee.freeEndpoint(this->sensor_device->GetEndpointId());
  zigbee_endpoint_unregister(this->sensor_device);
  delete this->sensor_device;
  this->sensor_device = nullptr;
  this->base_zigbee_device = nullptr;
  this->initialized = false;
}

void ZigbeeLightSensor::set_measured_value_raw(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMeasuredValue(value);
  }
}

void ZigbeeLightSensor::set_measured_value_lux(float lux)
{
  set_measured_value_raw(lux_to_measured_value(lux));
}

uint16_t ZigbeeLightSensor::get_measured_value_raw()
{
  if (!this->sensor_device) {
    return 0;
  }
  return this->sensor_device->GetMeasuredValue();
}

float ZigbeeLightSensor::get_measured_value_lux()
{
  return measured_value_to_lux(get_measured_value_raw());
}

void ZigbeeLightSensor::set_min_value_raw(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMinMeasuredValue(value);
  }
}

void ZigbeeLightSensor::set_min_value_lux(float lux)
{
  set_min_value_raw(lux_to_measured_value(lux));
}

void ZigbeeLightSensor::set_max_value_raw(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMaxMeasuredValue(value);
  }
}

void ZigbeeLightSensor::set_max_value_lux(float lux)
{
  set_max_value_raw(lux_to_measured_value(lux));
}

void ZigbeeLightSensor::set_light_sensor_type(LightSensorType type)
{
  if (this->sensor_device) {
    this->sensor_device->SetLightSensorType((uint8_t)type);
  }
}

bool ZigbeeLightSensor::send_attribute_report()
{
  if (!this->sensor_device) {
    return false;
  }
  return this->sensor_device->SendAttributeReport();
}

bool ZigbeeLightSensor::get_attribute_report_sent()
{
  if (!this->sensor_device) {
    return false;
  }
  return this->sensor_device->GetAttributeReportSent();
}

bool ZigbeeLightSensor::set_reporting_interval(uint16_t min_interval_s, uint16_t max_interval_s)
{
  if (!this->sensor_device) {
    return false;
  }
  return this->sensor_device->SetReportingInterval(min_interval_s, max_interval_s);
}

ZigbeeLightSensor::operator float()
{
  return get_measured_value_lux();
}

void ZigbeeLightSensor::operator=(float lux)
{
  set_measured_value_lux(lux);
}

uint16_t ZigbeeLightSensor::lux_to_measured_value(float lux)
{
  if (!(lux >= 1.0f)) {
    return 0;
  }

  float value = 10000.0f * log10f(lux) + 1.0f;
  if (value < 1.0f) {
    return 1;
  }
  if (value > 65534.0f) {
    return 0xFFFE;
  }
  return (uint16_t)(value + 0.5f);
}

float ZigbeeLightSensor::measured_value_to_lux(uint16_t value)
{
  if (value == 0 || value == 0xFFFF) {
    return 0.0f;
  }
  return powf(10.0f, ((float)value - 1.0f) / 10000.0f);
}
