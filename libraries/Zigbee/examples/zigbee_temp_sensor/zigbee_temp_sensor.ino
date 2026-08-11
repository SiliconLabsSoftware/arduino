/*
   Zigbee temperature sensor example

   The example shows how to create a temperature sensor with the Arduino Zigbee API.

   The example creates a Zigbee temperature sensor device and publishes the current CPU temperature through it.
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
#include <ZigbeeTemperatureSensor.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeTemperatureSensor zigbee_temp_sensor;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee temperature sensor");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
  pinMode(button_pin, INPUT_PULLUP);

  // Hold the button during boot to factory reset (clear stored Zigbee network data)
  if (digitalRead(button_pin) == LOW) {
    Serial.println("Factory resetting...");
    Serial.println("Release the button to reboot");
    while (digitalRead(button_pin) == LOW) {
      delay(100);
    }
    Zigbee.factoryReset();
  }

  Zigbee.setVendorName("Arduino");
  Zigbee.setProductName("Zigbee Temperature Sensor");
  Zigbee.setFirmwareVersion(0x00000420);
  Zigbee.begin();
  zigbee_temp_sensor.begin();

  if (!Zigbee.isPaired()) {
    Serial.println("Device is not commissioned");
    Serial.println("Waiting to join a Zigbee network...");
  }
  while (!Zigbee.isPaired ()) {
    delay(200);
  }

  Serial.println("Connecting to Zigbee network...");
  while (!Zigbee.isConnectedToNetwork()) {
    delay(200);
  }
  Serial.print("Connected to Zigbee network; ");
  Serial.print("Channel: ");
  Serial.print(Zigbee.getChannel());
  Serial.print(" | PAN ID: 0x");
  Serial.println(Zigbee.getPanId(), HEX);
}

void loop()
{
  float current_cpu_temp = getCPUTemp();
  zigbee_temp_sensor.set_measured_value_celsius(current_cpu_temp);
  Serial.printf("Current CPU temperature: %.02f C\n", current_cpu_temp);
  delay(2000);
}
