cmake_minimum_required(VERSION 3.15)
project(5_rpn_calc C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Werror -Wextra -Wall")

add_executable(5_rpn_calc main.c)