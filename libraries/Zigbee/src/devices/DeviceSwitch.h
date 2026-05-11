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

#ifndef DEVICE_SWITCH_H
#define DEVICE_SWITCH_H

#include "ZigbeeDevice.h"

class DeviceSwitch : public ZigbeeDevice {
public:
  DeviceSwitch(const char* device_name, uint8_t endpoint_id);

  void SendOn();
  void SendOff();
  void SendToggle();
  void SendDimUp(uint8_t rate_percent = 50);
  void SendDimDown(uint8_t rate_percent = 50);
  void SendStopDimming();
  void SendMoveToLevel(uint8_t level, uint32_t transition_time_ms = 0);
  void SendMoveToPercent(uint8_t percent, uint32_t transition_time_ms = 0);

  void HandleAttributeChange(uint16_t cluster_id,
                             uint16_t attribute_id,
                             uint8_t size,
                             uint8_t* value) override;

private:
  static const uint8_t LEVEL_CONTROL_MAX_LEVEL = 254;
  static const uint16_t ZCL_TRANSITION_TIME_MAX = 0xFFFE;
  enum OnOffCmd { CMD_ON, CMD_OFF, CMD_TOGGLE };
  enum LevelMoveMode { LEVEL_MOVE_UP = 0x00, LEVEL_MOVE_DOWN = 0x01 };

  static uint8_t PercentToLevel(uint8_t percent);
  static uint16_t MillisecondsToZclTransitionTime(uint32_t transition_time_ms);
  void FillOnOffBuffer(OnOffCmd cmd);
  void FillLevelMoveBuffer(LevelMoveMode move_mode, uint8_t rate);
  void FillLevelStopBuffer();
  void FillMoveToLevelBuffer(uint8_t level, uint16_t transition_time_tenths);
  void SendOnOffCommand(OnOffCmd cmd);
  void SendLevelMoveCommand(LevelMoveMode move_mode, uint8_t rate);
  void SendLevelStopCommand();
  void SendMoveToLevelCommand(uint8_t level, uint16_t transition_time_tenths);
};

#endif // DEVICE_SWITCH_H
