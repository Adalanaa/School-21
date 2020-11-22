cmake_minimum_required(VERSION 3.15)
project(5_print_memory C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(5_print_memory print_memory.c main.c)