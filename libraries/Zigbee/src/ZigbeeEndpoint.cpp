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

#include "ZigbeeEndpoint.h"

static ZigbeeDevice* registered_devices[ZigbeeDevice::kMaxEndpoints] = { nullptr };

bool zigbee_endpoint_register(ZigbeeDevice* device)
{
  if (!device) {
    return false;
  }

  // Reject if this endpoint ID is already registered
  const uint8_t endpoint_id = device->GetEndpointId();
  for (uint8_t i = 0; i < ZigbeeDevice::kMaxEndpoints; i++) {
    if (registered_devices[i] != nullptr && registered_devices[i]->GetEndpointId() == endpoint_id) {
      return false;
    }
  }

  // Insert into the first free table slot
  for (uint8_t i = 0; i < ZigbeeDevice::kMaxEndpoints; i++) {
    if (registered_devices[i] == nullptr) {
      registered_devices[i] = device;
      return true;
    }
  }
  return false;
}

bool zigbee_endpoint_unregister(ZigbeeDevice* device)
{
  if (!device) {
    return false;
  }
  for (uint8_t i = 0; i < ZigbeeDevice::kMaxEndpoints; i++) {
    if (registered_devices[i] == device) {
      registered_devices[i] = nullptr;
      return true;
    }
  }
  return false;
}

ZigbeeDevice* zigbee_endpoint_get_device(uint8_t endpoint_id)
{
  for (uint8_t i = 0; i < ZigbeeDevice::kMaxEndpoints; i++) {
    if (registered_devices[i] && registered_devices[i]->GetEndpointId() == endpoint_id) {
      return registered_devices[i];
    }
  }
  return nullptr;
}
