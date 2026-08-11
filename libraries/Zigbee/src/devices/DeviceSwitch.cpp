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

#include "DeviceSwitch.h"
#include "../ZigbeeAfLock.h"

extern "C" {
#include "af.h"
}

DeviceSwitch::DeviceSwitch(const char* device_name, uint8_t endpoint_id) :
  ZigbeeDevice(device_name, endpoint_id)
{
}

void DeviceSwitch::FillOnOffBuffer(OnOffCmd cmd)
{
  switch (cmd) {
    case CMD_ON:
      sl_zigbee_af_fill_command_on_off_cluster_on();
      break;
    case CMD_OFF:
      sl_zigbee_af_fill_command_on_off_cluster_off();
      break;
    case CMD_TOGGLE:
      sl_zigbee_af_fill_command_on_off_cluster_toggle();
      break;
  }
}

void DeviceSwitch::FillLevelMoveBuffer(LevelMoveMode move_mode, uint8_t rate)
{
  sl_zigbee_af_fill_command_level_control_cluster_move(move_mode, rate, 0x00, 0x00);
}

void DeviceSwitch::FillLevelStopBuffer()
{
  sl_zigbee_af_fill_command_level_control_cluster_stop(0x00, 0x00);
}

void DeviceSwitch::FillMoveToLevelBuffer(uint8_t level, uint16_t transition_time_tenths)
{
  sl_zigbee_af_fill_command_level_control_cluster_move_to_level(level, transition_time_tenths, 0x00, 0x00);
}

void DeviceSwitch::SendOnOffCommand(OnOffCmd cmd)
{
  ZigbeeAfLock lock;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);

  FillOnOffBuffer(cmd);
  sl_zigbee_af_send_command_unicast(SL_ZIGBEE_OUTGOING_DIRECT, 0x0000);

  FillOnOffBuffer(cmd);
  sl_zigbee_af_send_command_unicast_to_bindings();

  FillOnOffBuffer(cmd);
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceSwitch::SendLevelMoveCommand(LevelMoveMode move_mode, uint8_t rate)
{
  ZigbeeAfLock lock;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);

  FillLevelMoveBuffer(move_mode, rate);
  sl_zigbee_af_send_command_unicast(SL_ZIGBEE_OUTGOING_DIRECT, 0x0000);

  FillLevelMoveBuffer(move_mode, rate);
  sl_zigbee_af_send_command_unicast_to_bindings();

  FillLevelMoveBuffer(move_mode, rate);
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceSwitch::SendLevelStopCommand()
{
  ZigbeeAfLock lock;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);

  FillLevelStopBuffer();
  sl_zigbee_af_send_command_unicast(SL_ZIGBEE_OUTGOING_DIRECT, 0x0000);

  FillLevelStopBuffer();
  sl_zigbee_af_send_command_unicast_to_bindings();

  FillLevelStopBuffer();
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceSwitch::SendMoveToLevelCommand(uint8_t level, uint16_t transition_time_tenths)
{
  ZigbeeAfLock lock;

  sl_zigbee_af_set_command_endpoints(this->endpoint_id, 1);

  FillMoveToLevelBuffer(level, transition_time_tenths);
  sl_zigbee_af_send_command_unicast(SL_ZIGBEE_OUTGOING_DIRECT, 0x0000);

  FillMoveToLevelBuffer(level, transition_time_tenths);
  sl_zigbee_af_send_command_unicast_to_bindings();

  FillMoveToLevelBuffer(level, transition_time_tenths);
  sl_zigbee_af_send_command_multicast_to_bindings();
}

void DeviceSwitch::SendOn()
{
  SendOnOffCommand(CMD_ON);
}

void DeviceSwitch::SendOff()
{
  SendOnOffCommand(CMD_OFF);
}

void DeviceSwitch::SendToggle()
{
  SendOnOffCommand(CMD_TOGGLE);
}

void DeviceSwitch::SendDimUp(uint8_t rate_percent)
{
  SendLevelMoveCommand(LEVEL_MOVE_UP, PercentToLevel(rate_percent));
}

void DeviceSwitch::SendDimDown(uint8_t rate_percent)
{
  SendLevelMoveCommand(LEVEL_MOVE_DOWN, PercentToLevel(rate_percent));
}

void DeviceSwitch::SendStopDimming()
{
  SendLevelStopCommand();
}

void DeviceSwitch::SendMoveToLevel(uint8_t level, uint32_t transition_time_ms)
{
  SendMoveToLevelCommand(level, MillisecondsToZclTransitionTime(transition_time_ms));
}

void DeviceSwitch::SendMoveToPercent(uint8_t percent, uint32_t transition_time_ms)
{
  SendMoveToLevel(PercentToLevel(percent), transition_time_ms);
}

uint8_t DeviceSwitch::PercentToLevel(uint8_t percent)
{
  static const uint8_t LEVEL_PERCENT_MAX = 100u;
  if (percent >= LEVEL_PERCENT_MAX) {
    return LEVEL_CONTROL_MAX_LEVEL;
  }
  uint16_t level = static_cast<uint16_t>(percent) * LEVEL_CONTROL_MAX_LEVEL;
  return static_cast<uint8_t>((level + (LEVEL_PERCENT_MAX / 2)) / LEVEL_PERCENT_MAX);
}

uint16_t DeviceSwitch::MillisecondsToZclTransitionTime(uint32_t transition_time_ms)
{
  if (transition_time_ms == 0) {
    return 0;
  }
  uint32_t transition_time_tenths = (transition_time_ms + 99) / 100;
  if (transition_time_tenths > ZCL_TRANSITION_TIME_MAX) {
    return ZCL_TRANSITION_TIME_MAX;
  }
  return static_cast<uint16_t>(transition_time_tenths);
}

void DeviceSwitch::HandleAttributeChange(uint16_t cluster_id,
                                              uint16_t attribute_id,
                                              uint8_t size,
                                              uint8_t* value)
{
  (void)cluster_id;
  (void)attribute_id;
  (void)size;
  (void)value;
}
