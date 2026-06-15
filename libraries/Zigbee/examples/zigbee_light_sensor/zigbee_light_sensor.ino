/*
   Zigbee light sensor example

   The example shows how to create a light sensor with the Arduino Zigbee API.

   The example creates a Zigbee light sensor device and publishes a simulated illuminance value through it.
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
#include <ZigbeeLightSensor.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeLightSensor zigbee_light_sensor;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee light sensor");

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
  Zigbee.setProductName("Zigbee Light Sensor");
  Zigbee.setFirmwareVersion(0x00000043);
  Zigbee.begin();
  zigbee_light_sensor.begin();
  zigbee_light_sensor.set_min_value_lux(1.0f);
  zigbee_light_sensor.set_max_value_lux(100000.0f);
  zigbee_light_sensor.set_light_sensor_type(ZigbeeLightSensor::LIGHT_SENSOR_TYPE_CMOS);

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
  // Simulate an illuminance value (200 lx +/- 180 lx based on millis)
  float lux = 200.0f + 180.0f * sin((float)millis() / 30000.0f);
  zigbee_light_sensor.set_measured_value_lux(lux);
  Serial.printf("Current illuminance: %.02f lx\n", lux);
  delay(5000);
}
