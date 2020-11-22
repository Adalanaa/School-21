cmake_minimum_required(VERSION 3.15)
project(C C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wextra -Wall -Werror")

add_executable(C
        main.c vozvedenie_v_stepen.c head.h)
