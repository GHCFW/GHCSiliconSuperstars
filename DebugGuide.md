**Wokwi Debug Guide**

Error: . Resolution: Confirm that you have the right header inclusions namely,


**Compiler Explorer Debug Guide**

Error: Compiler Error/Catch2 framework not found. Resolution: Change the compiler to x86-64 gcc 10.2 and in "Libraries" add Catch2 version 3.0.0-preview2

Error: Running main code instead of unit tests or vice versa. Resolution: Use -DRUN_UNIT_TESTS=0 (for main code) or -DRUN_UNIT_TESTS=1 (for unit tests) in Tree=>CMake options
