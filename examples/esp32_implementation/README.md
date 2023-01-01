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
I (320) example_usage: Device reset: Successful
I (330) example_usage: Changing power mode to ON: Successful
I (510) example_usage: BH1750 config successful
I (510) example_usage: BH1750 initialization successful
I (630) example_usage: Light Intensity: 34 Lux
I (1750) example_usage: Light Intensity: 34 Lux
I (2870) example_usage: Light Intensity: 34 Lux
I (3990) example_usage: Light Intensity: 34 Lux
I (5110) example_usage: Light Intensity: 34 Lux
I (6230) example_usage: Light Intensity: 34 Lux
I (7350) example_usage: Light Intensity: 34 Lux
I (8470) example_usage: Light Intensity: 242 Lux
I (9590) example_usage: Light Intensity: 492 Lux
I (10710) example_usage: Light Intensity: 415 Lux
I (11830) example_usage: Light Intensity: 386 Lux
I (12950) example_usage: Light Intensity: 371 Lux
I (14070) example_usage: Light Intensity: 309 Lux
I (15190) example_usage: Light Intensity: 81 Lux
I (16310) example_usage: Light Intensity: 37 Lux
I (17430) example_usage: Light Intensity: 34 Lux
I (18550) example_usage: Light Intensity: 34 Lux
I (19670) example_usage: Light Intensity: 33 Lux
```
