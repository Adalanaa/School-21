cmake_minimum_required(VERSION 3.14)
project(struct C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -g")

add_executable(struct main.c)