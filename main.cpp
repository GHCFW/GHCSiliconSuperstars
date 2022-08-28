#include <cstdio>
#include <string>
#include "api/api.h"

#define LED_PIN (PICO_DEFAULT_LED_PIN)

int program_led_pin(int led_pin);
void sleep_for_time(int time_in_ms);
void switch_pin(int pin, int value);

int program_led_pin(int led_pin) {
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
    return led_pin;
}

void sleep_for_time(int time_in_ms) {
    sleep_ms(time_in_ms);
}

void switch_pin(int pin, int value) {
    gpio_put(pin, value);
}

int main() {
    program_led_pin(LED_PIN);
    
    while (true) {
        printf("Hello, GHC participants!\n");
        switch_pin(LED_PIN, 1);
        sleep_for_time(1000);
        switch_pin(LED_PIN, 0);
        sleep_for_time(1000);
    }
}