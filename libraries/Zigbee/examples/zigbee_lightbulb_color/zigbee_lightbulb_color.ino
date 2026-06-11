/*
   Zigbee color lightbulb example for the Nano Matter

   The example shows how to create a color lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard RGB LED through Zigbee.
   The LED can be switched on/off, dimmed, and recolored from a Zigbee coordinator.
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
#include <ZigbeeColorLightbulb.h>

#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

#ifndef LED_BUILTIN_1
#define LED_BUILTIN_1 D1
#endif

#ifndef LED_BUILTIN_2
#define LED_BUILTIN_2 D2
#endif

#define LED_R LED_BUILTIN
#define LED_G LED_BUILTIN_1
#define LED_B LED_BUILTIN_2

ZigbeeColorLightbulb zigbee_bulb;
const uint8_t button_pin = BTN_BUILTIN;

void led_off();
void update_rgb_led();

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee color lightbulb");

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  led_off();
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
  Zigbee.setProductName("Zigbee Color Lightbulb");
  Zigbee.setFirmwareVersion(0x00000072);
  Zigbee.begin();
  zigbee_bulb.begin();
  zigbee_bulb.set_onoff(true);
  zigbee_bulb.set_brightness(100);
  zigbee_bulb.set_saturation_percent(100);
  zigbee_bulb.set_true_hue(0);
  zigbee_bulb.set_rgb(255, 255, 255);

  Serial.println("Waiting for Zigbee network...");
}

void loop()
{
  // Check if we joined to the network and print network information
  static bool joined = false;
  if (!joined && Zigbee.isJoinedToNetwork()) {
    joined = true;
    Serial.println("Joined Zigbee network!");
    Serial.print("Channel: ");
    Serial.println(Zigbee.getChannel());
    Serial.print("PAN ID: 0x");
    Serial.println(Zigbee.getPanId(), HEX);
  }

  static bool bulb_on_prev = false;
  bool bulb_on = zigbee_bulb.get_onoff();
  if (bulb_on && !bulb_on_prev) {
    bulb_on_prev = bulb_on;
    Serial.println("Bulb ON");
    update_rgb_led();
  }
  if (!bulb_on && bulb_on_prev) {
    bulb_on_prev = bulb_on;
    led_off();
    Serial.println("Bulb OFF");
  }

  static uint8_t hue_prev = zigbee_bulb.get_hue();
  static uint8_t saturation_prev = zigbee_bulb.get_saturation_percent();
  static uint8_t brightness_prev = zigbee_bulb.get_brightness();
  uint8_t hue_current = zigbee_bulb.get_hue();
  uint8_t saturation_current = zigbee_bulb.get_saturation_percent();
  uint8_t brightness_current = zigbee_bulb.get_brightness();

  if (hue_current != hue_prev || saturation_current != saturation_prev || brightness_current != brightness_prev) {
    hue_prev = hue_current;
    saturation_prev = saturation_current;
    brightness_prev = brightness_current;

    if (bulb_on) {
      update_rgb_led();
    }
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

void led_off()
{
  if (LED_BUILTIN_ACTIVE == LOW) {
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, 255);
  } else {
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 0);
  }
}

void update_rgb_led()
{
  if (!zigbee_bulb.get_onoff()) {
    led_off();
    return;
  }

  uint8_t r;
  uint8_t g;
  uint8_t b;
  zigbee_bulb.get_rgb(&r, &g, &b);
  Serial.printf("Setting bulb color to > r: %u  g: %u  b: %u\n", r, g, b);

  if (LED_BUILTIN_ACTIVE == LOW) {
    analogWrite(LED_R, 255 - r);
    analogWrite(LED_G, 255 - g);
    analogWrite(LED_B, 255 - b);
  } else {
    analogWrite(LED_R, r);
    analogWrite(LED_G, g);
    analogWrite(LED_B, b);
  }
}
