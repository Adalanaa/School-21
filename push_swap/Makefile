# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 21:26:51 by kplums            #+#    #+#              #
#    Updated: 2020/01/22 21:26:57 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

NAME_C = checker

OTHER_FILES		=	do_stacks.c \
					other.c \
					parser.c \
					rules_sa_sb_ss.c \
					rules_pa_pb.c \
					rules_ra_rb_rr.c \
					rules_rra_rrb_rrr.c

PUSH_FILES		=	after_chanks.c \
					algoritm_3_5.c \
					algoritm_12.c \
					algoritm_100_500.c \
					best_way.c \
					chank_in_b.c \
					push_swap.c

CHECK_FILES		=	checker.c

#			HEADERS			#
SRC_INC_DIR = ./includes/
INCLUDES = push_swap.h
HEADERS = $(addprefix $(SRC_INC_DIR), $(INCLUDES))
DEPS = $(HEADERS) Makefile $(LIBFT)

#			LIB				#
LIB_DIR = ../libft
LIB_INC_DIR = ../libft/includes/
LIBFT = $(LIB_DIR)/libft.a

# 			COMPILING		#
CFLGS = -Wall -Werror -Wextra
LFLGS = -L $(LIB_DIR) -lft
CC = gcc
INCL = -I $(SRC_INC_DIR)

#			SRC FILES			#
SRC_DIR  	= ./src/
PUSH_DIR 	= $(SRC_DIR)push_swap/
CHECK_DIR	= $(SRC_DIR)checker/
OTHER_DIR	= $(SRC_DIR)other/

PUSH_SRC	= $(addprefix $(PUSH_DIR),$(PUSH_FILES))
CHECK_SRC 	= $(addprefix $(CHECK_DIR),$(CHECK_FILES))
OTHER_SRC	= $(addprefix $(OTHER_DIR),$(OTHER_FILES))

PUSH 		+= $(PUSH_SRC) $(OTHER_SRC)
CHECK		+= $(CHECK_SRC) $(OTHER_SRC)

#			OBJECT FILES		#
OBJ_DIR_PUSH	= obj/obj_push/
OBJ_PUSH		= $(PUSH:$(SRC_DIR)%.c=$(OBJ_DIR_PUSH)%.o)
OBJ_DIR_CHECK 	= obj/obj_check/
OBJ_CHECK		= $(CHECK:$(SRC_DIR)%.c=$(OBJ_DIR_CHECK)%.o)

#___________________________
.PHONY: all clean fclean re

all: $(LIBFT) $(NAME_P) $(NAME_C)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

$(NAME_P): $(OBJ_PUSH)
	@$(CC) $(CFLGS) -o $(NAME_P) $(OBJ_PUSH) $(LFLGS)
	@echo "\033[32mPUSH_SWAP OK\033[0m"

$(OBJ_DIR_PUSH)%.o : $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR_PUSH)other $(OBJ_DIR_PUSH)push_swap
	$(CC) $(CFLGS) -MD -I $(SRC_INC_DIR) -I ../libft/includes/ $< -c -o $@

$(NAME_C): $(OBJ_CHECK)
	@$(CC) $(CFLGS) -o $(NAME_C) $(OBJ_CHECK) $(LFLGS)
	@echo "\033[32mCHECKER OK\033[0m"

$(OBJ_DIR_CHECK)%.o : $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR_CHECK) $(OBJ_DIR_CHECK)other $(OBJ_DIR_CHECK)checker
	$(CC) $(CFLGS) -MD -I $(SRC_INC_DIR) -I ../libft/includes/ $< -c -o $@

clean:
	@rm -rf obj
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(NAME_P)
	@echo "\033[31mPUSH_SWAP DEL\033[0m"
	@rm -rf $(NAME_C)
	@echo "\033[31mCHECKER DEL\033[0m"
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
