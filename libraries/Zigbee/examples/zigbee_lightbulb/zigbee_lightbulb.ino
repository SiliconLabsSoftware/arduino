/*
   Zigbee lightbulb example

   The example shows how to create a simple on/off lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard LED through Zigbee.
   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.

   Compatible boards:
   - Arduino Nano Matter (with Zigbee protocol stack selected)

   Author: Silicon Labs
 */
#include <Zigbee.h>
#include <ZigbeeLightbulb.h>

ZigbeeLightbulb zigbee_bulb;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
  pinMode(button_pin, INPUT_PULLUP);

  Zigbee.begin();
  zigbee_bulb.begin();

  Serial.println("Zigbee lightbulb");
  Serial.println("Waiting for Zigbee network...");
}

void loop()
{
  static bool last_state = false;
  static bool btn_last = true;
  static bool joined = false;

  if (!joined && Zigbee.isJoinedToNetwork()) {
    joined = true;
    Serial.println("Joined Zigbee network!");
    Serial.print("Channel: ");
    Serial.println(Zigbee.getChannel());
    Serial.print("PAN ID: 0x");
    Serial.println(Zigbee.getPanId(), HEX);
  }

  // Handle on/off state changes from the network
  bool current_state = zigbee_bulb.get_onoff();
  if (current_state != last_state) {
    last_state = current_state;
    digitalWrite(LED_BUILTIN, current_state ? LED_BUILTIN_ACTIVE : LED_BUILTIN_INACTIVE);
    Serial.print("Bulb state: ");
    Serial.println(current_state ? "ON" : "OFF");
  }

  // Toggle the bulb with the button
  bool btn_state = digitalRead(button_pin);
  if (!btn_state && btn_last) {
    zigbee_bulb.toggle();
  }
  btn_last = btn_state;

  delay(50);
}
