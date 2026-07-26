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

#include "MatterTimeSynchronization.h"

#include <app/EventLogging.h>
#include <app/clusters/time-synchronization-server/DefaultTimeSyncDelegate.h>
#include <app/clusters/time-synchronization-server/time-synchronization-server.h>
#include <lib/support/TimeUtils.h>

using namespace chip;
using namespace chip::app::Clusters::TimeSynchronization;
using namespace chip::DeviceLayer;
using namespace chip::System;
using namespace chip::System::Clock;

namespace {
// InitClock_RealTime seeds Unix 946684800 (2000-01-01). Treat anything within
// one day of that as "not synchronized".
constexpr uint64_t kPlaceholderUnixMs = static_cast<uint64_t>(CHIP_SYSTEM_CONFIG_VALID_REAL_TIME_THRESHOLD) * 1000ULL;
constexpr uint64_t kMinValidUnixMs = kPlaceholderUnixMs + 86400000ULL;

// Avoid flooding controllers with TimeFailure events from tight sketch loops.
constexpr uint32_t kRequestTimeMinIntervalMs = 60000;

MatterTimeSynchronization* g_active_time_sync = nullptr;

bool read_valid_unix_time_ms(uint64_t& out_unix_ms)
{
  Clock::Milliseconds64 utc_time_ms;
  if (SystemClock().GetClock_RealTimeMS(utc_time_ms) != CHIP_NO_ERROR) {
    return false;
  }
  if (utc_time_ms.count() < kMinValidUnixMs) {
    return false;
  }
  out_unix_ms = utc_time_ms.count();
  return true;
}

int32_t read_timezone_offset_seconds()
{
  auto& tz_list = TimeSynchronizationServer::Instance().GetTimeZone();
  if (tz_list.size() == 0) {
    return 0;
  }
  return tz_list[0].timeZone.offset;
}

int32_t read_dst_offset_seconds(uint64_t chip_epoch_us)
{
  auto& dst_list = TimeSynchronizationServer::Instance().GetDSTOffset();
  if (dst_list.size() == 0) {
    return 0;
  }

  size_t active_index = dst_list.size();
  for (size_t i = 0; i < dst_list.size(); i++) {
    if (dst_list[i].validStarting <= chip_epoch_us) {
      active_index = i;
    }
  }
  if (active_index >= dst_list.size()) {
    return 0;
  }

  const auto& dst = dst_list[active_index];
  if (!dst.validUntil.IsNull() && dst.validUntil.Value() <= chip_epoch_us) {
    return 0;
  }
  return dst.offset;
}

class ArduinoMatterTimeSyncDelegate : public DefaultTimeSyncDelegate {
public:
  // Never claim platform wall-clock time. FreeRTOS InitClock_RealTime only
  // seeds a year-2000 placeholder; GetClock_RealTimeMS would otherwise look
  // "valid" to the default delegate and mark the cluster synced without a
  // controller SetUTCTime.
  CHIP_ERROR UpdateTimeFromPlatformSource(chip::Callback::Callback<OnTimeSyncCompletion>* callback) override
  {
    (void)callback;
    return CHIP_ERROR_NOT_IMPLEMENTED;
  }

  void UTCTimeAvailabilityChanged(uint64_t time) override
  {
    (void)time;
    if (g_active_time_sync != nullptr) {
      g_active_time_sync->notify_time_update();
    }
  }

  void TimeZoneListChanged(const Span<TimeSyncDataProvider::TimeZoneStore> timeZoneList) override
  {
    (void)timeZoneList;
    if (g_active_time_sync != nullptr) {
      g_active_time_sync->notify_timezone_update();
    }
  }
};

ArduinoMatterTimeSyncDelegate g_time_sync_delegate;
} // namespace

/***************************************************************************//**
 * Constructor for MatterTimeSynchronization
 ******************************************************************************/
MatterTimeSynchronization::MatterTimeSynchronization() :
  initialized(false),
  time_available(false),
  timezone_available(false),
  last_request_time_ms(0),
  time_update_callback(nullptr),
  timezone_update_callback(nullptr)
{
  ;
}

/***************************************************************************//**
 * Destructor for MatterTimeSynchronization
 ******************************************************************************/
MatterTimeSynchronization::~MatterTimeSynchronization()
{
  this->end();
}

/***************************************************************************//**
 * Initializes the MatterTimeSynchronization instance
 *
 * Registers a Time Synchronization delegate so application callbacks are
 * invoked when the controller sets UTC time or timezone on the root endpoint.
 *
 * @return true if the initialization succeeded, false otherwise
 ******************************************************************************/
bool MatterTimeSynchronization::begin()
{
  if (this->initialized) {
    return false;
  }

  g_active_time_sync = this;
  SetDefaultDelegate(&g_time_sync_delegate);

  this->time_available = false;
  this->timezone_available = false;
  this->last_request_time_ms = 0;
  this->initialized = true;
  return true;
}

/***************************************************************************//**
 * Deinitializes the MatterTimeSynchronization instance
 ******************************************************************************/
void MatterTimeSynchronization::end()
{
  if (!this->initialized) {
    return;
  }

  if (g_active_time_sync == this) {
    g_active_time_sync = nullptr;
  }
  this->time_update_callback = nullptr;
  this->timezone_update_callback = nullptr;
  this->time_available = false;
  this->timezone_available = false;
  this->last_request_time_ms = 0;
  this->initialized = false;
}

/***************************************************************************//**
 * Checks whether wall-clock time has been synchronized by a controller
 *
 * Prefer the UTCTimeAvailabilityChanged latch, but also accept a non-placeholder
 * SystemClock value in case SetUTCTime updated the clock without our callback
 * being observed.
 *
 * @return true if a controller has set UTC time, false otherwise
 ******************************************************************************/
bool MatterTimeSynchronization::has_time()
{
  if (!this->initialized) {
    return false;
  }

  if (this->time_available) {
    return true;
  }

  // Keep our delegate registered in case something else replaced it.
  SetDefaultDelegate(&g_time_sync_delegate);

  uint64_t unix_ms = 0;
  if (!read_valid_unix_time_ms(unix_ms)) {
    return false;
  }

  this->time_available = true;
  return true;
}

/***************************************************************************//**
 * Gets the current Unix time in seconds
 *
 * @return seconds since 1970-01-01 UTC, or 0 if time is not synchronized
 ******************************************************************************/
uint32_t MatterTimeSynchronization::get_unix_time()
{
  return static_cast<uint32_t>(this->get_unix_time_millis() / 1000ULL);
}

/***************************************************************************//**
 * Gets the current Unix time in milliseconds
 *
 * Uses GetClock_RealTimeMS because FreeRTOS/Silabs GetClock_RealTime() always
 * returns CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE.
 *
 * @return milliseconds since 1970-01-01 UTC, or 0 if time is not synchronized
 ******************************************************************************/
uint64_t MatterTimeSynchronization::get_unix_time_millis()
{
  if (!this->has_time()) {
    return 0;
  }

  uint64_t unix_ms = 0;
  if (!read_valid_unix_time_ms(unix_ms)) {
    return 0;
  }
  return unix_ms;
}

/***************************************************************************//**
 * Checks whether a controller has pushed a timezone via SetTimeZone
 *
 * @return true if SetTimeZone has been received, false otherwise
 ******************************************************************************/
bool MatterTimeSynchronization::has_timezone()
{
  if (!this->initialized) {
    return false;
  }

  return this->timezone_available;
}

/***************************************************************************//**
 * Requests time synchronization from the Matter controller
 *
 * Emits a TimeFailure event on the root endpoint. Controllers that subscribe to
 * this event (for example matter.js TimeSyncManager) may respond with SetUTCTime
 * and timezone/DST commands. Rate-limited to once per 60 seconds.
 *
 * Note: some controllers currently ignore TimeFailure during a cooldown window
 * after a prior sync; restarting the Matter Server clears that state today.
 *
 * @return true if the event was emitted, false if not initialized, rate-limited,
 *         or logging failed
 ******************************************************************************/
bool MatterTimeSynchronization::request_time()
{
  if (!this->initialized) {
    return false;
  }

  const uint32_t now_ms = millis();
  if ((this->last_request_time_ms != 0) && ((now_ms - this->last_request_time_ms) < kRequestTimeMinIntervalMs)) {
    return false;
  }

  Events::TimeFailure::Type event;
  EventNumber event_number = 0;

  PlatformMgr().LockChipStack();
  CHIP_ERROR err = app::LogEvent(event, kRootEndpointId, event_number);
  PlatformMgr().UnlockChipStack();

  if (err != CHIP_NO_ERROR) {
    return false;
  }

  this->last_request_time_ms = now_ms;
  return true;
}

/***************************************************************************//**
 * Gets the active timezone base offset in seconds (excluding DST)
 *
 * @return timezone offset in seconds east of UTC, or 0 if unavailable
 ******************************************************************************/
int32_t MatterTimeSynchronization::get_timezone_offset_seconds()
{
  if (!this->has_timezone()) {
    return 0;
  }
  return read_timezone_offset_seconds();
}

/***************************************************************************//**
 * Gets the currently applicable DST offset in seconds
 *
 * @return DST offset in seconds, or 0 if unavailable / not in DST
 ******************************************************************************/
int32_t MatterTimeSynchronization::get_dst_offset_seconds()
{
  if (!this->has_timezone()) {
    return 0;
  }

  uint64_t unix_ms = 0;
  if (!read_valid_unix_time_ms(unix_ms)) {
    // Timezone may arrive before UTC; still allow reading DST against epoch 0.
    unix_ms = kMinValidUnixMs;
  }

  uint64_t chip_epoch_us = 0;
  if (!UnixEpochToChipEpochMicros(unix_ms * 1000ULL, chip_epoch_us)) {
    return 0;
  }
  return read_dst_offset_seconds(chip_epoch_us);
}

/***************************************************************************//**
 * Gets the combined local offset (timezone + DST) in seconds
 *
 * @return local offset in seconds east of UTC, or 0 if timezone unavailable
 ******************************************************************************/
int32_t MatterTimeSynchronization::get_local_offset_seconds()
{
  return this->get_timezone_offset_seconds() + this->get_dst_offset_seconds();
}

/***************************************************************************//**
 * Gets the current local Unix time in seconds
 *
 * If timezone has not been set yet, returns UTC Unix time.
 *
 * @return seconds since 1970-01-01 in local time, or 0 if time is unavailable
 ******************************************************************************/
uint32_t MatterTimeSynchronization::get_local_unix_time()
{
  return static_cast<uint32_t>(this->get_local_unix_time_millis() / 1000ULL);
}

/***************************************************************************//**
 * Gets the current local Unix time in milliseconds
 *
 * Computed as UTC + timezone + DST. Does not use cluster GetLocalTime(), which
 * depends on FreeRTOS GetClock_RealTime() (always unsupported on this platform).
 * If timezone has not been set yet, returns UTC Unix time.
 *
 * @return milliseconds since 1970-01-01 in local time, or 0 if unavailable
 ******************************************************************************/
uint64_t MatterTimeSynchronization::get_local_unix_time_millis()
{
  uint64_t unix_ms = this->get_unix_time_millis();
  if (unix_ms == 0) {
    return 0;
  }
  if (!this->has_timezone()) {
    return unix_ms;
  }

  const int64_t offset_ms = static_cast<int64_t>(this->get_local_offset_seconds()) * 1000LL;
  return static_cast<uint64_t>(static_cast<int64_t>(unix_ms) + offset_ms);
}

/***************************************************************************//**
 * Sets a callback invoked when UTC time becomes available or is updated
 *
 * @param[in] cb callback function pointer, or nullptr to clear
 ******************************************************************************/
void MatterTimeSynchronization::set_time_update_callback(void (*cb)(void))
{
  this->time_update_callback = cb;
}

/***************************************************************************//**
 * Sets a callback invoked when the timezone list is updated by the controller
 *
 * @param[in] cb callback function pointer, or nullptr to clear
 ******************************************************************************/
void MatterTimeSynchronization::set_timezone_update_callback(void (*cb)(void))
{
  this->timezone_update_callback = cb;
}

/***************************************************************************//**
 * Conversion operator returning Unix time in seconds
 *
 * @return seconds since 1970-01-01 UTC, or 0 if time is not synchronized
 ******************************************************************************/
MatterTimeSynchronization::operator uint32_t()
{
  return this->get_unix_time();
}

/***************************************************************************//**
 * Marks time as available and invokes the user time-update callback if set.
 * Invoked by the Time Synchronization cluster delegate when UTC time changes.
 ******************************************************************************/
void MatterTimeSynchronization::notify_time_update()
{
  uint64_t unix_ms = 0;
  if (!read_valid_unix_time_ms(unix_ms)) {
    return;
  }

  this->time_available = true;
  if (this->time_update_callback != nullptr) {
    this->time_update_callback();
  }
}

/***************************************************************************//**
 * Marks timezone as available and invokes the user timezone callback if set.
 * Invoked by the Time Synchronization cluster delegate when the TZ list changes.
 ******************************************************************************/
void MatterTimeSynchronization::notify_timezone_update()
{
  this->timezone_available = true;
  if (this->timezone_update_callback != nullptr) {
    this->timezone_update_callback();
  }
}
