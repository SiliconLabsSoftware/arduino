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

#ifndef ZIGBEE_LIGHT_SENSOR_H
#define ZIGBEE_LIGHT_SENSOR_H

#include "Zigbee.h"
#include "devices/DeviceLightSensor.h"

class ZigbeeLightSensor : public ArduinoZigbeeAppliance {
public:
  enum LightSensorType : uint8_t {
    LIGHT_SENSOR_TYPE_PHOTODIODE = 0x00,
    LIGHT_SENSOR_TYPE_CMOS = 0x01,
    LIGHT_SENSOR_TYPE_UNKNOWN = 0xFF
  };

  ZigbeeLightSensor();
  ~ZigbeeLightSensor();
  bool begin() override;
  bool begin(uint8_t endpoint_id);
  void end() override;

  void set_measured_value(uint16_t value);
  void set_measured_value_lux(float lux);
  bool send_attribute_report();
  bool get_attribute_report_sent();
  uint16_t get_measured_value();
  float get_measured_value_lux();
  void set_min_value(uint16_t value);
  void set_min_value_lux(float lux);
  void set_max_value(uint16_t value);
  void set_max_value_lux(float lux);
  void set_light_sensor_type(LightSensorType type);

  operator float();
  void operator=(float lux);

private:
  static uint16_t lux_to_measured_value(float lux);
  static float measured_value_to_lux(uint16_t value);

  DeviceLightSensor* sensor_device;
  bool initialized;
};

#endif // ZIGBEE_LIGHT_SENSOR_H
