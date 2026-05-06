/*
   Zigbee humidity sensor example

   The example shows how to create a humidity sensor with the Arduino Zigbee API.

   The example creates a Zigbee humidity sensor device and publishes a simulated humidity value through it.
   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.

   Compatible boards:
   - Arduino Nano Matter (with Zigbee protocol stack selected)

   Author: Tamas Jozsi (Silicon Labs)
 */
#include <Zigbee.h>
#include <ZigbeeHumiditySensor.h>

ZigbeeHumiditySensor zigbee_humidity_sensor;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee humidity sensor");

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
  Zigbee.setProductName("Zigbee Humidity Sensor");
  Zigbee.setFirmwareVersion(0x00000042);
  Zigbee.begin();
  zigbee_humidity_sensor.begin();

  Serial.println("Waiting for Zigbee network...");
  while (!Zigbee.isJoinedToNetwork()) {
    delay(200);
  }
  Serial.println("Joined Zigbee network!");
  Serial.print("Channel: ");
  Serial.println(Zigbee.getChannel());
  Serial.print("PAN ID: 0x");
  Serial.println(Zigbee.getPanId(), HEX);
}

void loop()
{
  // Simulate a humidity value (50% +/- 10% based on millis)
  float humidity = 50.0f + 10.0f * sin((float)millis() / 30000.0f);
  zigbee_humidity_sensor.set_measured_value_percent(humidity);
  Serial.printf("Current humidity: %.02f %%\n", humidity);
  delay(2000);
}
