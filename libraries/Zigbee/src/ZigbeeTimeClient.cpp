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

#include "ZigbeeTimeClient.h"

ZigbeeTimeClient::ZigbeeTimeClient() :
  time_client_device(nullptr),
  initialized(false),
  time_update_callback(nullptr)
{
}

ZigbeeTimeClient::~ZigbeeTimeClient()
{
  end();
}

bool ZigbeeTimeClient::begin()
{
  if (this->initialized) {
    return false;
  }

  uint8_t ep = Zigbee.allocateTimeClientEndpoint();
  if (ep == 0) {
    return false;
  }

  this->time_client_device = new DeviceTimeClient("Zigbee Time Client", ep);
  if (!this->time_client_device) {
    Zigbee.freeEndpoint(ep);
    return false;
  }

  this->base_zigbee_device = this->time_client_device;
  this->time_client_device->SetTimeUpdateCallback(this->time_update_callback);

  if (!zigbee_endpoint_register(this->time_client_device)) {
    Zigbee.freeEndpoint(ep);
    delete this->time_client_device;
    this->time_client_device = nullptr;
    this->base_zigbee_device = nullptr;
    return false;
  }

  DeviceTimeClient::RegisterTimeClient(this->time_client_device);
  this->time_client_device->SetOnline(true);
  this->initialized = true;
  return true;
}

void ZigbeeTimeClient::end()
{
  if (!this->initialized) {
    return;
  }
  DeviceTimeClient::UnregisterTimeClient(this->time_client_device);
  Zigbee.freeEndpoint(this->time_client_device->GetEndpointId());
  zigbee_endpoint_unregister(this->time_client_device);
  delete this->time_client_device;
  this->time_client_device = nullptr;
  this->base_zigbee_device = nullptr;
  this->initialized = false;
}

bool ZigbeeTimeClient::request_time(uint8_t coordinator_endpoint_id)
{
  if (!this->time_client_device) {
    return false;
  }
  return this->time_client_device->RequestTime(coordinator_endpoint_id);
}

bool ZigbeeTimeClient::has_time()
{
  return this->time_client_device && this->time_client_device->HasTime();
}

uint32_t ZigbeeTimeClient::get_zigbee_time()
{
  if (!this->time_client_device) {
    return 0;
  }
  return this->time_client_device->GetZigbeeTime();
}

uint32_t ZigbeeTimeClient::get_unix_time()
{
  if (!this->time_client_device) {
    return 0;
  }
  return this->time_client_device->GetUnixTime();
}

uint32_t ZigbeeTimeClient::get_local_unix_time()
{
  if (!this->time_client_device) {
    return 0;
  }
  return this->time_client_device->GetLocalUnixTime();
}

bool ZigbeeTimeClient::has_timezone()
{
  return this->time_client_device && this->time_client_device->HasTimeZone();
}

int32_t ZigbeeTimeClient::get_timezone()
{
  if (!this->time_client_device) {
    return 0;
  }
  return this->time_client_device->GetTimeZone();
}

uint8_t ZigbeeTimeClient::get_time_status()
{
  if (!this->time_client_device) {
    return 0;
  }
  return this->time_client_device->GetTimeStatus();
}

void ZigbeeTimeClient::set_time_update_callback(void (*cb)(void))
{
  this->time_update_callback = cb;
  if (this->time_client_device) {
    this->time_client_device->SetTimeUpdateCallback(cb);
  }
}
