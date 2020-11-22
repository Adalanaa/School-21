cmake_minimum_required(VERSION 3.14)
project(5_cycle_detector C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Werror -Wall -Wextra")

add_executable(5_cycle_detector main.c cycle_detector.c list.h)