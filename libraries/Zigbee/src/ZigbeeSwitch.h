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

#ifndef ZIGBEE_SWITCH_H
#define ZIGBEE_SWITCH_H

#include "Zigbee.h"
#include "devices/DeviceSwitch.h"

class ZigbeeSwitch : public ArduinoZigbeeAppliance {
public:
  ZigbeeSwitch();
  ~ZigbeeSwitch();
  bool begin() override;
  void end() override;

  void on();
  void off();
  void toggle();
  void dim_up(uint8_t rate_percent = 50);
  void dim_down(uint8_t rate_percent = 50);
  void stop_dimming();
  void move_to_level(uint8_t level, uint32_t transition_time_ms = 0);
  void move_to_percent(uint8_t percent, uint32_t transition_time_ms = 0);

private:
  bool start_on_endpoint(uint8_t endpoint_id);

  DeviceSwitch* switch_device;
  bool initialized;
};

#endif // ZIGBEE_SWITCH_H
