cmake_minimum_required(VERSION 3.14)
project(sudoku C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sudoku
		ft.c
		ft.h
		main.c
		sdk.h
		sdk_accessory.c
		sdk_solver.c)
