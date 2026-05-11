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

#include "ZigbeeSwitch.h"

ZigbeeSwitch::ZigbeeSwitch() :
  switch_device(nullptr),
  initialized(false)
{
}

ZigbeeSwitch::~ZigbeeSwitch()
{
  end();
}

bool ZigbeeSwitch::begin()
{
  uint8_t ep = Zigbee.allocateEndpoint(ZIGBEE_ON_OFF_SWITCH);
  if (ep == 0) {
    return false;
  }
  return begin(ep);
}

bool ZigbeeSwitch::begin(uint8_t endpoint_id)
{
  if (this->initialized) {
    return false;
  }

  this->switch_device = new DeviceSwitch("Zigbee Switch", endpoint_id);
  if (!this->switch_device) {
    return false;
  }

  this->base_zigbee_device = this->switch_device;

  if (!zigbee_endpoint_register(this->switch_device)) {
    delete this->switch_device;
    this->switch_device = nullptr;
    this->base_zigbee_device = nullptr;
    return false;
  }

  this->switch_device->SetOnline(true);
  this->initialized = true;
  return true;
}

void ZigbeeSwitch::end()
{
  if (!this->initialized) {
    return;
  }
  Zigbee.freeEndpoint(this->switch_device->GetEndpointId());
  zigbee_endpoint_unregister(this->switch_device);
  delete this->switch_device;
  this->switch_device = nullptr;
  this->base_zigbee_device = nullptr;
  this->initialized = false;
}

void ZigbeeSwitch::on()
{
  if (this->switch_device) {
    this->switch_device->SendOn();
  }
}

void ZigbeeSwitch::off()
{
  if (this->switch_device) {
    this->switch_device->SendOff();
  }
}

void ZigbeeSwitch::toggle()
{
  if (this->switch_device) {
    this->switch_device->SendToggle();
  }
}

void ZigbeeSwitch::dimUp(uint8_t rate_percent)
{
  if (this->switch_device) {
    this->switch_device->SendDimUp(rate_percent);
  }
}

void ZigbeeSwitch::dimDown(uint8_t rate_percent)
{
  if (this->switch_device) {
    this->switch_device->SendDimDown(rate_percent);
  }
}

void ZigbeeSwitch::stopDimming()
{
  if (this->switch_device) {
    this->switch_device->SendStopDimming();
  }
}

void ZigbeeSwitch::moveToLevel(uint8_t level, uint32_t transition_time_ms)
{
  if (this->switch_device) {
    this->switch_device->SendMoveToLevel(level, transition_time_ms);
  }
}

void ZigbeeSwitch::moveToPercent(uint8_t percent, uint32_t transition_time_ms)
{
  if (this->switch_device) {
    this->switch_device->SendMoveToPercent(percent, transition_time_ms);
  }
}
