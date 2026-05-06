# Arduino Zigbee Library

![Zigbee](../../doc/zigbee_logo.png)

The Zigbee library lets Arduino sketches create simple Zigbee 3.0 smart home
devices on Silicon Labs hardware. It wraps the Silicon Labs EmberZNet stack and
the generated Zigbee endpoint configuration with Arduino-style classes for
lights, switches, temperature sensors, and humidity sensors.

The library is intended for Silicon Labs based Arduino boards with the
Zigbee protocol stack selected.

## Supported Boards

- **Arduino Nano Matter**
- **Silicon Labs xG24 Explorer Kit**
- **SparkFun Thing Plus Matter**
- **Seeed Studio XIAO MG24 (Sense)**

Make sure `Tools > Protocol Stack > Zigbee` is selected in order to use the Zigbee library.
Sketches that include `Zigbee.h` intentionally fail to compile on non-Zigbee
board variants. If you see an error saying the selected board or variant is not
Zigbee compatible, select a board and protocol stack combination that supports
Zigbee.

## Included Examples

| Example | Description |
| --- | --- |
| `zigbee_lightbulb` | Creates an On/Off light controlled by a Zigbee coordinator. The onboard LED follows the Zigbee On/Off state. |
| `zigbee_lightbulb_identify` | Adds Identify cluster behavior to the lightbulb example. The onboard LED blinks while a coordinator is identifying the device. |
| `zigbee_switch` | Creates an On/Off switch that sends On, Off, and Toggle commands to bound lights. |
| `zigbee_temp_sensor` | Publishes the board CPU temperature through the Zigbee Temperature Measurement cluster. |
| `zigbee_humidity_sensor` | Publishes a simulated relative humidity value through the Zigbee Relative Humidity Measurement cluster. |

Open the examples from the Arduino IDE with **File > Examples > Zigbee**.

## Basic Flow

Every sketch follows the same shape:

1. Include `Zigbee.h` and the device class header you want to use.
2. Create one or more device objects globally.
3. Optionally set device metadata and pairing channel.
4. Call `Zigbee.begin()`.
5. Call `begin()` on each device object.
6. Put your Zigbee coordinator in pairing mode and wait for the device to join.

Minimal lightbulb:

```cpp
#include <Zigbee.h>
#include <ZigbeeLightbulb.h>

ZigbeeLightbulb bulb;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  Zigbee.setVendorName("Arduino");
  Zigbee.setProductName("Zigbee Lightbulb");
  Zigbee.setFirmwareVersion(0x00000001);

  Zigbee.begin();
  bulb.begin();
}

void loop()
{
  if (bulb.get_onoff()) {
    digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
  } else {
    digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
  }
  delay(50);
}
```

Call `Zigbee.begin()` before calling `begin()` on the device objects. The global
`Zigbee` object initializes the stack-side endpoint state, and each appliance
then allocates and enables its endpoint.

## Pairing and Network Steering

`Zigbee.begin()` starts Zigbee network steering if the device is not already on a
network. Network steering is the Zigbee joining procedure: the device scans for
open Zigbee networks, tries to join one, and stores the network credentials when
joining succeeds.

To pair a sketch:

1. Upload a Zigbee sketch to the board.
2. Open the Serial Monitor at the sketch's configured baud rate.
3. Put your coordinator, such as Home Assistant ZHA, in pairing or permit-join mode.
4. Wait for the sketch to print that it joined the network.

Network credentials are stored in non-volatile memory, so a paired board usually
rejoins automatically after reset or reflash.

### Restricting the Pairing Channel

By default, network steering can use Zigbee channels 11 through 26. You can
restrict pairing to one channel:

```cpp
Zigbee.setPairingChannel(15);
Zigbee.begin();
```

`setPairingChannel()` returns `true` for a valid Zigbee channel and `false` for
invalid channels. This only controls joining scans. It does not move an already
joined device to another network channel.

## Factory Reset

The examples support holding the built-in button during boot to factory reset:

```cpp
if (digitalRead(BTN_BUILTIN) == LOW) {
  Zigbee.factoryReset();
}
```

`factoryReset()` leaves the current network when joined, clears stored Zigbee and
NVM3 data, and resets the MCU. Use this when you want the board to forget its
network and pair again from a clean state.

If your coordinator still shows an old device entry after factory reset, remove
that stale entry from the coordinator before pairing again.

## Device Metadata

Set metadata before starting the device:

```cpp
Zigbee.setVendorName("Arduino");
Zigbee.setProductName("Zigbee Temperature Sensor");
Zigbee.setFirmwareVersion(0x00000420);
```

Available metadata APIs:

```cpp
void Zigbee.setVendorName(const char* name);
void Zigbee.setProductName(const char* name);
void Zigbee.setFirmwareVersion(const char* version);
void Zigbee.setFirmwareVersion(uint32_t file_version);
```

`setVendorName()` writes the Basic cluster Manufacturer Name attribute.
`setProductName()` writes the Basic cluster Model Identifier attribute.

The string firmware overload writes the Basic cluster SW Build ID attribute and
is limited to 16 characters. The numeric overload writes Basic Application
Version and OTA Current File Version attributes, which are the fields many
coordinators use for firmware display and OTA metadata. This library does not
implement a Zigbee OTA update server.

## Appliance Lifecycle

All Zigbee appliance classes inherit from a common base and provide:

```cpp
bool begin();
bool begin(uint8_t endpoint_id);
void end();
bool is_online();
bool get_identify_in_progress();
void set_device_name(const char* device_name);
void set_device_change_callback(void (*cb)(void));
```

`begin()` allocates, registers, and enables an endpoint. It returns `true` when
the appliance was created successfully.

`end()` unregisters the endpoint and frees the object resources.

`is_online()` returns whether the appliance has been marked online by the
library. In the current implementation this becomes true after the local endpoint
is created.

`get_identify_in_progress()` returns true while the Zigbee Identify cluster is
active for that endpoint.

`set_device_name()` is present on the appliance base class, but the current
Zigbee implementation does not publish a per-appliance name through this method.
Use `Zigbee.setVendorName()` and `Zigbee.setProductName()` for coordinator-visible
Basic cluster metadata.

`set_device_change_callback()` registers a no-argument callback called when the
device state changes, for example when an On/Off attribute changes, a sensor
measurement is written, or Identify starts/stops. Register the callback after the
appliance `begin()` call, because the underlying endpoint object is created
during `begin()`.

The generated endpoint configuration currently supports 12 dynamic endpoints:
three On/Off lights, three temperature sensors, three humidity sensors, and
three On/Off switches. Use the default `begin()` overload unless you specifically
need to bind to a known generated endpoint ID.

## Identifying a Device

Zigbee coordinators can send an Identify command to make a device physically
signal which device it is. The library tracks this state per endpoint:

```cpp
if (bulb.get_identify_in_progress()) {
  // Blink an LED, play a tone, or otherwise identify the device.
}
```

The `zigbee_lightbulb_identify` example blinks the onboard LED while Identify is
active, then restores the LED to the current light on/off state when Identify
ends.

## ZigbeeLightbulb

Header:

```cpp
#include <ZigbeeLightbulb.h>
```

Creates an On/Off Light endpoint. Remote On, Off, and Toggle commands update the
local state, and local calls update the Zigbee On/Off attribute.

API:

```cpp
bool begin();
bool begin(uint8_t endpoint_id);
void end();

void set_onoff(bool value);
bool get_onoff();
void toggle();

operator bool();
void operator=(bool state);
```

Example:

```cpp
ZigbeeLightbulb bulb;

void setup()
{
  Zigbee.begin();
  bulb.begin();
}

void loop()
{
  if (bulb.get_onoff()) {
    digitalWrite(LED_BUILTIN, LED_BUILTIN_ACTIVE);
  } else {
    digitalWrite(LED_BUILTIN, LED_BUILTIN_INACTIVE);
  }
}
```

You can also use the assignment and bool operators:

```cpp
bulb = true;

if (bulb) {
  // Bulb state is on.
}
```

## ZigbeeSwitch

Header:

```cpp
#include <ZigbeeSwitch.h>
```

Creates an On/Off Switch endpoint. The switch sends On, Off, or Toggle commands
to the coordinator and to configured bindings. After pairing, create a binding
from the switch's On/Off cluster to the target light in your coordinator.

API:

```cpp
bool begin();
bool begin(uint8_t endpoint_id);
void end();

void on();
void off();
void toggle();
```

Example:

```cpp
ZigbeeSwitch zigbee_switch;

void setup()
{
  pinMode(BTN_BUILTIN, INPUT_PULLUP);
  Zigbee.begin();
  zigbee_switch.begin();
}

void loop()
{
  static bool last_button_state = HIGH;
  bool button_state = digitalRead(BTN_BUILTIN);

  if (last_button_state == HIGH && button_state == LOW) {
    zigbee_switch.toggle();
  }

  last_button_state = button_state;
  delay(50);
}
```

## ZigbeeTemperatureSensor

Header:

```cpp
#include <ZigbeeTemperatureSensor.h>
```

Creates a Temperature Measurement endpoint.

Zigbee temperature values are represented as signed hundredths of a degree
Celsius. For example, `2350` means `23.50 C`. The convenience Celsius APIs do
the conversion for you.

API:

```cpp
bool begin();
bool begin(uint8_t endpoint_id);
void end();

void set_measured_value(int16_t value);
void set_measured_value_celsius(float celsius);
int16_t get_measured_value();
float get_measured_value_celsius();
void set_min_value(int16_t value);
void set_max_value(int16_t value);

operator float();
void operator=(float celsius);
```

Example:

```cpp
ZigbeeTemperatureSensor temperature;

void setup()
{
  Zigbee.begin();
  temperature.begin();
  temperature.set_min_value(-4000);  // -40.00 C
  temperature.set_max_value(12500);  // 125.00 C
}

void loop()
{
  temperature.set_measured_value_celsius(getCPUTemp());
  delay(2000);
}
```

## ZigbeeHumiditySensor

Header:

```cpp
#include <ZigbeeHumiditySensor.h>
```

Creates a Relative Humidity Measurement endpoint.

Zigbee humidity values are represented as unsigned hundredths of a percent. For
example, `5030` means `50.30%`. The convenience percent APIs do the conversion
for you.

API:

```cpp
bool begin();
bool begin(uint8_t endpoint_id);
void end();

void set_measured_value(uint16_t value);
void set_measured_value_percent(float percent);
uint16_t get_measured_value();
float get_measured_value_percent();
void set_min_value(uint16_t value);
void set_max_value(uint16_t value);

operator float();
void operator=(float percent);
```

Example:

```cpp
ZigbeeHumiditySensor humidity;

void setup()
{
  Zigbee.begin();
  humidity.begin();
  humidity.set_min_value(0);      // 0.00%
  humidity.set_max_value(10000);  // 100.00%
}

void loop()
{
  humidity.set_measured_value_percent(52.5f);
  delay(2000);
}
```

## Global Zigbee API

The global `Zigbee` object manages the Zigbee stack, network state, metadata, and
dynamic endpoint allocation.

```cpp
void begin();

void setVendorName(const char* name);
void setProductName(const char* name);
void setFirmwareVersion(const char* version);
void setFirmwareVersion(uint32_t file_version);
bool setPairingChannel(uint8_t channel);

bool isJoinedToNetwork();
uint8_t getChannel();
uint16_t getPanId();
uint16_t getNodeId();

void leaveNetwork();
void factoryReset();
```

Network status helpers:

- `isJoinedToNetwork()` returns whether the stack is joined to a Zigbee network.
- `getChannel()` returns the current radio channel.
- `getPanId()` returns the current PAN ID.
- `getNodeId()` returns the current Zigbee node ID.

Network management helpers:

- `leaveNetwork()` requests a Zigbee network leave when currently joined.
- `factoryReset()` leaves the network, erases stored network data, and resets.

## Home Assistant Notes

The examples are commonly tested with Home Assistant ZHA:

1. In Home Assistant, open **Settings > Devices & services > Zigbee Home Automation**.
2. Choose **Add device** to permit joining.
3. Reset or power the Arduino board running a Zigbee sketch.
4. Wait for the device to appear.

For the switch example, pairing only adds the switch device. To make it control a
light directly, add a Zigbee binding from the switch On/Off cluster to the target
light. The exact UI depends on your Home Assistant and ZHA version.

If a firmware, model, or manufacturer value does not update immediately after
you change a sketch, remove the old device from Home Assistant and pair it again,
or use the coordinator's reconfigure/read-attributes tools where available.

## Troubleshooting

### The sketch does not compile

Make sure the board is Arduino Nano Matter and the selected protocol stack is
Zigbee. Matter, BLE, and "None" protocol stack variants cannot compile sketches
that include `Zigbee.h`.

### The device does not appear in the coordinator

Check that the coordinator is in permit-join mode. If the board was paired to a
different network before, factory reset it by holding the built-in button during
boot in one of the examples, or call `Zigbee.factoryReset()` from your sketch.

If you restricted the pairing channel, make sure it matches the coordinator's
Zigbee channel.

### The device rejoins an old network after reflash

This is expected. Zigbee network credentials are stored in non-volatile memory
and survive sketch upload. Use `Zigbee.factoryReset()` when you want the board to
forget the old network.

### The switch pairs but does not control a light

Create a Zigbee binding from the switch's On/Off cluster to the light you want to
control. The switch sends commands to configured bindings.

### Home Assistant shows stale metadata

Many coordinators cache Basic cluster values. Remove and re-pair the device, or
force a reconfigure/read of the device from the coordinator.

## Current Scope

This library is an Arduino-friendly wrapper around a generated Zigbee
application. It is intentionally smaller than the full Silicon Labs Zigbee SDK.
It currently exposes common smart-home device types and selected cluster
attributes. For advanced Zigbee clusters, custom device types, or changes to the
generated endpoint layout, you can use Simplicity Studio to build your own custom fine-tuned Zigbee applications.
