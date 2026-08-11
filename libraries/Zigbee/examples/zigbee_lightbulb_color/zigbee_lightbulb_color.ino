/*
   Zigbee color lightbulb example

   The example shows how to create a color lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard LED(s) through Zigbee.
   The LED can be switched on/off, dimmed, and recolored on boards with an RGB LED from a Zigbee coordinator.
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

ZigbeeColorLightbulb zigbee_bulb;
const uint8_t button_pin = BTN_BUILTIN;

void led_off();
void init_rgb_led();
void update_rgb_led();

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee color lightbulb");

  init_rgb_led();
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

  Zigbee.setVendorName("Silicon Labs");
  Zigbee.setProductName("Zigbee Color Lightbulb");
  Zigbee.setFirmwareVersion(0x00000072);
  Zigbee.begin();
  zigbee_bulb.begin();

  if (!Zigbee.isPaired()) {
    Serial.println("Device is not commissioned");
    Serial.println("Please pair it to your Zigbee Coordinator");
    zigbee_bulb.set_onoff(true);
    zigbee_bulb.set_brightness_percent(100);
    zigbee_bulb.set_saturation_percent(100);
    zigbee_bulb.set_true_hue(0);
    zigbee_bulb.set_rgb(255, 255, 255);
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
  static uint8_t brightness_prev = zigbee_bulb.get_brightness_percent();
  uint8_t hue_current = zigbee_bulb.get_hue();
  uint8_t saturation_current = zigbee_bulb.get_saturation_percent();
  uint8_t brightness_current = zigbee_bulb.get_brightness_percent();

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
    analogWrite(LED_BUILTIN, 255);
    #ifdef LED_BUILTIN_1
    analogWrite(LED_BUILTIN_1, 255);
    #endif
    #ifdef LED_BUILTIN_2
    analogWrite(LED_BUILTIN_2, 255);
    #endif
  } else {
    analogWrite(LED_BUILTIN, 0);
    #ifdef LED_BUILTIN_1
    analogWrite(LED_BUILTIN_1, 0);
    #endif
    #ifdef LED_BUILTIN_2
    analogWrite(LED_BUILTIN_2, 0);
    #endif
  }
}

void init_rgb_led()
{
  pinMode(LED_BUILTIN, OUTPUT); // Red channel
  // Some boards don't have an RGB LED - we skip the remaining channels in that case
  #ifdef LED_BUILTIN_1
  pinMode(LED_BUILTIN_1, OUTPUT); // Green channel
  #endif
  #ifdef LED_BUILTIN_2
  pinMode(LED_BUILTIN_2, OUTPUT); // Blue channel
  #endif
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
    analogWrite(LED_BUILTIN, 255 - r);
    #ifdef LED_BUILTIN_1
    analogWrite(LED_BUILTIN_1, 255 - g);
    #endif
    #ifdef LED_BUILTIN_2
    analogWrite(LED_BUILTIN_2, 255 - b);
    #endif
  } else {
    analogWrite(LED_BUILTIN, r);
    #ifdef LED_BUILTIN_1
    analogWrite(LED_BUILTIN_1, g);
    #endif
    #ifdef LED_BUILTIN_2
    analogWrite(LED_BUILTIN_2, b);
    #endif
  }
}
