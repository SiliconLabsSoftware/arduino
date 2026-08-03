/*
   Zigbee dimmer switch example

   The example shows how to create a Zigbee switch that can control on/off and
   brightness on bound lightbulb devices.

   The device has to be commissioned to a Zigbee network first.
   Open your Zigbee coordinator (e.g. Home Assistant with ZHA) and put it in pairing mode.
   After pairing, create bindings from this switch's On/Off and Level Control
   client clusters to the target lightbulb.

   Compatible boards:
   - Arduino Nano Matter
   - Silicon Labs xG24 Explorer Kit
   - SparkFun Thing Plus Matter
   - Seeed Studio XIAO MG24 (Sense)

   Author: Tamas Jozsi (Silicon Labs)
 */
#include <Zigbee.h>
#include <ZigbeeSwitch.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeSwitch zigbee_switch;

const uint8_t dim_rate_percent = 50;
const uint32_t level_transition_time_ms = 1000;

void printCommands()
{
  Serial.println();
  Serial.println("Serial commands:");
  Serial.println("  o - on");
  Serial.println("  f - off");
  Serial.println("  t - toggle");
  Serial.println("  u - dim up");
  Serial.println("  d - dim down");
  Serial.println("  s - stop dimming");
  Serial.println("  0-9 - move to brightness percent");
  Serial.println();
}

uint8_t digitToPercent(char digit)
{
  uint8_t step = digit - '0';
  return (step * 100) / 9;
}

void handleSerialCommand(char command)
{
  if (command >= '0' && command <= '9') {
    uint8_t percent = digitToPercent(command);
    Serial.print("Moving to ");
    Serial.print(percent);
    Serial.println("%...");
    zigbee_switch.move_to_percent(percent, level_transition_time_ms);
    return;
  }

  switch (command) {
    case 'o':
    case 'O':
      Serial.println("Sending on command...");
      zigbee_switch.on();
      break;

    case 'f':
    case 'F':
      Serial.println("Sending off command...");
      zigbee_switch.off();
      break;

    case 't':
    case 'T':
      Serial.println("Sending toggle command...");
      zigbee_switch.toggle();
      break;

    case 'u':
    case 'U':
      Serial.println("Sending dim up command...");
      zigbee_switch.dim_up(dim_rate_percent);
      break;

    case 'd':
    case 'D':
      Serial.println("Sending dim down command...");
      zigbee_switch.dim_down(dim_rate_percent);
      break;

    case 's':
    case 'S':
      Serial.println("Sending stop dimming command...");
      zigbee_switch.stop_dimming();
      break;

    case '\n':
    case '\r':
      break;

    default:
      printCommands();
      break;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee dimmer switch");

  pinMode(BTN_BUILTIN, INPUT_PULLUP);
  if (digitalRead(BTN_BUILTIN) == LOW) {
    Serial.println("Factory resetting...");
    Serial.println("Release the button to reboot");
    while (digitalRead(BTN_BUILTIN) == LOW) {
      delay(100);
    }
    Zigbee.factoryReset();
  }

  Zigbee.setVendorName("Arduino");
  Zigbee.setProductName("Zigbee Dimmer Switch");
  Zigbee.setFirmwareVersion(0x00000070);
  Zigbee.begin();
  zigbee_switch.begin();

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

  printCommands();
}

void loop()
{
  while (Serial.available()) {
    handleSerialCommand(Serial.read());
  }
  delay(10);
}
