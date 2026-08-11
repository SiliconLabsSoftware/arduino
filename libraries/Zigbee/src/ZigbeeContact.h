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

#ifndef ZIGBEE_CONTACT_H
#define ZIGBEE_CONTACT_H

#include "Zigbee.h"
#include "devices/DeviceContactSensor.h"

class ZigbeeContact : public ArduinoZigbeeAppliance {
public:
  ZigbeeContact();
  ~ZigbeeContact();
  bool begin() override;
  void end() override;

  void set_state(bool state);
  bool get_state();

  bool is_open();
  void set_open();
  bool is_closed();
  void set_closed();

  operator bool();
  void operator=(bool state);

private:
  bool start_on_endpoint(uint8_t endpoint_id);

  DeviceContactSensor* sensor_device;
  bool initialized;
};

#endif // ZIGBEE_CONTACT_H
