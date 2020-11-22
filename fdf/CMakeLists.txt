cmake_minimum_required(VERSION 3.15)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

add_executable(fdf includes/fdf.h
        src/main.c
        src/ft_validation.c
        src/ft_koord.c
        src/ft_error.c
        src/ft_draw.c
        src/ft_delfdf.c src/ft_deal.c src/ft_mat.c)

target_link_libraries(fdf
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a "-framework OpenGL" "-framework AppKit")


