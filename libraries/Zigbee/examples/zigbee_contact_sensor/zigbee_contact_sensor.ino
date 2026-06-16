/*
   Zigbee contact sensor example

   The example shows how to create a simple contact sensor with the Arduino Zigbee API.

   The example creates a Zigbee contact sensor device and publishes the on-board button's state through it.
   When the button is pressed the contact sensor will open the contact.
   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.

   Compatible boards:
   - Arduino Nano Matter
   - Silicon Labs xG24 Explorer Kit
   - SparkFun Thing Plus Matter
   - Seeed Studio XIAO MG24 (Sense)

   Author: Tamas Jozsi (Silicon Labs)
 */
#include <Zigbee.h>
#include <ZigbeeContact.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeContact zigbee_contact_sensor;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee contact sensor");

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
  Zigbee.setProductName("Zigbee Contact Sensor");
  Zigbee.setFirmwareVersion(0x00000069);
  Zigbee.begin();
  zigbee_contact_sensor.begin();
  zigbee_contact_sensor.set_closed();

  Serial.println("Waiting for Zigbee network...");
}

void loop()
{
  static bool joined = false;
  if (!joined && Zigbee.isJoinedToNetwork()) {
    joined = true;
    Serial.println("Joined Zigbee network!");
    Serial.print("Channel: ");
    Serial.println(Zigbee.getChannel());
    Serial.print("PAN ID: 0x");
    Serial.println(Zigbee.getPanId(), HEX);
  }

  static bool contact_open_prev = false;
  bool contact_open = zigbee_contact_sensor.is_open();
  if (contact_open && !contact_open_prev) {
    contact_open_prev = contact_open;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    Serial.println("Contact open");
  }
  if (!contact_open && contact_open_prev) {
    contact_open_prev = contact_open;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    Serial.println("Contact closed");
  }

  static bool button_prev_state = true;
  bool button_current_state = digitalRead(button_pin);
  if (button_current_state != button_prev_state) {
    button_prev_state = button_current_state;
    // Set the contact sensor to "open" when the button is pressed, "closed" when the button is released
    if (button_current_state == LOW) {
      zigbee_contact_sensor.set_open();
    } else {
      zigbee_contact_sensor.set_closed();
    }
  }

  delay(50);
}
