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

#ifndef MATTER_WATER_VALVE_H
#define MATTER_WATER_VALVE_H

#include "Matter.h"
#include "devices/DeviceWaterValve.h"
#include <platform/CHIPDeviceLayer.h>
#include <app-common/zap-generated/attributes/Accessors.h>

using namespace chip;
using namespace ::chip::DeviceLayer;

class WaterValveCommandHandler;

class MatterWaterValve : public ArduinoMatterAppliance {
public:

  enum valve_state_t {
    VALVE_STATE_CLOSED        = 0,
    VALVE_STATE_OPEN          = 1,
    VALVE_STATE_TRANSITIONING = 2
  };

  enum valve_fault_t {
    VALVE_FAULT_GENERAL_FAULT     = 0x01,
    VALVE_FAULT_BLOCKED           = 0x02,
    VALVE_FAULT_LEAKING           = 0x04,
    VALVE_FAULT_NOT_CONNECTED     = 0x08,
    VALVE_FAULT_SHORT_CIRCUIT     = 0x10,
    VALVE_FAULT_CURRENT_EXCEEDED  = 0x20
  };

  MatterWaterValve();
  ~MatterWaterValve();
  bool begin();
  void end();

  void open();
  void open(uint32_t duration_seconds);
  void close();

  valve_state_t get_current_state();
  valve_state_t get_target_state();

  uint32_t get_open_duration();

  uint32_t get_default_open_duration();
  void set_default_open_duration(uint32_t duration_seconds);

  uint32_t get_remaining_duration();
  void set_remaining_duration(uint32_t remaining_duration_seconds);

  uint16_t get_valve_fault();
  void set_valve_fault(valve_fault_t valve_fault);

private:
  DeviceWaterValve* water_valve_device;
  EmberAfEndpointType* device_endpoint;
  DataVersion* endpoint_dataversion_storage;
  WaterValveCommandHandler* command_handler;
  bool initialized;
};

#endif // MATTER_WATER_VALVE_H
