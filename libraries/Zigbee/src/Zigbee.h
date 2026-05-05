/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2025 Silicon Laboratories Inc. www.silabs.com
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

#ifndef ZIGBEE_H
#define ZIGBEE_H

#ifndef ARDUINO_ZIGBEE
  #error "Selected board/variant is not Zigbee compatible - please select the Zigbee protocol stack if your board supports it!"
#endif

#include "Arduino.h"
#include "devices/ZigbeeDevice.h"
#include "ZigbeeEndpoint.h"

class ArduinoZigbeeAppliance {
public:
  ArduinoZigbeeAppliance();
  virtual ~ArduinoZigbeeAppliance();
  virtual bool begin() = 0;
  virtual void end() = 0;
  bool is_online();
  void set_device_name(const char* device_name);
  void set_device_change_callback(void (*cb)(void));

protected:
  ZigbeeDevice* base_zigbee_device;
};

class ZigbeeClass {
public:
  void begin();

  bool isJoinedToNetwork();
  uint8_t getChannel();
  uint16_t getPanId();
  uint16_t getNodeId();

  void leaveNetwork();
  void factoryReset();

private:
  bool started;
};

extern ZigbeeClass Zigbee;

#endif // ZIGBEE_H
