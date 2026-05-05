/*
   Zigbee on/off switch example

   The example shows how to create a Zigbee switch that can control a lightbulb.

   The example creates a Zigbee on/off switch device. When the button is pressed, it sends a
   toggle command to all bound lightbulb devices.
   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.
   After pairing, create a binding from this switch's On/Off cluster to the target lightbulb.

   Compatible boards:
   - Arduino Nano Matter (with Zigbee protocol stack selected)

   Author: Silicon Labs
 */
#include <Zigbee.h>
#include <ZigbeeSwitch.h>

ZigbeeSwitch zigbee_switch;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);

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
  Zigbee.setProductName("Nano Zigbee");
  Zigbee.begin();
  zigbee_switch.begin();

  Serial.println("Zigbee on/off switch");
  Serial.println("Waiting for Zigbee network...");
}

void loop()
{
  static bool joined = false;
  static bool last_button_state = HIGH;

  if (!joined && Zigbee.isJoinedToNetwork()) {
    joined = true;
    Serial.println("Joined Zigbee network!");
    Serial.print("Channel: ");
    Serial.println(Zigbee.getChannel());
    Serial.print("PAN ID: 0x");
    Serial.println(Zigbee.getPanId(), HEX);
    Serial.println("Press the button to toggle bound lights");
  }

  if (joined) {
    bool button_state = digitalRead(button_pin);
    if (last_button_state == HIGH && button_state == LOW) {
      Serial.println("Sending toggle command to bound lights...");
      zigbee_switch.toggle();
      digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
      delay(100);
      digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    }
    last_button_state = button_state;
  }

  delay(50);
}
