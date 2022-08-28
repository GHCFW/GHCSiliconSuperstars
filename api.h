#pragma once

#include <unordered_map>
#include <string>

#define PICO_DEFAULT_LED_PIN (25)

// Hash of LED pin# and direction
std::unordered_map<int, std::string> pin_directions;

void gpio_init(int led_pin);
void gpio_set_dir(int led_pin, std::string direction);
void sleep_ms(int time_in_ms);
void gpio_put(int pin, int value);