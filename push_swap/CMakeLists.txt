cmake_minimum_required(VERSION 3.15)
project(push_swap)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(LIBRARY_PATH /Users/kplums/CLionProjects/School/libft/libft.a)

add_executable(push_swap    includes/push_swap.h
                            src/push_swap/algoritm_3_5.c
                            src/push_swap/algoritm_12.c
                            src/push_swap/algoritm_100_500.c
                            src/other/do_stacks.c
                            src/other/parser.c
                            src/other/rules_pa_pb.c
                            src/other/rules_ra_rb_rr.c
                            src/other/rules_rra_rrb_rrr.c
                            src/other/rules_sa_sb_ss.c
#                            src/other/get_next_line.c
                            src/other/other.c
                            src/push_swap/after_chanks.c
                            src/push_swap/best_way.c
                            src/push_swap/chank_in_b.c
#                            src/push_swap/push_swap.c)
                           src/checker/checker.c)

target_link_libraries(push_swap ${LIBRARY_PATH})

target_include_directories(push_swap PRIVATE ../libft/includes)
target_include_directories(push_swap PRIVATE includes)