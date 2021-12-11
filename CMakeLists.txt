# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/antonio/Progetti/picoProjects/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(C_MOTE C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(C_MOTE C_MOTE.c oled.c)

pico_set_program_name(C_MOTE "C_MOTE")
pico_set_program_version(C_MOTE "0.1")

pico_enable_stdio_uart(C_MOTE 1)
pico_enable_stdio_usb(C_MOTE 1)

# Add the standard library to the build
target_link_libraries(C_MOTE pico_stdlib)
target_link_libraries(C_MOTE pico_stdlib pico_multicore)
target_link_libraries(C_MOTE pico_stdlib hardware_gpio)
target_link_libraries(C_MOTE pico_stdlib hardware_adc)
target_link_libraries(C_MOTE pico_stdlib hardware_i2c)

pico_add_extra_outputs(C_MOTE)

