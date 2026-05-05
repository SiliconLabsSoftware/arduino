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

#include "ZigbeeHumiditySensor.h"

ZigbeeHumiditySensor::ZigbeeHumiditySensor() :
  sensor_device(nullptr),
  initialized(false)
{
}

ZigbeeHumiditySensor::~ZigbeeHumiditySensor()
{
  end();
}

bool ZigbeeHumiditySensor::begin()
{
  uint8_t ep = Zigbee.allocateEndpoint(ZIGBEE_HUMIDITY_SENSOR);
  if (ep == 0) {
    return false;
  }
  return begin(ep);
}

bool ZigbeeHumiditySensor::begin(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->sensor_device = new DeviceHumiditySensor("Zigbee Humidity Sensor", endpoint_id);
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

void ZigbeeHumiditySensor::end()
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

void ZigbeeHumiditySensor::set_measured_value(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMeasuredValue(value);
  }
}

void ZigbeeHumiditySensor::set_measured_value_percent(float percent)
{
  set_measured_value((uint16_t)(percent * 100.0f));
}

uint16_t ZigbeeHumiditySensor::get_measured_value()
{
  if (!this->sensor_device) {
    return 0;
  }
  return this->sensor_device->GetMeasuredValue();
}

float ZigbeeHumiditySensor::get_measured_value_percent()
{
  return (float)get_measured_value() / 100.0f;
}

void ZigbeeHumiditySensor::set_min_value(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMinMeasuredValue(value);
  }
}

void ZigbeeHumiditySensor::set_max_value(uint16_t value)
{
  if (this->sensor_device) {
    this->sensor_device->SetMaxMeasuredValue(value);
  }
}

ZigbeeHumiditySensor::operator float()
{
  return get_measured_value_percent();
}

void ZigbeeHumiditySensor::operator=(float percent)
{
  set_measured_value_percent(percent);
}
