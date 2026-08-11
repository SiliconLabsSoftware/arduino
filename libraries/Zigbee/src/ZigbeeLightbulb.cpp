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

#include "ZigbeeLightbulb.h"

ZigbeeLightbulb::ZigbeeLightbulb() :
  light_device(nullptr),
  initialized(false)
{
}

ZigbeeLightbulb::~ZigbeeLightbulb()
{
  end();
}

bool ZigbeeLightbulb::begin()
{
  return beginEndpointType(ZIGBEE_ON_OFF_LIGHT);
}

bool ZigbeeLightbulb::beginEndpointType(ZigbeeEndpointType type)
{
  if (this->initialized) {
    return false;
  }

  uint8_t ep = Zigbee.allocateEndpoint(type);
  if (ep == 0) {
    return false;
  }
  if (!start_on_endpoint(ep)) {
    Zigbee.freeEndpoint(ep);
    return false;
  }
  return true;
}

bool ZigbeeLightbulb::start_on_endpoint(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->light_device = CreateLightDevice(GetDeviceName(), endpoint_id);
  if (!this->light_device) {
    return false;
  }

  this->base_zigbee_device = this->light_device;

  if (!zigbee_endpoint_register(this->light_device)) {
    delete this->light_device;
    this->light_device = nullptr;
    this->base_zigbee_device = nullptr;
    return false;
  }

  this->light_device->RestorePersistedState();
  this->light_device->SetOnline(true);
  this->initialized = true;
  return true;
}

void ZigbeeLightbulb::end()
{
  if (!this->initialized) {
    return;
  }
  Zigbee.freeEndpoint(this->light_device->GetEndpointId());
  zigbee_endpoint_unregister(this->light_device);
  delete this->light_device;
  this->light_device = nullptr;
  this->base_zigbee_device = nullptr;
  this->initialized = false;
}

void ZigbeeLightbulb::set_onoff(bool value)
{
  if (!this->light_device) {
    return;
  }
  this->light_device->SetOnOff(value);
}

bool ZigbeeLightbulb::get_onoff()
{
  if (!this->light_device) {
    return false;
  }
  return this->light_device->IsOn();
}

void ZigbeeLightbulb::toggle()
{
  if (!this->light_device) {
    return;
  }
  this->light_device->Toggle();
}

ZigbeeLightbulb::operator bool()
{
  return get_onoff();
}

void ZigbeeLightbulb::operator=(bool state)
{
  set_onoff(state);
}

DeviceOnOffLight* ZigbeeLightbulb::CreateLightDevice(const char* device_name, uint8_t endpoint_id)
{
  return new DeviceOnOffLight(device_name, endpoint_id);
}

const char* ZigbeeLightbulb::GetDeviceName() const
{
  return "Zigbee Lightbulb";
}
