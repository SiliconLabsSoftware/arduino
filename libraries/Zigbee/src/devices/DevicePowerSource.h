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

#ifndef DEVICE_POWER_SOURCE_H
#define DEVICE_POWER_SOURCE_H

#include "ZigbeeDevice.h"

class DevicePowerSource : public ZigbeeDevice {
public:
  DevicePowerSource(const char* device_name, uint8_t endpoint_id);

  uint8_t GetBatteryPercentageRemaining();
  void SetBatteryPercentageRemaining(uint8_t value);
  bool SendAttributeReport();
  bool GetAttributeReportSent();
  bool SetReportingInterval(uint16_t min_interval_s, uint16_t max_interval_s);
  void HandleAttributeReportSent(uint32_t status);

  void HandleAttributeChange(uint16_t cluster_id,
                             uint16_t attribute_id,
                             uint8_t size,
                             uint8_t* value) override;

private:
  bool SendAttributeReportWithCallback(uint8_t* report_data, uint8_t report_data_length);
  uint8_t battery_percentage_remaining;
  bool attribute_report_pending;
  bool attribute_report_completed;
  uint32_t attribute_report_status;
};

#endif // DEVICE_POWER_SOURCE_H
