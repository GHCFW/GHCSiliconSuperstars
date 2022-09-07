# GHC SiliconSuperstars: The star power of firmware in computing

Step 1: 
Open Compiler Explorer project link and get all unit tests to pass
https://godbolt.org/z/8P1EcoMGE
Step 2:
Open Wokwi project for Raspberry Pi Pico
https://wokwi.com/projects/341664287465407060

You have a set of failing unit tests for Blink LED exercise
GOAL: Write minimal code to get all the tests to pass for the GPIO interface
HINT: review code in the test to understand the expected behavior
Program LED to Blink in main()
Port the blink led code in main() to the Wokwi simulator project and “Deploy”
Program the toggle_led() to use the hardware toggle register that will blink the LED
Replace sleep() in main.cpp with a timer by implementing a interrupt handler routine

**Compiler Explorer Debug Guide:**

Error: Compiler Error/Catch2 framework not found. 
Resolution: Change the compiler to x86-64 gcc 10.2 and in "Libraries" add Catch2 version 3.0.0-preview2

Error: Running main code instead of unit tests or vice versa. 
Resolution: Use -DRUN_UNIT_TESTS=0 (for main code) or -DRUN_UNIT_TESTS=1 (for unit tests) in Tree=>CMake options

**Wokwi Debug Guide:**

Error: .
Resolution: Confirm that you have the right header inclusions namely, 

**Answer Key for the Compiler Explorer Exercise**
https://godbolt.org/z/esProoG99
