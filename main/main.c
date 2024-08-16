/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 15;
const int BTN_PIN = 28;
const int A = 6;
const int B = 7;
const int C = 8;
const int D = 9;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(A);
    gpio_init(B);
    gpio_init(C);
    gpio_init(D);

    gpio_set_dir(A, GPIO_OUT);
    gpio_set_dir(B, GPIO_OUT);
    gpio_set_dir(C, GPIO_OUT);
    gpio_set_dir(D, GPIO_OUT);
    
    int led = 0;

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            gpio_put(LED_PIN, 1);
            sleep_ms(50);
            for (int i = 0; i < 512; i++) {

                gpio_put(A, 1);
                sleep_ms(5);
                gpio_put(A,0);
                
                gpio_put(B, 1);
                sleep_ms(5);
                gpio_put(B, 0);
                
                gpio_put(C, 1);
                sleep_ms(5);
                gpio_put(C, 0);
            
                gpio_put(D, 1);
                sleep_ms(5);
                gpio_put(D, 0);
                
                
            }
            gpio_put(LED_PIN, 0);
        }
    }
}
