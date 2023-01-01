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

#include "bh1750_i2c.h" 
#include "bh1750_i2c_hal.h" 

#include "math.h"

int16_t bh1750_i2c_dev_reset(bh1750_dev_t dev)
{
    uint8_t data = OPECODE_RESET;
    int16_t err = bh1750_i2c_hal_write(dev.i2c_addr, &data, 1);
    
    return err;
}

int16_t bh1750_i2c_set_power_mode(bh1750_dev_t dev, bh1750_power_mode_t mode)
{
    uint8_t data = (uint8_t)mode;
    int16_t err = bh1750_i2c_hal_write(dev.i2c_addr, &data, 1);
    
    return err;
}

int16_t bh1750_i2c_set_resolution_mode(bh1750_dev_t *dev, bh1750_res_mode_t mode)
{
    uint8_t data = (uint8_t)mode;
    int16_t err = bh1750_i2c_hal_write(dev->i2c_addr, &data, 1);

    if(err != BH1750_OK)
        return err;

    if(mode == BH1750_CONT_L_RES_MODE || mode == BH1750_ONETIME_L_RES_MODE)
        dev->meas_time = L_RES_MODE_MEASUREMENT_TIME_MS;
    else
        dev->meas_time = H_RES_MODE_MEASUREMENT_TIME_MS;

    bh1750_i2c_hal_ms_delay(RES_MODE_SET_DELAY_TIME_MS);
    
    return err;
}

int16_t bh1750_i2c_set_mtreg_val(bh1750_dev_t *dev, float sens)
{
    uint8_t data;
    int16_t err;
    sens /= 100;
    if(sens > 100 || ((dev->mtreg_val * ((uint8_t) (1 / sens))) > 0xFF))
        return BH1750_ERR;
    
    uint8_t mtreg = dev->mtreg_val * (uint8_t) (1 / sens);

    /* Send high bits */
    data = OPECODE_MEAS_TIME_HIGH_BIT | (mtreg >> 5);
    err = bh1750_i2c_hal_write(dev->i2c_addr, &data, 1);

    if(err != BH1750_OK)
        return err;

    /* Send low bits */
    data = OPECODE_MEAS_TIME_LOW_BIT | (mtreg & 0x1F);
    err = bh1750_i2c_hal_write(dev->i2c_addr, &data, 1);

    if(err != BH1750_OK)
        return err;

    dev->meas_time_mul = (uint8_t) (1 / sens);
    dev->mtreg_val = mtreg;

    return err;
}

int16_t bh1750_i2c_read_data(bh1750_dev_t dev, uint16_t *dt)
{
    uint8_t data[2];
    int16_t err = bh1750_i2c_hal_read(dev.i2c_addr, data, 2);

    *dt = (data[0] << 8) | data[1];
    *dt = round(*dt / 1.2f);

    bh1750_i2c_hal_ms_delay(dev.meas_time * dev.meas_time_mul);

    return err;
}