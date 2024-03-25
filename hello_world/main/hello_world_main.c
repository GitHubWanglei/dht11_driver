/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "dht11.h"

void app_main(void)
{
    printf("Start read.....\n");
    DHT11 *dht11_info = (DHT11 *)malloc(sizeof(DHT11));
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS * 3);
        if (dht11_read(7, dht11_info)){
            printf("RH: %d.%d%%, T: %d.%d℃\n", dht11_info->rh_i, dht11_info->rh_d, dht11_info->t_i, dht11_info->t_d);
        } else {
            printf("Read fail.\n");
        }
    }

    // free(dht11_info);
    // dht11_info = NULL;
    
}
