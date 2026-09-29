/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2024 Silicon Laboratories Inc. www.silabs.com
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

#if defined(ARDUINO_SILABS)

#include "ArduinoLowPower.h"
extern "C" {
  #include "em_burtc.h"
  #include "em_emu.h"
  #include "sl_power_manager.h"
}

static uint32_t GetEm4WakeUpPinMask(GPIO_Port_TypeDef port, uint32_t pin);

ArduinoLowPowerClass::ArduinoLowPowerClass() :
  wakeup_callback(nullptr),
  wakeup_pin(PIN_NAME_NC),
  wakeup_mode(FALLING),
  deep_sleep_hold_gpio(false),
  pin_retention_enabled(false),
  retained_pin_count(0u)
{
  ;
}

void ArduinoLowPowerClass::handleWakeup()
{
  if (this->wakeup_callback) {
    this->wakeup_callback();
  }
}

// EM1
void ArduinoLowPowerClass::idle()
{
  sl_power_manager_sleep();
  this->handleWakeup();
}

// EM1 - timed
void ArduinoLowPowerClass::idle(uint32_t millis)
{
  this->timedSleep(millis);
}

// EM2
void ArduinoLowPowerClass::sleep()
{
  Serial.suspend();
  #if (NUM_HW_SERIAL > 1)
  Serial1.suspend();
  #endif

  sl_power_manager_sleep();
  this->handleWakeup();

  Serial.resume();
  #if (NUM_HW_SERIAL > 1)
  Serial1.resume();
  #endif
}

// EM2 - timed
void ArduinoLowPowerClass::sleep(uint32_t millis)
{
  Serial.suspend();
  #if (NUM_HW_SERIAL > 1)
  Serial1.suspend();
  #endif

  this->timedSleep(millis);

  Serial.resume();
  #if (NUM_HW_SERIAL > 1)
  Serial1.resume();
  #endif
}

// EM4 - GPIO wakeup
void ArduinoLowPowerClass::deepSleep()
{
  EMU_EM4Init_TypeDef em4_init = EMU_EM4INIT_DEFAULT;
  if (this->pin_retention_enabled) {
    em4_init.pinRetentionMode = emuPinRetentionLatch;
  } else if (this->deep_sleep_hold_gpio) {
    em4_init.pinRetentionMode = emuPinRetentionEm4Exit;
  }
  EMU_EM4Init(&em4_init);

  this->readAndApplyDeepSleepRetainedPins();
  this->setupDeepSleepWakeUpPin();
  this->armDeepSleepPinRetention();
  EMU_EnterEM4();
}

// EM4 - BURTC wakeup - the device will also wake up on GPIO interrupt if configured
void ArduinoLowPowerClass::deepSleep(uint32_t millis)
{
  CMU_ClockSelectSet(cmuClock_EM4GRPACLK, cmuSelect_ULFRCO);
  CMU_ClockEnable(cmuClock_BURTC, true);
  CMU_ClockEnable(cmuClock_BURAM, true);

  BURTC_Init_TypeDef burtcInit = BURTC_INIT_DEFAULT;
  burtcInit.compare0Top = true; // Reset counter when counter reaches compare value
  burtcInit.em4comp = true;     // BURTC compare interrupt wakes from EM4 (causes reset)
  BURTC_Init(&burtcInit);

  BURTC_CounterReset();
  BURTC_CompareSet(0, millis);

  BURTC_IntEnable(BURTC_IEN_COMP);    // Compare match
  NVIC_EnableIRQ(BURTC_IRQn);
  BURTC_Enable(true);

  EMU_EM4Init_TypeDef em4_init = EMU_EM4INIT_DEFAULT;
  if (this->pin_retention_enabled) {
    em4_init.pinRetentionMode = emuPinRetentionLatch;
  } else if (this->deep_sleep_hold_gpio) {
    em4_init.pinRetentionMode = emuPinRetentionEm4Exit;
  }
  EMU_EM4Init(&em4_init);

  this->readAndApplyDeepSleepRetainedPins();
  this->setupDeepSleepWakeUpPin();
  this->armDeepSleepPinRetention();
  EMU_EnterEM4();
}

void ArduinoLowPowerClass::attachInterruptWakeup(uint32_t pin, voidFuncPtr callback, irq_mode mode)
{
  this->wakeup_callback = callback;
  this->wakeup_pin = pin;
  this->wakeup_mode = mode;
}

void ArduinoLowPowerClass::timedSleep(uint32_t millis_to_sleep)
{
  delay(millis_to_sleep);
  this->handleWakeup();
}

// Writes 4 bytes to the specified Backup RAM address which is retained during deep sleep
void ArduinoLowPowerClass::deepSleepMemoryWrite(uint32_t address, uint32_t data)
{
  if (this->pin_retention_enabled && this->isDeepSleepPinRetentionAddress(address)) {
    return;
  }
  this->deepSleepMemoryWriteRaw(address, data);
}

// Reads 4 bytes from the specified Backup RAM address
uint32_t ArduinoLowPowerClass::deepSleepMemoryRead(uint32_t address)
{
  if (this->pin_retention_enabled && this->isDeepSleepPinRetentionAddress(address)) {
    return 0u;
  }
  return this->deepSleepMemoryReadRaw(address);
}

// Returns whether the device was reset by deep sleeping or by an other cause
bool ArduinoLowPowerClass::wokeUpFromDeepSleep()
{
  return (get_system_reset_cause() & EMU_RSTCAUSE_EM4);
}

// Configures the specified pin to wake up the device from EM4
void ArduinoLowPowerClass::setupDeepSleepWakeUpPin()
{
  if (this->wakeup_pin == PIN_NAME_NC) {
    return;
  }
  GPIO_Port_TypeDef wakeup_interrupt_port = getSilabsPortFromArduinoPin(pinToPinName(wakeup_pin));
  uint32_t wakeup_interrupt_pin = getSilabsPinFromArduinoPin(pinToPinName(wakeup_pin));
  GPIO_PinModeSet(wakeup_interrupt_port, wakeup_interrupt_pin, gpioModeInputPullFilter, 1);
  uint32_t wakeup_pin_mask = GetEm4WakeUpPinMask(wakeup_interrupt_port, wakeup_interrupt_pin);

  // LOW/FALLING by default
  uint32_t polarity_mask = 0u;
  if (wakeup_mode == RISING || wakeup_mode == HIGH) {
    polarity_mask = __UINT32_MAX__ & _GPIO_EM4WUPOL_MASK;
  }
  GPIO_EM4EnablePinWakeup(wakeup_pin_mask, polarity_mask);
}

// Holds GPIO states during deep sleep, but resets them upon wakeup
// Use deepSleepRetainPin to configure GPIO pins to retain after deep sleep
void ArduinoLowPowerClass::deepSleepHoldPins(bool hold)
{
  this->deep_sleep_hold_gpio = hold;
}

// Retains the specified pin and state during deep sleep and after waking up
bool ArduinoLowPowerClass::deepSleepRetainPin(pin_size_t pinNumber, PinMode mode, PinStatus status)
{
  PinName pin_name = pinToPinName(pinNumber);
  if (pin_name == PIN_NAME_NC) {
    return false;
  }
  return this->deepSleepRetainPin(pin_name, mode, status);
}

// Retains the specified pin and state during deep sleep and after waking up
bool ArduinoLowPowerClass::deepSleepRetainPin(PinName pin, PinMode mode, PinStatus status)
{
  if (!this->isValidDeepSleepRetainedPin(pin, mode, status)) {
    return false;
  }

  if (this->retained_pin_count >= this->retained_pin_count_max) {
    return false;
  }
  this->retained_pin_count++;
  this->pin_retention_enabled = true;

  // Keep the retention header disarmed until right before entering EM4
  deepSleepMemoryWriteRaw(this->deep_sleep_pin_retention_storage_offset, 0);
  uint32_t retained_pin_entry_offset = this->deep_sleep_pin_retention_storage_offset + 1u + (this->retained_pin_count - 1u) * this->retained_pin_entry_size;
  deepSleepMemoryWriteRaw(retained_pin_entry_offset + 0, pin);
  deepSleepMemoryWriteRaw(retained_pin_entry_offset + 1, mode);
  deepSleepMemoryWriteRaw(retained_pin_entry_offset + 2, status);

  return true;
}

void ArduinoLowPowerClass::deepSleepClearRetainedPins()
{
  this->pin_retention_enabled = false;
  this->retained_pin_count = 0u;
  deepSleepMemoryWriteRaw(this->deep_sleep_pin_retention_storage_offset, 0);
}

bool ArduinoLowPowerClass::readDeepSleepPinRetentionCount(uint32_t* count)
{
  // Read the number of retained pins from the pin retention header
  uint32_t retained_pin_header = deepSleepMemoryReadRaw(this->deep_sleep_pin_retention_storage_offset);
  this->retained_pin_count = retained_pin_header & deep_sleep_pin_retention_count_mask;
  // The pin count read from deep sleep memory should be in the valid retained pin count range.
  // If it isn't, unlatch GPIO then return without restoring anything.
  if (this->retained_pin_count == 0u || this->retained_pin_count > this->retained_pin_count_max) {
    return false;
  }
  *count = this->retained_pin_count;
  return true;
}

bool ArduinoLowPowerClass::readAndApplyDeepSleepRetainedPins()
{
  if (!this->pin_retention_enabled || this->retained_pin_count == 0u) {
    return false;
  }
  PinName retained_pins[retained_pin_count_max];
  PinMode retained_modes[retained_pin_count_max];
  PinStatus retained_statuses[retained_pin_count_max];

  // Read and validate each retained pin entry from deep sleep memory
  for (uint32_t i = 0; i < this->retained_pin_count; i++) {
    uint32_t retained_pin_entry_offset = this->deep_sleep_pin_retention_storage_offset + 1u + i * this->retained_pin_entry_size;
    PinName pin = (PinName)deepSleepMemoryReadRaw(retained_pin_entry_offset + 0);
    PinMode mode = (PinMode)deepSleepMemoryReadRaw(retained_pin_entry_offset + 1);
    PinStatus status = (PinStatus)deepSleepMemoryReadRaw(retained_pin_entry_offset + 2);
    if (!this->isValidDeepSleepRetainedPin(pin, mode, status)) {
      return false;
    }
    retained_pins[i] = pin;
    retained_modes[i] = mode;
    retained_statuses[i] = status;
  }

  // Apply the retained pin configurations to the actual GPIO pins
  for (uint32_t i = 0; i < this->retained_pin_count; i++) {
    pinMode(retained_pins[i], retained_modes[i]);
    digitalWrite(retained_pins[i], retained_statuses[i]);
  }
  return true;
}

void ArduinoLowPowerClass::_restoreDeepSleepRetainedPins()
{
  // Check EM4 IO retention is active
  if ((EMU->STATUS & EMU_STATUS_EM4IORET) == 0u) {
    return;
  }

  // Read and validate the pin retention marker
  uint32_t retained_pin_header = deepSleepMemoryReadRaw(this->deep_sleep_pin_retention_storage_offset);
  this->pin_retention_enabled = ((retained_pin_header & deep_sleep_pin_retention_marker_mask) == deep_sleep_pin_retention_marker);
  if (!this->pin_retention_enabled) {
    EMU_UnlatchPinRetention();
    return;
  }

  // Read the number of retained pins from the pin retention header and validate it
  bool res = this->readDeepSleepPinRetentionCount(&this->retained_pin_count);
  if (!res) {
    this->deepSleepClearRetainedPins();
    EMU_UnlatchPinRetention();
    return;
  }

  // Read and apply the retained pin configurations from deep sleep memory
  res = this->readAndApplyDeepSleepRetainedPins();
  if (!res) {
    this->deepSleepClearRetainedPins();
    EMU_UnlatchPinRetention();
    return;
  }

  // Clear the retained pin entries from deep sleep memory and unlatch pin retention
  this->deepSleepClearRetainedPins();
  EMU_UnlatchPinRetention();
}

void ArduinoLowPowerClass::armDeepSleepPinRetention()
{
  if (!this->pin_retention_enabled || this->retained_pin_count == 0u || this->retained_pin_count > this->retained_pin_count_max) {
    return;
  }

  // The retention marker has 0xA595 on the top 16 bits and the retained pin count on the lower 16 bits
  uint32_t retained_pin_header = deep_sleep_pin_retention_marker | (this->retained_pin_count & deep_sleep_pin_retention_count_mask);
  deepSleepMemoryWriteRaw(this->deep_sleep_pin_retention_storage_offset, retained_pin_header);
}

void ArduinoLowPowerClass::deepSleepMemoryWriteRaw(uint32_t address, uint32_t data)
{
  if (address >= this->deep_sleep_memory_size) {
    return;
  }
  CMU_ClockEnable(cmuClock_BURAM, true);
  BURAM->RET[address].REG = data;
}

uint32_t ArduinoLowPowerClass::deepSleepMemoryReadRaw(uint32_t address)
{
  if (address >= this->deep_sleep_memory_size) {
    return 0u;
  }
  CMU_ClockEnable(cmuClock_BURAM, true);
  return BURAM->RET[address].REG;
}

bool ArduinoLowPowerClass::isDeepSleepPinRetentionAddress(uint32_t address)
{
  return (address >= this->deep_sleep_pin_retention_storage_offset) && (address < this->deep_sleep_memory_size);
}

bool ArduinoLowPowerClass::isValidDeepSleepRetainedPin(PinName pin, PinMode mode, PinStatus status)
{
  return (pin >= PIN_NAME_MIN) && (pin < PIN_NAME_MAX) && (mode == OUTPUT) && (status == LOW || status == HIGH);
}

ArduinoLowPowerClass LowPower;

// Get EM4 wakeup pin mask for a provided port and pin - note that not all pins can wake up the MCU from EM4
// If the provided pin is not a wakeup pin, the device won't be able to wake up from EM4 - only with a reset
static uint32_t GetEm4WakeUpPinMask(GPIO_Port_TypeDef port, uint32_t pin)
{
  uint32_t wakeup_pin_mask = 0u;
  if (GPIO_EM4WU0_PORT == port && GPIO_EM4WU0_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN0;
  } else if (GPIO_EM4WU3_PORT == port && GPIO_EM4WU3_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN3;
  }
#if defined(GPIO_EM4WU4_PORT) && defined(GPIO_EM4WU4_PIN)
  else if (GPIO_EM4WU4_PORT == port && GPIO_EM4WU4_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN4;
  }
#endif
  else if (GPIO_EM4WU6_PORT == port && GPIO_EM4WU6_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN6;
  } else if (GPIO_EM4WU7_PORT == port && GPIO_EM4WU7_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN7;
  } else if (GPIO_EM4WU8_PORT == port && GPIO_EM4WU8_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN8;
  } else if (GPIO_EM4WU9_PORT == port && GPIO_EM4WU9_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN9;
  }
#if defined(GPIO_EM4WU10_PORT) && defined(GPIO_EM4WU10_PIN)
  else if (GPIO_EM4WU10_PORT == port && GPIO_EM4WU10_PIN == pin) {
    wakeup_pin_mask = GPIO_IEN_EM4WUIEN10;
  }
#endif
  return wakeup_pin_mask;
}

void BURTC_IRQHandler(void)
{
  BURTC_IntClear(BURTC_IF_COMP); // Compare match
}

// Overrides the WEAK escapeHatch() function in main.cpp to provide a way to prevent
// the device from going to EM4 too quickly. If the device enters EM4 sleep the programmer
// is not able to communicate with it - and without this mechanism it can easily be bricked.
// This function will run before any user code and keep the device awake when the built-in button
// (or the configured escape pin) is pressed during startup so that the programmer has a chance to
// communicate with it.
void escape_hatch()
{
  if (LowPower.wokeUpFromDeepSleep()) {
    LowPower._restoreDeepSleepRetainedPins();
  }

  pinMode(DEEP_SLEEP_ESCAPE_PIN, INPUT_PULLUP);
  if (digitalRead(DEEP_SLEEP_ESCAPE_PIN) != LOW) {
    return;
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
  while (1) {
    ;
  }
}

#endif // ARDUINO_SILABS
