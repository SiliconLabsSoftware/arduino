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

#include "ZigbeeContact.h"

ZigbeeContact::ZigbeeContact() :
  sensor_device(nullptr),
  initialized(false)
{
}

ZigbeeContact::~ZigbeeContact()
{
  end();
}

bool ZigbeeContact::begin()
{
  uint8_t ep = Zigbee.allocateEndpoint(ZIGBEE_CONTACT_SENSOR);
  if (ep == 0) {
    return false;
  }
  if (!start_on_endpoint(ep)) {
    Zigbee.freeEndpoint(ep);
    return false;
  }
  return true;
}

bool ZigbeeContact::start_on_endpoint(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->sensor_device = new DeviceContactSensor("Zigbee Contact Sensor", endpoint_id);
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

  this->sensor_device->RestoreEnrollmentState();
  this->sensor_device->SetOnline(true);
  this->initialized = true;
  return true;
}

void ZigbeeContact::end()
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

// Sets the contact state - "false" means contact detected (closed), "true" means contact lost (open)
void ZigbeeContact::set_state(bool state)
{
  if (this->sensor_device) {
    this->sensor_device->SetStateValue(state);
  }
}

// Returns false if contact is detected (closed), true if contact is lost (open)
bool ZigbeeContact::get_state()
{
  if (!this->sensor_device) {
    return false;
  }
  return this->sensor_device->GetStateValue();
}

bool ZigbeeContact::is_open()
{
  return this->get_state();
}

void ZigbeeContact::set_open()
{
  this->set_state(true);
}

bool ZigbeeContact::is_closed()
{
  return !this->get_state();
}

void ZigbeeContact::set_closed()
{
  this->set_state(false);
}

ZigbeeContact::operator bool()
{
  return this->get_state();
}

void ZigbeeContact::operator=(bool state)
{
  this->set_state(state);
}
