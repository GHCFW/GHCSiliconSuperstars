// File for unit tests of LED exercise
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Switch LED to on and off every 1sec") {
    REQUIRE( program_led_pin(25) == 25 );
    REQUIRE( LED_PIN == PICO_DEFAULT_LED_PIN );
}