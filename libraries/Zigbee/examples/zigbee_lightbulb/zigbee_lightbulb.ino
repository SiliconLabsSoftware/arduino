/*
   Zigbee lightbulb example

   The example shows how to create a simple on/off lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard LED through Zigbee.
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
#include <ZigbeeLightbulb.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeLightbulb zigbee_bulb;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee lightbulb");

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
  Zigbee.setProductName("Zigbee Lightbulb");
  Zigbee.setFirmwareVersion(0x00000067);
  Zigbee.begin();
  zigbee_bulb.begin();

  if (!Zigbee.isPaired()) {
    Serial.println("Device is not commissioned");
    Serial.println("Please pair it to your Zigbee Coordinator");
    zigbee_bulb.set_onoff(true);
  }
}

void loop()
{
  static bool joined = false;
  if (!joined && Zigbee.isConnectedToNetwork()) {
    joined = true;
    Serial.print("Connected to Zigbee network; ");
    Serial.print("Channel: ");
    Serial.print(Zigbee.getChannel());
    Serial.print(" | PAN ID: 0x");
    Serial.println(Zigbee.getPanId(), HEX);
  }

  // Handle on/off state changes from the network
  static bool bulb_prev_state = false;
  bool bulb_current_state = zigbee_bulb.get_onoff();
  // If the current state is ON and the previous was OFF - turn on the LED
  if (bulb_current_state && !bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    Serial.println("Bulb ON");
  }
  // If the current state is OFF and the previous was ON - turn off the LED
  if (!bulb_current_state && bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    Serial.println("Bulb OFF");
  }

  // Toggle the bulb with the button - this even works when Zigbee is not connected
  static bool btn_last = true;
  bool btn_state = digitalRead(button_pin);
  if (!btn_state && btn_last) {
    zigbee_bulb.toggle();
  }
  btn_last = btn_state;

  delay(50);
}
