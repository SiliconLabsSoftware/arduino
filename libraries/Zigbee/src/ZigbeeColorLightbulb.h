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

#ifndef ZIGBEE_COLOR_LIGHTBULB_H
#define ZIGBEE_COLOR_LIGHTBULB_H

#include "ZigbeeDimmableLightbulb.h"
#include "devices/DeviceColorLight.h"

class ZigbeeColorLightbulb : public ZigbeeDimmableLightbulb {
public:
  ZigbeeColorLightbulb();
  bool begin() override;
  using ZigbeeDimmableLightbulb::begin;

  uint8_t get_hue();
  uint8_t get_saturation();
  uint8_t get_saturation_percent();
  uint16_t get_true_hue();
  void set_hue(uint8_t hue);
  void set_saturation(uint8_t saturation);
  void set_saturation_percent(uint8_t saturation);
  void set_true_hue(uint16_t true_hue);
  void set_color(uint8_t hue, uint8_t saturation);

  void get_rgb(uint8_t* r, uint8_t* g, uint8_t* b);
  void get_rgb_raw(uint8_t* r, uint8_t* g, uint8_t* b);
  void set_rgb(uint8_t r, uint8_t g, uint8_t b);
  void boost_saturation(uint8_t amount);

protected:
  DeviceOnOffLight* CreateLightDevice(const char* device_name, uint8_t endpoint_id) override;
  const char* GetDeviceName() const override;

private:
  static uint8_t color_value_to_rgb_value(uint8_t value);
  static uint8_t rgb_value_to_color_value(uint8_t value);
  static void hsv_to_rgb(uint8_t hue, uint8_t saturation, uint8_t value, uint8_t* r, uint8_t* g, uint8_t* b);
  static void rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b, uint8_t* hue, uint8_t* saturation, uint8_t* value);
  static uint8_t max3(uint8_t a, uint8_t b, uint8_t c);
  static uint8_t min3(uint8_t a, uint8_t b, uint8_t c);

  DeviceColorLight* get_color_light_device();
  uint8_t get_boosted_saturation();

  uint8_t saturation_boost;
};

#endif // ZIGBEE_COLOR_LIGHTBULB_H
