# GHC SiliconSuperstars: The star power of firmware in computing

<br>

**Programming Exercises**

Exercise 1: Blink an LED using Wokwi Simulator for Raspberry Pi Pico
https://wokwi.com/projects/341664287465407060

    * Program LED to Blink in main() by updating blinkd_led() function.

    * LED is ON when you write 1 to it and off when you write 0.


Exercise 2: Develop an API for the GPIO library

Follow along here: https://godbolt.org/z/s8edYcKfK 

      * You have a set of failing unit tests that checks for the functionality of gpio_set_dir() function
      * **GOAL**: Write minimal source code to get all the tests to pass
      * HINT: Start with fixing one REQUIRE at a time



<br>

**GPIOs**
* GPIO stands for General Purpose I/O
* It is an interface that allows the processor to connect to external peripherals
* It can be programmed through software using the SIO interface
  * Check out **gpio_registers_t** struct in **gpio.h** for a list of registers we will be using in the programming exercise

* APIs we will be working on (based on the Raspberry Pi Pico SDK):
  
  * Enable the pin: 									     ***gpio_init***
  * Change the direction of a given pin: 	***gpio_set_dir***
      * Updates the ***gpio_oe*** register to drive the direction for the given GPIO pin
  * Get the direction of a given pin: 		***gpio_get_dir***
      * Reads the ***gpio_oe*** register to get the direction for the given GPIO pin
  * Write to the gpio pin: 							 ***gpio_put***
      * Updates the ***gpio_out*** register to drive the output value for the given GPIO pin
  * Read from a gpio pin: 							  ***gpio_get***
      * Reads the ***gpio_in*** register to get the status of the given pin

<br>

**Compiler Explorer Debug Guide:**

Error: Compiler Error/Catch2 framework not found. 
Resolution: Change the compiler to x86-64 gcc 10.2 and in "Libraries" add Catch2 version 3.0.0-preview2

Error: Running main code instead of unit tests or vice versa. 
Resolution: Use -DRUN_UNIT_TESTS=0 (for main code) or -DRUN_UNIT_TESTS=1 (for unit tests) in Tree=>CMake options

<br>

**Wokwi Debug Guide:**

Error: .
Resolution: Confirm that you have the right header inclusions namely, 

<br>

**Answer Keys**

  * ***Compiler Explorer Exercise***
  
    https://godbolt.org/z/4sb5W1GzK 

  * ***Wokwi Exercise*** [Update this]
  
    https://wokwi.com/projects/342181558184051283
    
<br>

* Bonus Exercises 
    * Exercise:

      * Program the toggle_led() to use the hardware toggle register to blink the LED


    * Exercise:

      * Implement an interrupt handler in the alarm_irq() to the toggle the LED

      * **HINT**: Pay attention to the global alarm_fired variable

