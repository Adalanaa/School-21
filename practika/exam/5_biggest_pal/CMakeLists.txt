cmake_minimum_required(VERSION 3.14)
project(5_biggest_pal C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wextra -Werror -Wall")

add_executable(5_biggest_pal main.c)