# GHC SiliconSuperstars: The star power of firmware in computing

Step 1: 
Open Compiler Explorer project link and get all unit tests to pass
https://godbolt.org/z/7Y1eqoK3Y

Step 2:
Wokwi Phase 1 deployment of Blink LED
https://wokwi.com/projects/341175578309689940

Step 3:
Wokwi Develop Toggle LED

Step 4:
Wokwi Develop Interrupt Routine Handler

**Debug Guide:**

Error: Compiler Error/Catch2 framework not found. 
Resolution: Change the compiler to x86-64 gcc 10.2 and in "Libraries" add Catch2 version 3.0.0-preview2

Error: Running main code instead of unit tests or vice versa. 
Resolution: Use -DRUN_UNIT_TESTS=0 (for main code) or -DRUN_UNIT_TESTS=1 (for unit tests) in Tree=>CMake options
