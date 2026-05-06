/*
   Zigbee lightbulb with identify example

   The example shows how to create a simple on/off lightbulb with the Arduino Zigbee API.

   The example lets users control the onboard LED through Zigbee.
   The lightbulb will also respond to identification requests by blinking the LED.
   The device has to be commissioned to a Zigbee network first.
   The lightbulb will also respond to identification requests by blinking the LED.
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
#define BTN_BUILTIN PA0
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

  static bool identification_in_progress_last = false;
  bool identification_in_progress = zigbee_bulb.get_identify_in_progress();
  // Handle the identification enable/disable transitions
  if (identification_in_progress && !identification_in_progress_last) {
    Serial.println("Identification started");
  } else if (!identification_in_progress && identification_in_progress_last) {
    // Set the LED to the current on/off state once the identification ends
    Serial.println("Identification ended");
    if(zigbee_bulb.get_onoff()) {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    } else {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    }
  }
  identification_in_progress_last = identification_in_progress;

  // Blink the LED while the identification is in progress
  if (identification_in_progress) {
    if (millis() % 1000 < 500) {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    } else {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    }
  }

  // Handle on/off state changes from the network
  static bool bulb_prev_state = false;
  bool bulb_current_state = zigbee_bulb.get_onoff();
  // If the current state is ON and the previous was OFF - turn on the LED
  if (bulb_current_state && !bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    if (!identification_in_progress) {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
    }
    Serial.println("Bulb ON");
  }
  // If the current state is OFF and the previous was ON - turn off the LED
  if (!bulb_current_state && bulb_prev_state) {
    bulb_prev_state = bulb_current_state;
    if (!identification_in_progress) {
      digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
    }
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
