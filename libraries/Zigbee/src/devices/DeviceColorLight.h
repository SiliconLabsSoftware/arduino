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

#ifndef DEVICE_COLOR_LIGHT_H
#define DEVICE_COLOR_LIGHT_H

#include "DeviceDimmableLight.h"

class DeviceColorLight : public DeviceDimmableLight {
public:
  DeviceColorLight(const char* device_name, uint8_t endpoint_id);

  uint8_t GetHue();
  void SetHue(uint8_t hue);
  uint8_t GetSaturation();
  void SetSaturation(uint8_t saturation);
  void SetColor(uint8_t hue, uint8_t saturation);

  uint16_t GetTrueHue();
  void SetTrueHue(uint16_t true_hue);
  uint8_t GetSaturationPercent();
  void SetSaturationPercent(uint8_t percent);
  uint16_t GetCurrentX();
  uint16_t GetCurrentY();
  void SetXy(uint16_t x, uint16_t y);

  void HandleAttributeChange(uint16_t cluster_id,
                             uint16_t attribute_id,
                             uint8_t size,
                             uint8_t* value) override;

private:
  enum {
    COLOR_CONTROL_MAX_VALUE = 254,
    COLOR_PERCENT_MAX = 100,
    COLOR_TRUE_HUE_MAX = 360,
    COLOR_MODE_HUE_SATURATION = 0,
    COLOR_MODE_CURRENT_X_Y = 1,
    COLOR_CAPABILITY_HUE_SATURATION = 0x0001,
    COLOR_CAPABILITY_CURRENT_X_Y = 0x0008,
    COLOR_CAPABILITIES = COLOR_CAPABILITY_HUE_SATURATION | COLOR_CAPABILITY_CURRENT_X_Y
  };

  static uint8_t NormalizeColorValue(uint8_t value);
  static uint16_t NormalizeXyValue(uint16_t value);
  static uint8_t PercentToColorValue(uint8_t percent);
  static uint8_t ColorValueToPercent(uint8_t value);
  static uint8_t TrueHueToHue(uint16_t true_hue);
  static uint16_t HueToTrueHue(uint8_t hue);
  static uint16_t ReadInt16u(const uint8_t* value);
  static uint8_t EnhancedHueToHue(uint16_t enhanced_hue);
  static uint16_t HueToEnhancedHue(uint8_t hue);
  static uint16_t FloatToXyValue(float value);
  static float XyValueToFloat(uint16_t value);
  static void HsvToRgbFloat(uint8_t hue, uint8_t saturation, float* red, float* green, float* blue);
  static void RgbFloatToHsv(float red, float green, float blue, uint8_t* hue, uint8_t* saturation);
  static void HsvToXy(uint8_t hue, uint8_t saturation, uint16_t* x, uint16_t* y);
  static void XyToHsv(uint16_t x, uint16_t y, uint8_t* hue, uint8_t* saturation);

  void WriteColorModeAttributes();
  void WriteHueAttributes();
  void WriteSaturationAttribute();
  void WriteXyAttributes();

  uint8_t hue;
  uint8_t saturation;
  uint16_t current_x;
  uint16_t current_y;
  uint8_t color_mode;
};

#endif // DEVICE_COLOR_LIGHT_H
