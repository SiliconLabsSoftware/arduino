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

#include "ZigbeeColorLightbulb.h"

ZigbeeColorLightbulb::ZigbeeColorLightbulb() :
  ZigbeeDimmableLightbulb(),
  saturation_boost(0)
{
}

bool ZigbeeColorLightbulb::begin()
{
  return this->beginEndpointType(ZIGBEE_COLOR_LIGHT);
}

void ZigbeeColorLightbulb::set_hue(uint8_t hue)
{
  DeviceColorLight* device = this->get_color_light_device();
  if (device) {
    device->SetHue(hue);
  }
}

uint8_t ZigbeeColorLightbulb::get_hue()
{
  DeviceColorLight* device = this->get_color_light_device();
  if (!device) {
    return 0;
  }
  return device->GetHue();
}

void ZigbeeColorLightbulb::set_saturation(uint8_t saturation)
{
  DeviceColorLight* device = this->get_color_light_device();
  if (device) {
    device->SetSaturation(saturation);
  }
}

uint8_t ZigbeeColorLightbulb::get_saturation()
{
  return this->get_boosted_saturation();
}

void ZigbeeColorLightbulb::set_color(uint8_t hue, uint8_t saturation)
{
  DeviceColorLight* device = this->get_color_light_device();
  if (device) {
    device->SetColor(hue, saturation);
  }
}

uint16_t ZigbeeColorLightbulb::get_true_hue()
{
  DeviceColorLight* device = this->get_color_light_device();
  if (!device) {
    return 0;
  }
  return device->GetTrueHue();
}

void ZigbeeColorLightbulb::set_true_hue(uint16_t true_hue)
{
  DeviceColorLight* device = this->get_color_light_device();
  if (device) {
    device->SetTrueHue(true_hue);
  }
}

uint8_t ZigbeeColorLightbulb::get_saturation_percent()
{
  uint16_t percent = static_cast<uint16_t>(get_boosted_saturation()) * 100u;
  return static_cast<uint8_t>((percent + 127u) / 254u);
}

void ZigbeeColorLightbulb::set_saturation_percent(uint8_t saturation)
{
  DeviceColorLight* device = this->get_color_light_device();
  if (device) {
    device->SetSaturationPercent(saturation);
  }
}

void ZigbeeColorLightbulb::get_rgb(uint8_t* r, uint8_t* g, uint8_t* b)
{
  if (!r || !g || !b) {
    return;
  }
  this->hsv_to_rgb(get_hue(), get_boosted_saturation(), color_value_to_rgb_value(get_level()), r, g, b);
}

void ZigbeeColorLightbulb::get_rgb_raw(uint8_t* r, uint8_t* g, uint8_t* b)
{
  if (!r || !g || !b) {
    return;
  }
  this->hsv_to_rgb(get_hue(), get_boosted_saturation(), 255, r, g, b);
}

void ZigbeeColorLightbulb::set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
  uint8_t hue;
  uint8_t saturation;
  uint8_t value;
  this->rgb_to_hsv(r, g, b, &hue, &saturation, &value);
  this->set_color(hue, saturation);
  this->set_level(this->rgb_value_to_color_value(value));
}

void ZigbeeColorLightbulb::boost_saturation(uint8_t amount)
{
  this->saturation_boost = amount;
}

DeviceOnOffLight* ZigbeeColorLightbulb::CreateLightDevice(const char* device_name, uint8_t endpoint_id)
{
  return new DeviceColorLight(device_name, endpoint_id);
}

const char* ZigbeeColorLightbulb::GetDeviceName() const
{
  return "Zigbee Color Lightbulb";
}

DeviceColorLight* ZigbeeColorLightbulb::get_color_light_device()
{
  return static_cast<DeviceColorLight*>(this->light_device);
}

uint8_t ZigbeeColorLightbulb::get_boosted_saturation()
{
  DeviceColorLight* device = this->get_color_light_device();
  if (!device) {
    return 0;
  }
  uint16_t saturation = device->GetSaturation() + this->saturation_boost;
  if (saturation > 254u) {
    return 254u;
  }
  return static_cast<uint8_t>(saturation);
}

uint8_t ZigbeeColorLightbulb::color_value_to_rgb_value(uint8_t value)
{
  uint16_t scaled_value = static_cast<uint16_t>(value) * 255u;
  return static_cast<uint8_t>((scaled_value + 127u) / 254u);
}

uint8_t ZigbeeColorLightbulb::rgb_value_to_color_value(uint8_t value)
{
  uint16_t scaled_value = static_cast<uint16_t>(value) * 254u;
  return static_cast<uint8_t>((scaled_value + 127u) / 255u);
}

void ZigbeeColorLightbulb::hsv_to_rgb(uint8_t hue, uint8_t saturation, uint8_t value, uint8_t* r, uint8_t* g, uint8_t* b)
{
  uint16_t rgb_saturation = color_value_to_rgb_value(saturation);
  uint16_t hue_sector = (static_cast<uint32_t>(hue) * 1530u + 127u) / 254u;
  if (hue_sector >= 1530u) {
    hue_sector = 0u;
  }

  uint8_t region = hue_sector / 255u;
  uint8_t remainder = hue_sector - (region * 255u);
  uint8_t p = (static_cast<uint16_t>(value) * (255u - rgb_saturation) + 127u) / 255u;
  uint8_t q = (static_cast<uint16_t>(value) * (255u - ((rgb_saturation * remainder + 127u) / 255u)) + 127u) / 255u;
  uint8_t t = (static_cast<uint16_t>(value) * (255u - ((rgb_saturation * (255u - remainder) + 127u) / 255u)) + 127u) / 255u;

  switch (region) {
    case 0:
      *r = value;
      *g = t;
      *b = p;
      break;
    case 1:
      *r = q;
      *g = value;
      *b = p;
      break;
    case 2:
      *r = p;
      *g = value;
      *b = t;
      break;
    case 3:
      *r = p;
      *g = q;
      *b = value;
      break;
    case 4:
      *r = t;
      *g = p;
      *b = value;
      break;
    default:
      *r = value;
      *g = p;
      *b = q;
      break;
  }
}

void ZigbeeColorLightbulb::rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b, uint8_t* hue, uint8_t* saturation, uint8_t* value)
{
  uint8_t rgb_max = max3(r, g, b);
  uint8_t rgb_min = min3(r, g, b);
  uint8_t delta = rgb_max - rgb_min;
  *value = rgb_max;

  if (rgb_max == 0 || delta == 0) {
    *hue = 0;
    *saturation = 0;
    return;
  }

  *saturation = static_cast<uint8_t>((static_cast<uint16_t>(delta) * 254u + (rgb_max / 2u)) / rgb_max);

  int32_t hue_sector;
  if (rgb_max == r) {
    hue_sector = (255L * (static_cast<int32_t>(g) - static_cast<int32_t>(b))) / delta;
    if (hue_sector < 0) {
      hue_sector += 1530L;
    }
  } else if (rgb_max == g) {
    hue_sector = 510L + (255L * (static_cast<int32_t>(b) - static_cast<int32_t>(r))) / delta;
  } else {
    hue_sector = 1020L + (255L * (static_cast<int32_t>(r) - static_cast<int32_t>(g))) / delta;
  }

  if (hue_sector < 0) {
    hue_sector += 1530L;
  }
  if (hue_sector >= 1530L) {
    hue_sector -= 1530L;
  }
  *hue = static_cast<uint8_t>((static_cast<uint32_t>(hue_sector) * 254u + 765u) / 1530u);
}

uint8_t ZigbeeColorLightbulb::max3(uint8_t a, uint8_t b, uint8_t c)
{
  uint8_t max_value = a;
  if (b > max_value) {
    max_value = b;
  }
  if (c > max_value) {
    max_value = c;
  }
  return max_value;
}

uint8_t ZigbeeColorLightbulb::min3(uint8_t a, uint8_t b, uint8_t c)
{
  uint8_t min_value = a;
  if (b < min_value) {
    min_value = b;
  }
  if (c < min_value) {
    min_value = c;
  }
  return min_value;
}
