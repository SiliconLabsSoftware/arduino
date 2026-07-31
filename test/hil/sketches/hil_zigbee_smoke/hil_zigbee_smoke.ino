#include <Zigbee.h>
#include <ZigbeeLightbulb.h>

ZigbeeLightbulb zigbee_bulb;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);

  Zigbee.setVendorName("Arduino");
  Zigbee.setProductName("Zigbee Lightbulb");
  Zigbee.setFirmwareVersion(0x00000067);
  Zigbee.begin();
  zigbee_bulb.begin();

  Serial.println("Zigbee smoke test");

  zigbee_bulb.set_onoff(false);
  zigbee_bulb.set_onoff(true);
}

void loop()
{
  Serial.print("Zigbee smoke test running!");
  Serial.print(" uptime: ");
  Serial.println(millis());

  if (!Zigbee.isPaired()) {
    Serial.println("Zigbee device is not commissioned");
  }

  delay(1000);
}
