cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(LIBRARY_PATH /Users/kplums/CLionProjects/ft_printf/libft/libft.a)

add_executable(ft_printf main.c src/a_ft_printf.c src/b_parser.c src/d_buff_write.c
        src/doit_di.c src/doit_s.c src/doit_c.c src/doit_f.c src/doit_lf.c
        src/doit_p.c src/doit_persent.c src/doit_ouxx_2.c src/doit_ouxx_1.c src/c_doit.c includes/func_printf.h)

target_link_libraries(ft_printf ${LIBRARY_PATH})

target_include_directories(ft_printf PRIVATE libft/includes)
target_include_directories(ft_printf PRIVATE includes)