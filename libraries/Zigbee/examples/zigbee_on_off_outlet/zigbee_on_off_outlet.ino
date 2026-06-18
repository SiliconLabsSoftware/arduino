/*
   Zigbee On/Off Plug-in Unit / Outlet example

   The example shows how to create a smart outlet with the Arduino Zigbee API.

   The example displays the outlet's state with the onboard LED.
   The example also lets users control the outlet locally with the built-in button.
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
#include <ZigbeeOnOffPluginUnit.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeOnOffPluginUnit zigbee_outlet;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee On/Off Plug-in Unit / Outlet");

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
  Zigbee.setProductName("Zigbee On/Off Plug-in Unit");
  Zigbee.setFirmwareVersion(0x00000068);
  Zigbee.begin();
  zigbee_outlet.begin();

  if (!Zigbee.isPaired()) {
    Serial.println("Device is not commissioned");
    Serial.println("Please pair it to your Zigbee Coordinator");
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

  static bool outlet_prev_state = false;
  bool outlet_current_state = zigbee_outlet.get_onoff();
  if (outlet_current_state && !outlet_prev_state) {
    outlet_prev_state = outlet_current_state;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    Serial.println("Outlet ON");
  }
  if (!outlet_current_state && outlet_prev_state) {
    outlet_prev_state = outlet_current_state;
    digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    Serial.println("Outlet OFF");
  }

  static bool btn_last = true;
  bool btn_state = digitalRead(button_pin);
  if (!btn_state && btn_last) {
    zigbee_outlet.toggle();
  }
  btn_last = btn_state;

  delay(50);
}
