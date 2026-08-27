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

#ifndef ZIGBEE_LIGHTBULB_H
#define ZIGBEE_LIGHTBULB_H

#include "Zigbee.h"
#include "devices/DeviceOnOffLight.h"

class ZigbeeLightbulb : public ArduinoZigbeeAppliance {
public:
  ZigbeeLightbulb();
  ~ZigbeeLightbulb() override;
  bool begin() override;
  void end() override;
  bool start_find_and_bind();

  void set_onoff(bool value);
  bool get_onoff();
  void toggle();

  operator bool();
  void operator=(bool state);

protected:
  bool beginEndpointType(ZigbeeEndpointType type);
  virtual DeviceOnOffLight* CreateLightDevice(const char* device_name, uint8_t endpoint_id);
  virtual const char* GetDeviceName() const;

  DeviceOnOffLight* light_device;
  bool initialized;

private:
  bool start_on_endpoint(uint8_t endpoint_id);
};

#endif // ZIGBEE_LIGHTBULB_H
