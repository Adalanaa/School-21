cmake_minimum_required(VERSION 3.17)
project(libft C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

include_directories(includes)

add_library(libft STATIC
        includes/ft_printf.h
        includes/get_next_line.h
        includes/libft.h
        src/array/ft_countarrtochar.c
        src/array/ft_lenarrtochar.c
        src/array/ft_newarrchar.c
        src/char/ft_isalnum.c
        src/char/ft_isalpha.c
        src/char/ft_isascii.c
        src/char/ft_isdigit.c
        src/char/ft_isprint.c
        src/char/ft_tolower.c
        src/char/ft_toupper.c
        src/gnl/get_next_line.c
        src/int/ft_int_abs.c
        src/int/ft_int_abs_min.c
        src/int/ft_int_arr_check.c
        src/int/ft_int_arr_max.c
        src/int/ft_int_arr_min.c
        src/int/ft_int_max.c
        src/int/ft_int_min.c
        src/list/ft_lst1add.c
        src/list/ft_lst1del.c
        src/list/ft_lst1delcont.c
        src/list/ft_lst1delone.c
        src/list/ft_lst1iter.c
        src/list/ft_lst1len.c
        src/list/ft_lst1map.c
        src/list/ft_lst1new.c
        src/memory/ft_bzero.c
        src/memory/ft_malloc.c
        src/memory/ft_memalloc.c
        src/memory/ft_memccpy.c
        src/memory/ft_memchr.c
        src/memory/ft_memcmp.c
        src/memory/ft_memcpy.c
        src/memory/ft_memdel.c
        src/memory/ft_memmove.c
        src/memory/ft_memset.c
        src/output/ft_printf/a_ft_printf.c
        src/output/ft_printf/b_parser.c
        src/output/ft_printf/c_doit.c
        src/output/ft_printf/d_buff_write.c
        src/output/ft_printf/doit_c.c
        src/output/ft_printf/doit_di.c
        src/output/ft_printf/doit_f.c
        src/output/ft_printf/doit_lf.c
        src/output/ft_printf/doit_ouxx_1.c
        src/output/ft_printf/doit_ouxx_2.c
        src/output/ft_printf/doit_p.c
        src/output/ft_printf/doit_persent.c
        src/output/ft_printf/doit_s.c
        src/output/ft_error.c
        src/output/ft_putchar.c
        src/output/ft_putchar_fd.c
        src/output/ft_putendl.c
        src/output/ft_putendl_fd.c
        src/output/ft_putnbr.c
        src/output/ft_putnbr_fd.c
        src/output/ft_putstr.c
        src/output/ft_putstr_fd.c
        src/string/ft_checkline_int_space.c
        src/string/ft_strcat.c
        src/string/ft_strchr.c
        src/string/ft_strclr.c
        src/string/ft_strcmp.c
        src/string/ft_strcpy.c
        src/string/ft_strdel.c
        src/string/ft_strdup.c
        src/string/ft_strequ.c
        src/string/ft_striter.c
        src/string/ft_striteri.c
        src/string/ft_strjoin.c
        src/string/ft_strlcat.c
        src/string/ft_strlen.c
        src/string/ft_strmap.c
        src/string/ft_strmapi.c
        src/string/ft_strncat.c
        src/string/ft_strncmp.c
        src/string/ft_strncpy.c
        src/string/ft_strnequ.c
        src/string/ft_strnew.c
        src/string/ft_strnstr.c
        src/string/ft_strrchr.c
        src/string/ft_strsplit.c
        src/string/ft_strstr.c
        src/string/ft_strsub.c
        src/string/ft_strtrim.c
        src/xtoy/ft_atoi.c
        src/xtoy/ft_itoa.c
        src/xtoy/ft_itoa_base.c
        src/xtoy/ft_atoi_longlong.c src/memory/ft_calloc.c)
