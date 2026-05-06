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

#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice(const char* device_name, uint8_t endpoint_id) :
  endpoint_id(endpoint_id),
  online(false),
  identify_in_progress(false),
  identify_time(0),
  device_change_callback(nullptr)
{
  strncpy(this->device_name, device_name, kMaxNameSize);
  this->device_name[kMaxNameSize] = '\0';
}

ZigbeeDevice::~ZigbeeDevice()
{
}

bool ZigbeeDevice::IsOnline()
{
  return this->online;
}

void ZigbeeDevice::SetOnline(bool online)
{
  this->online = online;
}

uint8_t ZigbeeDevice::GetEndpointId()
{
  return this->endpoint_id;
}

const char* ZigbeeDevice::GetName()
{
  return this->device_name;
}

bool ZigbeeDevice::GetIdentifyInProgress()
{
  return this->identify_in_progress;
}

void ZigbeeDevice::HandleIdentifyStart(uint16_t identify_time)
{
  if (identify_time == 0) {
    return;
  }

  this->identify_time = identify_time;
  if (!this->identify_in_progress) {
    this->identify_in_progress = true;
    this->CallDeviceChangeCallback();
  }
}

void ZigbeeDevice::HandleIdentifyStop()
{
  this->identify_time = 0;
  if (this->identify_in_progress) {
    this->identify_in_progress = false;
    this->CallDeviceChangeCallback();
  }
}

void ZigbeeDevice::SetDeviceChangeCallback(void (*cb)(void))
{
  this->device_change_callback = cb;
}

void ZigbeeDevice::CallDeviceChangeCallback()
{
  if (this->device_change_callback) {
    this->device_change_callback();
  }
}
