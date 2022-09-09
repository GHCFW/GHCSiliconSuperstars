# GHC SiliconSuperstars: The star power of firmware in computing

<br>

# **Programming Exercises**

## **Exercise 1: Blink an LED using Wokwi Simulator for Raspberry Pi Pico**
Follow along here: 
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
	
GOAL: Develop an API for gpio_set_dir(uint gpio, bool direction)

* You have a set of failing unit tests that checks for the functionality of gpio_set_dir()
* Write minimal source code to get all the tests to pass
* Start with writing enough code to get one ASSERT (REQUIRE) to pass at a time

Unit testing framework used for the exercises: Catch2

### gpio_set_dir(uint gpio, bool direction)
	Set the direction for a single GPIO pin

	Parameters: gpio -> pin number
		   direction -> true: the pin is programmed as an output pin 
 				false: the pin is programmed as an input pin
				
This is achieved by writing to the GPIO output enable register.

### gpio_oe register
	GPIO output enable register
	32-bit register
		Bits[29:0] corresponds to the pin direction for GPIO pins [29:0] respectively
		Bit positions [31:30] are ignored by the hardware

For example: 
gpio_oe = 0x5 [101 in binary] means:
	<br>
		- GPIO_2 & GPIO_0 are programmed as output pins
	<br>
		- GPIO_29..GPIO_3 & GPIO_1 are programmed as input pins



<br>


# **GPIOs**
* GPIO stands for General Purpose I/O
* It is an interface that allows the processor to connect to external peripherals
* It can be programmed through software using the SIO interface
  * Check out **gpio_registers_t** struct in **gpio.h** for a list of registers we will be using in the programming exercise

* APIs we will be working on (based on the Raspberry Pi Pico SDK):
  
  * Enable the pin: 									     ***gpio_init***
  * Change the direction of a given pin: 	***gpio_set_dir***
      * Updates the *gpio_oe* register to drive the direction for the given GPIO pin
  * Get the direction of a given pin: 		***gpio_get_dir***
      * Reads the *gpio_oe* register to get the direction for the given GPIO pin
  * Write to the gpio pin: 							 ***gpio_put***
      * Updates the *gpio_out* register to drive the output value for the given GPIO pin
  * Read from a gpio pin: 							  ***gpio_get***
      * Reads the *gpio_in* register to get the status of the given pin


# Answer Keys
  * ***Wokwi Exercise*** 
  
    https://wokwi.com/projects/342301731204366931
  
  * ***Compiler Explorer Exercise***
  
    https://godbolt.org/z/4sb5W1GzK 
    
<br>

# Additional Resources

Raspberry Pi Resources:
<br>
https://github.com/raspberrypi/pico-sdk
<br>
https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
<br>
https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf
<br>
https://github.com/raspberrypi/pico-examples

<br>
Unit Testing:
<br>
https://en.wikipedia.org/wiki/Test-driven_development
<br>
https://en.wikipedia.org/wiki/Unit_testing

<br>
Memory Mapped I/O:
<br>
https://en.wikipedia.org/wiki/Memory-mapped_I/O
