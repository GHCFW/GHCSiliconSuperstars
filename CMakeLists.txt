project(led_exercise)

cmake_minimum_required(VERSION 3.23)

add_executable(led
    api/api.cpp
    test_main.cpp
    main.cpp)

target_include_directories(led PRIVATE api/)

target_link_libraries(led)