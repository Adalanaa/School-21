cmake_minimum_required(VERSION 3.15)
project(lcm C)

set(CMAKE_C_STANDARD 99)

add_executable(lcm main.c lcm.c)