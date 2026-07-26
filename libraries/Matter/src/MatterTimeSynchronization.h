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

#ifndef MATTER_TIME_SYNCHRONIZATION_H
#define MATTER_TIME_SYNCHRONIZATION_H

#include "Matter.h"
#include <platform/CHIPDeviceLayer.h>
#include <system/SystemClock.h>

class MatterTimeSynchronization {
public:
  MatterTimeSynchronization();
  ~MatterTimeSynchronization();
  bool begin();
  void end();

  bool has_time();
  uint32_t get_unix_time();
  uint64_t get_unix_time_millis();

  bool has_timezone();
  int32_t get_timezone_offset_seconds();
  int32_t get_dst_offset_seconds();
  int32_t get_local_offset_seconds();
  uint32_t get_local_unix_time();
  uint64_t get_local_unix_time_millis();

  bool request_time();

  void set_time_update_callback(void (*cb)(void));
  void set_timezone_update_callback(void (*cb)(void));

  operator uint32_t();

  void notify_time_update();
  void notify_timezone_update();

private:
  bool initialized;
  bool time_available;
  bool timezone_available;
  uint32_t last_request_time_ms;
  void (*time_update_callback)(void);
  void (*timezone_update_callback)(void);
};

#endif // MATTER_TIME_SYNCHRONIZATION_H
