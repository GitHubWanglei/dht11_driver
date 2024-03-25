#ifndef __DHT11_H_
#define __DHT11_H_

#include "driver/gpio.h"

/*
    dht11 data info struct.
*/
typedef struct {
    int8_t rh_i; // integral RH data
    int8_t rh_d; // decimal RH data
    int8_t t_i; // integral T data
    int8_t t_d; // decimal T data
} DHT11;

/*
    Returns: 1 success; 0 failure.
*/
uint8_t dht11_read(gpio_num_t gpio_num, DHT11 *dht11);

#endif