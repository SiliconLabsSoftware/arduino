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

#include "DeviceColorLight.h"

extern "C" {
#include "af.h"
}

DeviceColorLight::DeviceColorLight(const char* device_name, uint8_t endpoint_id) :
  DeviceDimmableLight(device_name, endpoint_id),
  hue(0),
  saturation(0),
  current_x(0),
  current_y(0),
  color_mode(COLOR_MODE_HUE_SATURATION)
{
  HsvToXy(this->hue, this->saturation, &this->current_x, &this->current_y);
  WriteColorModeAttributes();
  WriteHueAttributes();
  WriteSaturationAttribute();
  WriteXyAttributes();
}

uint8_t DeviceColorLight::GetHue()
{
  return this->hue;
}

void DeviceColorLight::SetHue(uint8_t hue)
{
  SetColor(hue, this->saturation);
}

uint8_t DeviceColorLight::GetSaturation()
{
  return this->saturation;
}

void DeviceColorLight::SetSaturation(uint8_t saturation)
{
  SetColor(this->hue, saturation);
}

void DeviceColorLight::SetColor(uint8_t hue, uint8_t saturation)
{
  uint8_t normalized_hue = NormalizeColorValue(hue);
  uint8_t normalized_saturation = NormalizeColorValue(saturation);
  uint16_t x;
  uint16_t y;
  HsvToXy(normalized_hue, normalized_saturation, &x, &y);
  if (this->hue == normalized_hue
      && this->saturation == normalized_saturation
      && this->current_x == x
      && this->current_y == y
      && this->color_mode == COLOR_MODE_HUE_SATURATION) {
    return;
  }

  this->hue = normalized_hue;
  this->saturation = normalized_saturation;
  this->current_x = x;
  this->current_y = y;
  this->color_mode = COLOR_MODE_HUE_SATURATION;
  WriteColorModeAttributes();
  WriteHueAttributes();
  WriteSaturationAttribute();
  WriteXyAttributes();
  CallDeviceChangeCallback();
}

uint16_t DeviceColorLight::GetTrueHue()
{
  return HueToTrueHue(this->hue);
}

void DeviceColorLight::SetTrueHue(uint16_t true_hue)
{
  SetHue(TrueHueToHue(true_hue));
}

uint8_t DeviceColorLight::GetSaturationPercent()
{
  return ColorValueToPercent(this->saturation);
}

void DeviceColorLight::SetSaturationPercent(uint8_t percent)
{
  SetSaturation(PercentToColorValue(percent));
}

uint16_t DeviceColorLight::GetCurrentX()
{
  return this->current_x;
}

uint16_t DeviceColorLight::GetCurrentY()
{
  return this->current_y;
}

void DeviceColorLight::SetXy(uint16_t x, uint16_t y)
{
  uint16_t normalized_x = NormalizeXyValue(x);
  uint16_t normalized_y = NormalizeXyValue(y);
  uint8_t new_hue;
  uint8_t new_saturation;
  XyToHsv(normalized_x, normalized_y, &new_hue, &new_saturation);

  if (this->current_x == normalized_x
      && this->current_y == normalized_y
      && this->hue == new_hue
      && this->saturation == new_saturation
      && this->color_mode == COLOR_MODE_CURRENT_X_Y) {
    return;
  }

  this->current_x = normalized_x;
  this->current_y = normalized_y;
  this->hue = new_hue;
  this->saturation = new_saturation;
  this->color_mode = COLOR_MODE_CURRENT_X_Y;
  WriteColorModeAttributes();
  WriteHueAttributes();
  WriteSaturationAttribute();
  WriteXyAttributes();
  CallDeviceChangeCallback();
}

void DeviceColorLight::HandleAttributeChange(uint16_t cluster_id,
                                             uint16_t attribute_id,
                                             uint8_t size,
                                             uint8_t* value)
{
  DeviceDimmableLight::HandleAttributeChange(cluster_id, attribute_id, size, value);

  if (cluster_id != ZCL_COLOR_CONTROL_CLUSTER_ID) {
    return;
  }

  bool changed = false;
  if (attribute_id == ZCL_COLOR_CONTROL_CURRENT_HUE_ATTRIBUTE_ID && size >= 1) {
    uint8_t new_hue = NormalizeColorValue(*value);
    if (this->hue != new_hue) {
      this->hue = new_hue;
      HsvToXy(this->hue, this->saturation, &this->current_x, &this->current_y);
      this->color_mode = COLOR_MODE_HUE_SATURATION;
      WriteColorModeAttributes();
      WriteXyAttributes();
      changed = true;
    }
  } else if (attribute_id == ZCL_COLOR_CONTROL_CURRENT_SATURATION_ATTRIBUTE_ID && size >= 1) {
    uint8_t new_saturation = NormalizeColorValue(*value);
    if (this->saturation != new_saturation) {
      this->saturation = new_saturation;
      HsvToXy(this->hue, this->saturation, &this->current_x, &this->current_y);
      this->color_mode = COLOR_MODE_HUE_SATURATION;
      WriteColorModeAttributes();
      WriteXyAttributes();
      changed = true;
    }
  } else if (attribute_id == ZCL_COLOR_CONTROL_ENHANCED_CURRENT_HUE_ATTRIBUTE_ID && size >= 2) {
    uint8_t new_hue = EnhancedHueToHue(ReadInt16u(value));
    if (this->hue != new_hue) {
      this->hue = new_hue;
      HsvToXy(this->hue, this->saturation, &this->current_x, &this->current_y);
      this->color_mode = COLOR_MODE_HUE_SATURATION;
      WriteColorModeAttributes();
      WriteXyAttributes();
      changed = true;
    }
  } else if (attribute_id == ZCL_COLOR_CONTROL_CURRENT_X_ATTRIBUTE_ID && size >= 2) {
    uint16_t new_x = NormalizeXyValue(ReadInt16u(value));
    if (this->current_x != new_x) {
      this->current_x = new_x;
      XyToHsv(this->current_x, this->current_y, &this->hue, &this->saturation);
      this->color_mode = COLOR_MODE_CURRENT_X_Y;
      WriteColorModeAttributes();
      WriteHueAttributes();
      WriteSaturationAttribute();
      changed = true;
    }
  } else if (attribute_id == ZCL_COLOR_CONTROL_CURRENT_Y_ATTRIBUTE_ID && size >= 2) {
    uint16_t new_y = NormalizeXyValue(ReadInt16u(value));
    if (this->current_y != new_y) {
      this->current_y = new_y;
      XyToHsv(this->current_x, this->current_y, &this->hue, &this->saturation);
      this->color_mode = COLOR_MODE_CURRENT_X_Y;
      WriteColorModeAttributes();
      WriteHueAttributes();
      WriteSaturationAttribute();
      changed = true;
    }
  }

  if (changed) {
    CallDeviceChangeCallback();
  }
}

uint8_t DeviceColorLight::NormalizeColorValue(uint8_t value)
{
  if (value > COLOR_CONTROL_MAX_VALUE) {
    return COLOR_CONTROL_MAX_VALUE;
  }
  return value;
}

uint16_t DeviceColorLight::NormalizeXyValue(uint16_t value)
{
  return value;
}

uint8_t DeviceColorLight::PercentToColorValue(uint8_t percent)
{
  if (percent >= COLOR_PERCENT_MAX) {
    return COLOR_CONTROL_MAX_VALUE;
  }
  uint16_t value = static_cast<uint16_t>(percent) * COLOR_CONTROL_MAX_VALUE;
  return static_cast<uint8_t>((value + (COLOR_PERCENT_MAX / 2)) / COLOR_PERCENT_MAX);
}

uint8_t DeviceColorLight::ColorValueToPercent(uint8_t value)
{
  uint8_t normalized_value = NormalizeColorValue(value);
  if (normalized_value >= COLOR_CONTROL_MAX_VALUE) {
    return COLOR_PERCENT_MAX;
  }
  uint16_t percent = static_cast<uint16_t>(normalized_value) * COLOR_PERCENT_MAX;
  return static_cast<uint8_t>((percent + (COLOR_CONTROL_MAX_VALUE / 2)) / COLOR_CONTROL_MAX_VALUE);
}

uint8_t DeviceColorLight::TrueHueToHue(uint16_t true_hue)
{
  if (true_hue >= COLOR_TRUE_HUE_MAX) {
    return COLOR_CONTROL_MAX_VALUE;
  }
  uint32_t hue = static_cast<uint32_t>(true_hue) * COLOR_CONTROL_MAX_VALUE;
  return static_cast<uint8_t>((hue + (COLOR_TRUE_HUE_MAX / 2)) / COLOR_TRUE_HUE_MAX);
}

uint16_t DeviceColorLight::HueToTrueHue(uint8_t hue)
{
  uint8_t normalized_hue = NormalizeColorValue(hue);
  if (normalized_hue >= COLOR_CONTROL_MAX_VALUE) {
    return COLOR_TRUE_HUE_MAX;
  }
  uint32_t true_hue = static_cast<uint32_t>(normalized_hue) * COLOR_TRUE_HUE_MAX;
  return static_cast<uint16_t>((true_hue + (COLOR_CONTROL_MAX_VALUE / 2)) / COLOR_CONTROL_MAX_VALUE);
}

uint16_t DeviceColorLight::ReadInt16u(const uint8_t* value)
{
  return static_cast<uint16_t>(value[0]) | (static_cast<uint16_t>(value[1]) << 8);
}

uint8_t DeviceColorLight::EnhancedHueToHue(uint16_t enhanced_hue)
{
  uint32_t hue = static_cast<uint32_t>(enhanced_hue) * COLOR_CONTROL_MAX_VALUE;
  return static_cast<uint8_t>((hue + (UINT16_MAX / 2)) / UINT16_MAX);
}

uint16_t DeviceColorLight::HueToEnhancedHue(uint8_t hue)
{
  uint8_t normalized_hue = NormalizeColorValue(hue);
  uint32_t enhanced_hue = static_cast<uint32_t>(normalized_hue) * UINT16_MAX;
  return static_cast<uint16_t>((enhanced_hue + (COLOR_CONTROL_MAX_VALUE / 2)) / COLOR_CONTROL_MAX_VALUE);
}

uint16_t DeviceColorLight::FloatToXyValue(float value)
{
  if (value <= 0.0f) {
    return 0;
  }
  if (value >= 1.0f) {
    return UINT16_MAX;
  }
  return static_cast<uint16_t>((value * static_cast<float>(UINT16_MAX)) + 0.5f);
}

float DeviceColorLight::XyValueToFloat(uint16_t value)
{
  return static_cast<float>(value) / static_cast<float>(UINT16_MAX);
}

void DeviceColorLight::HsvToRgbFloat(uint8_t hue, uint8_t saturation, float* red, float* green, float* blue)
{
  float s = static_cast<float>(NormalizeColorValue(saturation)) / static_cast<float>(COLOR_CONTROL_MAX_VALUE);
  float h = (static_cast<float>(NormalizeColorValue(hue)) * 6.0f) / static_cast<float>(COLOR_CONTROL_MAX_VALUE);
  if (h >= 6.0f) {
    h = 0.0f;
  }

  int region = static_cast<int>(h);
  float fraction = h - static_cast<float>(region);
  float p = 1.0f - s;
  float q = 1.0f - (s * fraction);
  float t = 1.0f - (s * (1.0f - fraction));

  switch (region) {
    case 0:
      *red = 1.0f;
      *green = t;
      *blue = p;
      break;
    case 1:
      *red = q;
      *green = 1.0f;
      *blue = p;
      break;
    case 2:
      *red = p;
      *green = 1.0f;
      *blue = t;
      break;
    case 3:
      *red = p;
      *green = q;
      *blue = 1.0f;
      break;
    case 4:
      *red = t;
      *green = p;
      *blue = 1.0f;
      break;
    default:
      *red = 1.0f;
      *green = p;
      *blue = q;
      break;
  }
}

void DeviceColorLight::RgbFloatToHsv(float red, float green, float blue, uint8_t* hue, uint8_t* saturation)
{
  float rgb_max = red;
  if (green > rgb_max) {
    rgb_max = green;
  }
  if (blue > rgb_max) {
    rgb_max = blue;
  }

  float rgb_min = red;
  if (green < rgb_min) {
    rgb_min = green;
  }
  if (blue < rgb_min) {
    rgb_min = blue;
  }

  float delta = rgb_max - rgb_min;
  if (rgb_max <= 0.0f || delta <= 0.0f) {
    *hue = 0;
    *saturation = 0;
    return;
  }

  float h;
  if (rgb_max == red) {
    h = (green - blue) / delta;
    if (h < 0.0f) {
      h += 6.0f;
    }
  } else if (rgb_max == green) {
    h = ((blue - red) / delta) + 2.0f;
  } else {
    h = ((red - green) / delta) + 4.0f;
  }

  *hue = static_cast<uint8_t>(((h * static_cast<float>(COLOR_CONTROL_MAX_VALUE)) / 6.0f) + 0.5f);
  *saturation = static_cast<uint8_t>(((delta / rgb_max) * static_cast<float>(COLOR_CONTROL_MAX_VALUE)) + 0.5f);
}

void DeviceColorLight::HsvToXy(uint8_t hue, uint8_t saturation, uint16_t* x, uint16_t* y)
{
  float red;
  float green;
  float blue;
  HsvToRgbFloat(hue, saturation, &red, &green, &blue);

  float tristimulus_x = (0.4124f * red) + (0.3576f * green) + (0.1805f * blue);
  float tristimulus_y = (0.2126f * red) + (0.7152f * green) + (0.0722f * blue);
  float tristimulus_z = (0.0193f * red) + (0.1192f * green) + (0.9505f * blue);
  float sum = tristimulus_x + tristimulus_y + tristimulus_z;
  if (sum <= 0.0f) {
    *x = FloatToXyValue(0.3127f);
    *y = FloatToXyValue(0.3290f);
    return;
  }

  *x = FloatToXyValue(tristimulus_x / sum);
  *y = FloatToXyValue(tristimulus_y / sum);
}

void DeviceColorLight::XyToHsv(uint16_t x, uint16_t y, uint8_t* hue, uint8_t* saturation)
{
  float x_float = XyValueToFloat(x);
  float y_float = XyValueToFloat(y);
  if (y_float <= 0.0f) {
    *hue = 0;
    *saturation = 0;
    return;
  }

  float tristimulus_y = 1.0f;
  float tristimulus_x = x_float / y_float;
  float tristimulus_z = (1.0f - x_float - y_float) / y_float;
  float red = (3.2406f * tristimulus_x) - (1.5372f * tristimulus_y) - (0.4986f * tristimulus_z);
  float green = (-0.9689f * tristimulus_x) + (1.8758f * tristimulus_y) + (0.0415f * tristimulus_z);
  float blue = (0.0557f * tristimulus_x) - (0.2040f * tristimulus_y) + (1.0570f * tristimulus_z);

  if (red < 0.0f) {
    red = 0.0f;
  }
  if (green < 0.0f) {
    green = 0.0f;
  }
  if (blue < 0.0f) {
    blue = 0.0f;
  }

  float rgb_max = red;
  if (green > rgb_max) {
    rgb_max = green;
  }
  if (blue > rgb_max) {
    rgb_max = blue;
  }
  if (rgb_max <= 0.0f) {
    *hue = 0;
    *saturation = 0;
    return;
  }

  RgbFloatToHsv(red / rgb_max, green / rgb_max, blue / rgb_max, hue, saturation);
}

void DeviceColorLight::WriteColorModeAttributes()
{
  uint16_t color_capabilities = COLOR_CAPABILITIES;
  uint8_t number_of_primaries = 0;
  uint8_t options = 0;

  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_COLOR_MODE_ATTRIBUTE_ID,
                                      &this->color_mode,
                                      ZCL_ENUM8_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_ATTRIBUTE_ID,
                                      &this->color_mode,
                                      ZCL_ENUM8_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_COLOR_CAPABILITIES_ATTRIBUTE_ID,
                                      reinterpret_cast<uint8_t*>(&color_capabilities),
                                      ZCL_BITMAP16_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_NUMBER_OF_PRIMARIES_ATTRIBUTE_ID,
                                      &number_of_primaries,
                                      ZCL_INT8U_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_OPTIONS_ATTRIBUTE_ID,
                                      &options,
                                      ZCL_BITMAP8_ATTRIBUTE_TYPE);
}

void DeviceColorLight::WriteHueAttributes()
{
  uint16_t enhanced_hue = HueToEnhancedHue(this->hue);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_CURRENT_HUE_ATTRIBUTE_ID,
                                      &this->hue,
                                      ZCL_INT8U_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_ENHANCED_CURRENT_HUE_ATTRIBUTE_ID,
                                      reinterpret_cast<uint8_t*>(&enhanced_hue),
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
}

void DeviceColorLight::WriteSaturationAttribute()
{
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_CURRENT_SATURATION_ATTRIBUTE_ID,
                                      &this->saturation,
                                      ZCL_INT8U_ATTRIBUTE_TYPE);
}

void DeviceColorLight::WriteXyAttributes()
{
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_CURRENT_X_ATTRIBUTE_ID,
                                      reinterpret_cast<uint8_t*>(&this->current_x),
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
  sl_zigbee_af_write_server_attribute(this->endpoint_id,
                                      ZCL_COLOR_CONTROL_CLUSTER_ID,
                                      ZCL_COLOR_CONTROL_CURRENT_Y_ATTRIBUTE_ID,
                                      reinterpret_cast<uint8_t*>(&this->current_y),
                                      ZCL_INT16U_ATTRIBUTE_TYPE);
}
