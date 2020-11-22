cmake_minimum_required(VERSION 3.14)
project (gnl C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -g")

set(LIBRARY_PATH //Users/kplums/school/gnl/libft/libft.a)

add_executable(gnl main.c get_next_line.c)
target_link_libraries(gnl ${LIBRARY_PATH})
target_include_directories(gnl PRIVATE libft/)