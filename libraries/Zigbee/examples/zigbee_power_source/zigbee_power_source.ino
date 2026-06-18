/*
   Zigbee power source example

   The example shows how to create a standalone Zigbee power source endpoint
   with the Arduino Zigbee API.

   The example publishes simulated battery percentage data through the Zigbee
   Power Configuration cluster. This lets battery-powered sketches opt in to a
   battery entity without baking battery support into every sensor type.

   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.

   Compatible boards:
   - Arduino Nano Matter

   Author: Tamas Jozsi (Silicon Labs)
 */
#include <Zigbee.h>
#include <ZigbeePowerSource.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeePowerSource zigbee_power_source;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee power source");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
  pinMode(button_pin, INPUT_PULLUP);

  // Hold the button during boot to factory reset (clear stored network credentials)
  if (digitalRead(button_pin) == LOW) {
    Serial.println("Factory resetting...");
    Serial.println("Release the button to reboot");
    while (digitalRead(button_pin) == LOW) {
      delay(100);
    }
    Zigbee.factoryReset();
  }

  Zigbee.setVendorName("Arduino");
  Zigbee.setProductName("Zigbee Power Source");
  Zigbee.setFirmwareVersion(0x00000420);
  Zigbee.setDeviceType(ZIGBEE_DEVICE_TYPE_END_DEVICE);
  Zigbee.setPowerSource(ZIGBEE_POWER_SOURCE_TYPE_BATTERY);
  Zigbee.begin();
  zigbee_power_source.begin();

  if (!Zigbee.isPaired()) {
    Serial.println("Device is not commissioned");
    Serial.println("Waiting to join a Zigbee network...");
  }
  while (!Zigbee.isPaired()) {
    delay(200);
  }

  Serial.println("Connecting to Zigbee network...");
  while (!Zigbee.isConnectedToNetwork()) {
    delay(200);
  }
  Serial.print("Connected to Zigbee network; ");
  Serial.print("Channel: ");
  Serial.print(Zigbee.getChannel());
  Serial.print(" | PAN ID: 0x");
  Serial.println(Zigbee.getPanId(), HEX);

  // Report the battery percent as fast as possible or at max 2 seconds
  zigbee_power_source.set_reporting_interval(0, 2);
}

void loop()
{
  static uint8_t battery_percent = 100u;
  static uint32_t last_update = 0;

  if ((last_update + 5000u) < millis()) {
    last_update = millis();
    zigbee_power_source.set_battery_percent(battery_percent);
    Serial.printf("Battery percent remaining: %u%%\n", battery_percent);

    // Turn on the LED as a low battery warning below 20%
    if (battery_percent < 20u) {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    } else {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    }

    if (battery_percent > 0u) {
      battery_percent -= 5u;
    } else {
      battery_percent = 100u;
    }
  }
}
