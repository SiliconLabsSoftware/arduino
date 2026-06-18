/*
   Zigbee end device thermometer example

   The example shows how to create a Zigbee temperature sensor that joins the
   network as an end device instead of a router.

   The example creates a Zigbee temperature sensor device and publishes the
   current CPU temperature through it. The device has to be commissioned to a
   Zigbee network first. Open your Zigbee coordinator (e.g. Home Assistant with
   ZHA) and put it in pairing mode.

   Compatible boards:
   - Arduino Nano Matter
   - Silicon Labs xG24 Explorer Kit
   - SparkFun Thing Plus Matter
   - Seeed Studio XIAO MG24 (Sense)

   Author: Tamas Jozsi (Silicon Labs)
 */
#include <Zigbee.h>
#include <ZigbeeTemperatureSensor.h>
#include <ArduinoLowPower.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeTemperatureSensor zigbee_temp_sensor;
const uint8_t button_pin = BTN_BUILTIN;

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee end device thermometer");

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
  Zigbee.setProductName("Zigbee End Device Thermometer");
  Zigbee.setFirmwareVersion(0x00000420);
  Zigbee.setDeviceType(ZIGBEE_DEVICE_TYPE_END_DEVICE);
  Zigbee.begin();
  zigbee_temp_sensor.begin();

  Serial.println("Waiting for Zigbee network...");
  while (!Zigbee.isJoinedToNetwork()) {
    delay(200);
  }
  Serial.println("Joined Zigbee network as end device!");
  Serial.print("Channel: ");
  Serial.println(Zigbee.getChannel());
  Serial.print("PAN ID: 0x");
  Serial.println(Zigbee.getPanId(), HEX);
}

void loop()
{
  // Take a temperature measurement
  float current_cpu_temp = getCPUTemp();
  zigbee_temp_sensor.set_measured_value_celsius(current_cpu_temp);
  Serial.printf("Current CPU temperature: %.02f C\n", current_cpu_temp);

  // Send the measurement immediately
  zigbee_temp_sensor.send_attribute_report();
  uint32_t report_send_check_count = 0u;
  bool report_sent = true;
  while(!zigbee_temp_sensor.get_attribute_report_sent()) {
    report_send_check_count++;
    delay(100);
    // If the report is not sent after 5 seconds, print a message and stop checking
    if (report_send_check_count == 50) {
      Serial.println("Failed to send report");
      report_sent = false;
      break;
    }
  }

  if (report_sent) {
    Serial.println("Report sent successfully");
  }

  // Send the device to sleep for 10 seconds
  Serial.println("Going to sleep for 10 seconds...");
  LowPower.sleep(10000);
}
