cmake_minimum_required(VERSION 3.15)
project(lem-in)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(LIBRARY_PATH /Users/kplums/CLionProjects/School-21/libft/libft.a)

add_executable(lem-in includes/lem_in.h
                        src/add_level.c
                        src/ant_and_comment.c
                        src/check_in.c
                        src/check_out.c
                        src/count_in_out.c
                        src/free.c
                        src/init.c
                        src/lemin.c
                        src/links.c
                        src/move.c
                        src/output.c
                        src/parser.c
        src/path.c)

target_link_libraries(lem-in    ${LIBRARY_PATH})

target_include_directories(lem-in    PRIVATE ../libft/includes)
target_include_directories(lem-in    PRIVATE includes)