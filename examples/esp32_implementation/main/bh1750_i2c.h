/*
 * Copyright (c) 2022, Mezael Docoy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MAIN_BH1750_I2C
#define MAIN_BH1750_I2C

#ifdef __cplusplus
extern "C" {
#endif

#include "bh1750_i2c_hal.h" 

/**
 * @brief BH1750 I2C slave addresses (ADDR pin low)
 */
#define I2C_ADDRESS_BH1750              0x23

/**
 * @brief BH1750 I2C slave addresses (ADDR pin high)
 */
//#define I2C_ADDRESS_BH1750              0x5C

/**
 * @brief BH1750 R/W Command Instruction Codes
 */
#define OPECODE_RESET                   0x07
#define OPECODE_MEAS_TIME_HIGH_BIT      0x40
#define OPECODE_MEAS_TIME_LOW_BIT       0x60

/**
 * @brief Other BH1750 macros
 */
#define RES_MODE_SET_DELAY_TIME_MS      180
#define H_RES_MODE_MEASUREMENT_TIME_MS  120
#define L_RES_MODE_MEASUREMENT_TIME_MS  16
#define DEFAULT_MEAS_TIME_REG_VAL       0x45

typedef struct{
    uint8_t i2c_addr;
    uint16_t meas_time;
    uint16_t meas_time_mul;
    uint8_t mtreg_val;
} bh1750_dev_t;

typedef enum{
    BH1750_CONT_H_RES_MODE = 0x10,
    BH1750_CONT_H_RES_MODE2  = 0x11,
    BH1750_CONT_L_RES_MODE  = 0x13,
    BH1750_ONETIME_H_RES_MODE  = 0x20,
    BH1750_ONETIME_H_RES_MODE2  = 0x21,
    BH1750_ONETIME_L_RES_MODE  = 0x23,
} bh1750_res_mode_t;

typedef enum{
    BH1750_POWER_DOWN = 0x00,
    BH1750_POWER_ON  = 0x01,
} bh1750_power_mode_t;

/**
 * @brief Reset BH1750
 */
int16_t bh1750_i2c_dev_reset(bh1750_dev_t dev);

/**
 * @brief Set power mode
 */
int16_t bh1750_i2c_set_power_mode(bh1750_dev_t dev, bh1750_power_mode_t mode);

/**
 * @brief Set resolution mode
 */
int16_t bh1750_i2c_set_resolution_mode(bh1750_dev_t *dev, bh1750_res_mode_t mode);

/**
 * @brief Set measurement time register value
 */
int16_t bh1750_i2c_set_mtreg_val(bh1750_dev_t *dev, float sens);

/**
 * @brief Read sensor data in lux
 */
int16_t bh1750_i2c_read_data(bh1750_dev_t dev, uint16_t *dt);

#ifdef __cplusplus
}
#endif

#endif /* MAIN_BH1750_I2C */