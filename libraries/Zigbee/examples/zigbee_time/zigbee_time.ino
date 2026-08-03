/*
   Zigbee time sync example

   The example shows how to request the current date and time from the Zigbee coordinator.

   The example creates a dedicated Time Client endpoint and reads the Time
   cluster from the coordinator.
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
#include <ZigbeeTimeClient.h>
#include <time.h>

// If there's no built-in button set a pin where a button is connected
#ifndef BTN_BUILTIN
#define BTN_BUILTIN D0
#endif

ZigbeeTimeClient zigbee_time;
const uint8_t button_pin = BTN_BUILTIN;

volatile bool zigbee_time_updated = false;

void print_date_time(const char* label, uint32_t unix_time);
void print_zigbee_time();

void on_zigbee_time_updated()
{
  zigbee_time_updated = true;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Zigbee time sync");

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

  Zigbee.setVendorName("Silicon Labs");
  Zigbee.setProductName("Zigbee time client");
  Zigbee.setFirmwareVersion(0x00000001);
  zigbee_time.set_time_update_callback(on_zigbee_time_updated);
  Zigbee.begin();
  zigbee_time.begin();

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

  zigbee_time.request_time();
}

void loop()
{
  static uint32_t last_time_request_ms = 0;
  if ((millis() - last_time_request_ms) > 10000) {
    zigbee_time.request_time();
    last_time_request_ms = millis();
  }

  if (zigbee_time_updated) {
    zigbee_time_updated = false;
    print_zigbee_time();
  }

  delay(50);
}

void print_date_time(const char* label, uint32_t unix_time)
{
  time_t timestamp = static_cast<time_t>(unix_time);
  tm* time_info = gmtime(&timestamp);
  char formatted_time[32];

  if (time_info == nullptr || strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", time_info) == 0) {
    return;
  }

  Serial.print(label);
  Serial.print(": ");
  Serial.println(formatted_time);
}

void print_zigbee_time()
{
  Serial.println("-------------------------------");
  Serial.print("Time status: 0x");
  Serial.println(zigbee_time.get_time_status(), HEX);
  Serial.print("Zigbee time: ");
  Serial.println(zigbee_time.get_zigbee_time());
  Serial.print("Unix time: ");
  Serial.println(zigbee_time.get_unix_time());
  print_date_time("UTC date/time", zigbee_time.get_unix_time());
  if (zigbee_time.has_timezone()) {
    Serial.print("Time zone offset: ");
    Serial.print(zigbee_time.get_timezone());
    Serial.println(" seconds");
  }
  Serial.print("Local Unix time: ");
  Serial.println(zigbee_time.get_local_unix_time());
  print_date_time("Local date/time", zigbee_time.get_local_unix_time());
}
