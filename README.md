# dht11_driver
dht11 driver for esp32 all series development boards.

# Usage
#### 1.Put `dht11.h` and `dht11.c` files in your `main` folder.
#### 2.Import `dht11.h` in your `main.c` file, then you can use it.
Use like this:
```C
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht11.h"

void app_main(void)
{
    printf("Start read.....\n");
    DHT11 *dht11_info = (DHT11 *)malloc(sizeof(DHT11));
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS * 3);
        if (dht11_read(7, dht11_info)) {
            printf("RH: %d.%d%%, T: %d.%d℃\n", dht11_info->rh_i, dht11_info->rh_d, dht11_info->t_i, dht11_info->t_d);
        } else {
            printf("Read fail.\n");
        }
    }
}
```
