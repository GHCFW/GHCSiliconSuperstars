# GHC SiliconSuperstars: The star power of firmware in computing

<br>

# **Programming Exercises**

## **Exercise 1: Blink an LED using Wokwi Simulator for Raspberry Pi Pico**

	https://wokwi.com/projects/342282251373904466
  
* Exercise 1.1: Use gpio_init that programs GPIO pin to LED_PIN

	```
	/*
    	Initialize the given GPIO by:
    	- Clear the output enable (i.e. set to input). 
    	- Clear the output value for the given GPIO
    	@params[in]: gpio   GPIO number
    	@return:     none
	*/
	void gpio_init(uint32_t gpio);
	```
* Exercise 1.2: Use gpio_set_dir that programs direction of LED_PIN to GPIO_OUT

	```
	/*
    	Set a single GPIO direction as input or output

    	@params[in]: gpio       GPIO pin number
    	@params[in]: direction  true for out, false for in
    	@return:     none
	*/
	void gpio_set_dir(uint32_t gpio, bool direction);
	```

* Exercise 1.3: Use gpio_put and drive LED to ON and OFF

	```
	/*
    	Drive a single GPIO high/low.
    	@param[in]: gpio    GPIO pin number
    	@param[in]: value   false: clear the pin,
                            true: set the pin
    	@return: none
	*/
	void gpio_put(uint32_t gpio, bool value);
	```

* Exercise 1.4: Use sleep_ms() to add some delay in between different LED states

	```
	/*
    	Wait for the given number of milliseconds before returning.
    	@param[in]: ms      the number of milliseconds to sleep

	*/
	void sleep_ms	(uint32_t ms);	
	```

## **Exercise 2: Develop an API for the GPIO library**

Follow along here: 
	https://godbolt.org/z/s8edYcKfK 

* You have a set of failing unit tests that checks for the functionality of gpio_set_dir() function
* GOAL: Write minimal source code to get all the tests to pass
* HINT: Start with fixing one REQUIRE at a time



## **GPIOs**
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


Raspberry Pi Resources:
https://github.com/raspberrypi/pico-sdk
https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf
https://github.com/raspberrypi/pico-examples


Unit Testing:
	https://en.wikipedia.org/wiki/Test-driven_development
	https://en.wikipedia.org/wiki/Unit_testing
