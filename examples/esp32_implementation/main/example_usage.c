#include <stdio.h>
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*  BH1750 components  */
#include "bh1750_i2c.h"
#include "bh1750_i2c_hal.h"

static const char *TAG = "example_usage";

bh1750_dev_t dev_1;

void app_main(void)
{
    esp_err_t err;

    bh1750_i2c_hal_init();

    /* Device init */
    dev_1.i2c_addr = I2C_ADDRESS_BH1750;
    dev_1.mtreg_val = DEFAULT_MEAS_TIME_REG_VAL;

    /* Perform device reset */
    err = bh1750_i2c_dev_reset(dev_1); 
    ESP_LOGI(TAG, "Device reset: %s", err == BH1750_OK ? "Successful" : "Failed");

    err += bh1750_i2c_set_power_mode(dev_1, BH1750_POWER_ON);
    ESP_LOGI(TAG, "Changing power mode to ON: %s", err == BH1750_OK ? "Successful" : "Failed");

    /* Configure device */
    err += bh1750_i2c_set_resolution_mode(&dev_1, BH1750_CONT_H_RES_MODE);
    if (err == BH1750_OK)
    {
        ESP_LOGI(TAG, "BH1750 config successful");
    }
    else{
        ESP_LOGE(TAG, "BH1750 config failed!");
    }
    /* End of device config */

    if (err == BH1750_OK)
    {
        ESP_LOGI(TAG, "BH1750 initialization successful");
        //Start reading data
        uint16_t data;
        while(1)
        {
            bh1750_i2c_read_data(dev_1, &data);
            ESP_LOGI(TAG, "Light Intensity: %d Lux", data);
            bh1750_i2c_hal_ms_delay(1000);
        }
    }
    else{
        ESP_LOGE(TAG, "BH1750 initialization failed!");
    }
}
