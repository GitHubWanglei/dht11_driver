#include "dht11.h"
#include "rom/ets_sys.h"

uint8_t dht11_read(gpio_num_t gpio_num, DHT11 *dht11) {
    // esp32 send start signal
    gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT);
    gpio_set_level(gpio_num, 0);
    ets_delay_us(20*1000);
    gpio_set_level(gpio_num, 1);
    // dht11 send response signal and wait
    gpio_set_direction(gpio_num, GPIO_MODE_INPUT);
    while (gpio_get_level(gpio_num) == 1);
    while (gpio_get_level(gpio_num) == 0);
    while (gpio_get_level(gpio_num) == 1);
    // start receive dht11 response data
    uint8_t idx = 0;
    int8_t data[5] = {0, 0, 0, 0, 0};
    for (uint8_t i = 0; i < 40; i++) {
        while (gpio_get_level(gpio_num) == 0);
        ets_delay_us(30);
        idx = i / 8;
        data[idx] = (data[idx] << 1);
        if (gpio_get_level(gpio_num) == 1) {
            data[idx] |= 1;
            while (gpio_get_level(gpio_num) == 1);
        }
    }
    // checksum
    if ((data[0]+data[1]+data[2]+data[3]) != data[4]) {
        return 0;
    }
    dht11->rh_i = data[0];
    dht11->rh_d = data[1];
    dht11->t_i = data[2];
    dht11->t_d = data[3];
    return 1;
}
