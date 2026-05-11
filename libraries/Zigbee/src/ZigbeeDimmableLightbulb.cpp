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

#include "ZigbeeDimmableLightbulb.h"

ZigbeeDimmableLightbulb::ZigbeeDimmableLightbulb() :
  ZigbeeLightbulb()
{
}

bool ZigbeeDimmableLightbulb::begin()
{
  return beginEndpointType(ZIGBEE_DIMMABLE_LIGHT);
}

void ZigbeeDimmableLightbulb::set_level(uint8_t level)
{
  DeviceDimmableLight* device = GetDimmableDevice();
  if (device) {
    device->SetLevel(level);
  }
}

uint8_t ZigbeeDimmableLightbulb::get_level()
{
  DeviceDimmableLight* device = GetDimmableDevice();
  if (!device) {
    return 0;
  }
  return device->GetLevel();
}

void ZigbeeDimmableLightbulb::set_brightness(uint8_t percent)
{
  DeviceDimmableLight* device = GetDimmableDevice();
  if (device) {
    device->SetBrightness(percent);
  }
}

uint8_t ZigbeeDimmableLightbulb::get_brightness()
{
  DeviceDimmableLight* device = GetDimmableDevice();
  if (!device) {
    return 0;
  }
  return device->GetBrightness();
}

DeviceOnOffLight* ZigbeeDimmableLightbulb::CreateLightDevice(const char* device_name, uint8_t endpoint_id)
{
  return new DeviceDimmableLight(device_name, endpoint_id);
}

const char* ZigbeeDimmableLightbulb::GetDeviceName() const
{
  return "Zigbee Dimmable Lightbulb";
}

DeviceDimmableLight* ZigbeeDimmableLightbulb::GetDimmableDevice()
{
  return static_cast<DeviceDimmableLight*>(this->light_device);
}
