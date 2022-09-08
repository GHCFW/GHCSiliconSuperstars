# GHC SiliconSuperstars: The star power of firmware in computing

<br>

**GPIOs**
* GPIO stands for General Purpose I/O
* It is an interface that allows the processor to connect to external peripherals
* It can be programmed through software using the SIO interface
  * Check out **gpio_registers_t** struct in **gpio.h** for a list of registers we will be using in the programming exercise

* APIs we will be working on:

  1. Enable the pin: 									     **gpio_init**
  1. Change the direction of a given pin: 	**gpio_set_dir**
  1. Get the direction of a given pin: 		**gpio_get_dir**
  1. Write to the gpio pin: 							 **gpio_put**
  1. Read from a gpio pin: 							  **gpio_get**

<br>

**Programming Exercises**

* Step 1: Open Compiler Explorer project for unit testing exercises

  https://godbolt.org/z/W7Ke7jeev


* Step 2: Complete Compiler Explorer Excerises below

  * Exercise 1:

    * You have a set of failing unit tests for the Blink LED exercise

      * **GOAL**: Write minimal source code to get all the tests to pass for the GPIO interface

      * HINT: review code in the test to understand the expected behavior


  * Exercise 2: 

    * Program LED to Blink in main() by updating blinkd_led() function.

    * LED is ON when you write 1 to it and off when you write 0.


* Step 3: Open Wokwi project for Raspberry Pi Pico simulation

  https://wokwi.com/projects/341664287465407060


* Step 4: Complete Wokwi Excerises below

  * Exercise 3:

    * Port the blink_led code from Compiler Explorer to the Wokwi simulator project and “Deploy”


  * Exercise 4:

    * Program the toggle_led() to use the hardware toggle register to blink the LED


  * Exercise 5:

    * Implement an interrupt handler in the alarm_irq() to the toggle the LED

      * **HINT**: Pay attention to the global alarm_fired variable

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
  
    https://godbolt.org/z/esProoG99

  * ***Wokwi Exercise***
  
    https://wokwi.com/projects/342181558184051283
