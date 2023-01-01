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
I (322) example_usage: Device reset: Successful
I (332) example_usage: Changing power mode to ON: Successful
I (332) example_usage: Changing measurement time: Successful
I (522) example_usage: BH1750 config successful
I (522) example_usage: BH1750 initialization successful
I (762) example_usage: Light Intensity: 0 Lux
I (2002) example_usage: Light Intensity: 8 Lux
I (3242) example_usage: Light Intensity: 8 Lux
I (4482) example_usage: Light Intensity: 8 Lux
I (5722) example_usage: Light Intensity: 8 Lux
I (6962) example_usage: Light Intensity: 303 Lux
I (8202) example_usage: Light Intensity: 418 Lux
I (9442) example_usage: Light Intensity: 402 Lux
I (10682) example_usage: Light Intensity: 288 Lux
I (11922) example_usage: Light Intensity: 8 Lux
I (13162) example_usage: Light Intensity: 8 Lux
I (14402) example_usage: Light Intensity: 8 Lux
I (15642) example_usage: Light Intensity: 8 Lux
```
