/*
   ArduinoLowPower deep sleep example with retained pin state

   The example shows how to retain a GPIO state during deep sleep and after wake-up.
   The specified pin is configured and its state is retained before entering deep sleep,
   then automatically restored before the sketch starts again after waking up.

   During deep sleep the whole device is powered down except for a minimal set of peripherals (like the Back-up RAM and RTC).
   This means that the CPU is stopped and the RAM contents are lost.
   The device will start from the beginning of the sketch after waking up.

   In this sketch the on-board LED's state is retained during deep sleep and after wake up.
   Without retention the LED would turn off during deep sleep.

   This example is compatible with all Silicon Labs Arduino boards.

   Author: Tamas Jozsi (Silicon Labs)
 */

#include "ArduinoLowPower.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("Deep sleep retained pin example");
}

void loop()
{
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
  LowPower.deepSleepRetainPin(LED_BUILTIN, OUTPUT, (PinStatus)LED_BUILTIN_ACTIVE);
  Serial.printf("Going to deep sleep for 10s at %lu\n", millis());
  LowPower.deepSleep(10000);
}
