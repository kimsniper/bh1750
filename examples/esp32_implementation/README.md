# BH1750 - ESP-IDF

BH1750 i2c library for ESP-IDF.
ESP-IDF template used for this project: https://github.com/espressif/esp-idf/tree/master/examples/peripherals/i2c/i2c_simple

## Overview

This example demonstrates usage of BH1750 to read light intensity.

### Hardware Required

To run this example, you should have one ESP32, ESP32-S or ESP32-C based development board as well as a BH1750. BH1750 is an digital Ambient Light Sensor IC for I2C bus interface. This IC is the most suitable to obtain the ambient light data for adjusting LCD and Keypad backlight power of Mobile phone. It is possible to detect wide range at High resolution. (1-65535 lx). It is easy to operate via a simple I2C command, you can read the datasheet [here](https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf).

#### Pin Assignment:

**Note:** The following pin assignments are used by default, you can change these in the `menuconfig` .

|                  | SDA             | SCL           |
| ---------------- | -------------- | -------------- |
| ESP I2C Master   | I2C_MASTER_SDA | I2C_MASTER_SCL |
| BH1750           | SDA            | SCL            |


For the actual default value of `I2C_MASTER_SDA` and `I2C_MASTER_SCL` see `Example Configuration` in `menuconfig`.

**Note: ** There’s no need to add an external pull-up resistors for SDA/SCL pin, because the driver will enable the internal pull-up resistors.

### Build and Flash

Enter `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

```bash
I (321) example_usage: Device reset: Successful
I (331) example_usage: Changing power mode to ON: Successful
I (511) example_usage: BH1750 config successful
I (511) example_usage: Changing measurement time: Successful
I (511) example_usage: BH1750 initialization successful
I (751) example_usage: Light Intensity: 0 Lux
I (1991) example_usage: Light Intensity: 31 Lux
I (3231) example_usage: Light Intensity: 32 Lux
I (4471) example_usage: Light Intensity: 32 Lux
I (5711) example_usage: Light Intensity: 32 Lux
I (6951) example_usage: Light Intensity: 185 Lux
I (8191) example_usage: Light Intensity: 688 Lux
I (9431) example_usage: Light Intensity: 636 Lux
I (10671) example_usage: Light Intensity: 618 Lux
I (11911) example_usage: Light Intensity: 616 Lux
I (13151) example_usage: Light Intensity: 466 Lux
I (14391) example_usage: Light Intensity: 33 Lux
I (15631) example_usage: Light Intensity: 505 Lux
I (16871) example_usage: Light Intensity: 535 Lux
I (18111) example_usage: Light Intensity: 69 Lux
I (19351) example_usage: Light Intensity: 31 Lux
I (20591) example_usage: Light Intensity: 30 Lux
```
