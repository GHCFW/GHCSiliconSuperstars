#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN (PICO_DEFAULT_LED_PIN)

volatile bool timer_fired = false;

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

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Timer %d fired!\n", (int) id);
    timer_fired = true;
    // Can return a value here in us to fire in the future
    return 0;
}

int main() {
    stdio_init_all();
    printf("Hello GHC participants!\n");

    program_led_pin(LED_PIN);
    
    // Call alarm_callback in 2 seconds
    add_alarm_in_ms(2000, alarm_callback, NULL, false);

    // LED => ON
    switch_pin(LED_PIN, 1);

    // Wait for alarm callback to set timer_fired
    while (!timer_fired) {
        tight_loop_contents();
    }

    // LED => OFF
    switch_pin(LED_PIN, 0);
    printf("Done\n");

    sleep_ms(2000);

    printf("Done\n");
    return 0;
}
