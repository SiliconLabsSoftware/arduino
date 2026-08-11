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

#include "ZigbeePowerSource.h"

ZigbeePowerSource::ZigbeePowerSource() :
  power_source_device(nullptr),
  initialized(false)
{
}

ZigbeePowerSource::~ZigbeePowerSource()
{
  end();
}

bool ZigbeePowerSource::begin()
{
  if (this->initialized) {
    return false;
  }

  uint8_t ep = Zigbee.allocateEndpoint(ZIGBEE_POWER_SOURCE);
  if (ep == 0) {
    return false;
  }
  if (!start_on_endpoint(ep)) {
    Zigbee.freeEndpoint(ep);
    return false;
  }
  return true;
}

bool ZigbeePowerSource::start_on_endpoint(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->power_source_device = new DevicePowerSource("Zigbee Power Source", endpoint_id);
  if (!this->power_source_device) {
    return false;
  }

  this->base_zigbee_device = this->power_source_device;

  if (!zigbee_endpoint_register(this->power_source_device)) {
    delete this->power_source_device;
    this->power_source_device = nullptr;
    this->base_zigbee_device = nullptr;
    return false;
  }

  this->power_source_device->SetOnline(true);
  this->initialized = true;
  this->set_battery_percent(100u);
  return true;
}

void ZigbeePowerSource::end()
{
  if (!this->initialized) {
    return;
  }
  Zigbee.freeEndpoint(this->power_source_device->GetEndpointId());
  zigbee_endpoint_unregister(this->power_source_device);
  delete this->power_source_device;
  this->power_source_device = nullptr;
  this->base_zigbee_device = nullptr;
  this->initialized = false;
}

void ZigbeePowerSource::set_battery_percent(uint8_t value)
{
  if (!this->power_source_device) {
    return;
  }
  if (value > 100u) {
    value = 100u;
  }
  this->power_source_device->SetBatteryPercentageRemaining(static_cast<uint8_t>(value * 2u));
}

uint8_t ZigbeePowerSource::get_battery_percent()
{
  if (!this->power_source_device) {
    return 0;
  }
  return static_cast<uint8_t>(this->power_source_device->GetBatteryPercentageRemaining() / 2u);
}

bool ZigbeePowerSource::send_attribute_report()
{
  if (!this->power_source_device) {
    return false;
  }
  return this->power_source_device->SendAttributeReport();
}

bool ZigbeePowerSource::get_attribute_report_sent()
{
  if (!this->power_source_device) {
    return false;
  }
  return this->power_source_device->GetAttributeReportSent();
}

bool ZigbeePowerSource::set_reporting_interval(uint16_t min_interval_s, uint16_t max_interval_s)
{
  if (!this->power_source_device) {
    return false;
  }
  return this->power_source_device->SetReportingInterval(min_interval_s, max_interval_s);
}

ZigbeePowerSource::operator uint8_t()
{
  return this->get_battery_percent();
}

void ZigbeePowerSource::operator=(uint8_t value)
{
  this->set_battery_percent(value);
}
