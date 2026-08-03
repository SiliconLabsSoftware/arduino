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

#ifndef ZIGBEE_TIME_CLIENT_H
#define ZIGBEE_TIME_CLIENT_H

#include "Zigbee.h"
#include "devices/DeviceTimeClient.h"

class ZigbeeTimeClient : public ArduinoZigbeeAppliance {
public:
  ZigbeeTimeClient();
  ~ZigbeeTimeClient() override;
  bool begin() override;
  void end() override;

  bool request_time(uint8_t coordinator_endpoint_id = 1);
  bool has_time();
  uint32_t get_zigbee_time();
  uint32_t get_unix_time();
  uint32_t get_local_unix_time();
  bool has_timezone();
  int32_t get_timezone();
  uint8_t get_time_status();
  void set_time_update_callback(void (*cb)(void));

private:
  DeviceTimeClient* time_client_device;
  bool initialized;
  void (*time_update_callback)(void);
};

#endif // ZIGBEE_TIME_CLIENT_H
