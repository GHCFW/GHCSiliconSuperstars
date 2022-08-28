// File for HW API that we abstracted here
#include "api.h"
#include <unistd.h>

void gpio_init(int led_pin) {
    pin_directions::insert(led_pin);
}

void gpio_set_dir(int led_pin, std::string direction) {
    pin_directions[led_pin] = direction;
}

void sleep_ms(int time_in_ms) {
    //<SW sleep in seconds>
    sleep(time_in_ms/1000);
}

void gpio_put(int pin, int value) {
    //Do nothing
}

