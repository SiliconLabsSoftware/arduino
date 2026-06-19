/*
   Zigbee dimmable lightbulb example

   The example shows how to create a dimmable lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard LED through Zigbee.
   The LED can be switched on/off and dimmed from a Zigbee coordinator.
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
#include <ZigbeeDimmableLightbulb.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeDimmableLightbulb zigbee_bulb;
const uint8_t button_pin = BTN_BUILTIN;

void updateOnboardLed(uint8_t brightness_percent)
{
  uint8_t pwm_brightness = (static_cast<uint16_t>(brightness_percent) * 255 + 50) / 100;
  if (LED_BUILTIN_ACTIVE == LOW) {
    analogWrite(LED_BUILTIN, 255 - pwm_brightness);
  } else {
    analogWrite(LED_BUILTIN, pwm_brightness);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee dimmable lightbulb");

  pinMode(LED_BUILTIN, OUTPUT);
  updateOnboardLed(0);
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
  Zigbee.setProductName("Zigbee Dimmable Lightbulb");
  Zigbee.setFirmwareVersion(0x00000071);
  Zigbee.begin();
  zigbee_bulb.begin();
  zigbee_bulb.set_brightness_percent(100);

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

  // Handle on/off state changes from the network
  static bool bulb_prev_state = false;
  bool bulb_current_state = zigbee_bulb.get_onoff();
  if (bulb_current_state && !bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    Serial.print("Bulb ON, brightness: ");
    Serial.print(zigbee_bulb.get_brightness_percent());
    Serial.println("%");
    updateOnboardLed(zigbee_bulb.get_brightness_percent());
  }
  if (!bulb_current_state && bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    updateOnboardLed(0);
    Serial.println("Bulb OFF");
  }

  // Handle brightness changes from the network
  static uint8_t brightness_prev = zigbee_bulb.get_brightness_percent();
  uint8_t brightness_current = zigbee_bulb.get_brightness_percent();
  if (brightness_current != brightness_prev) {
    brightness_prev = brightness_current;
    if (bulb_current_state) {
      updateOnboardLed(brightness_current);
    }
    Serial.print("Bulb brightness changed to ");
    Serial.print(brightness_current);
    Serial.println("%");
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
