# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 19:09:00 by kplums            #+#    #+#              #
#    Updated: 2020/11/12 19:09:02 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FILES		=	add_level.c \
				ant_and_comment.c \
				check_in.c \
				check_out.c \
				count_in_out.c \
				free.c \
				init.c \
				lemin.c \
				links.c \
				move.c \
				output.c \
				parser.c \
				path.c

#			HEADERS			#
SRC_INC_DIR = ./includes/
INCLUDES = lem-in.h
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
SRC_DIR		= ./src/
SRC			= $(addprefix $(SRC_DIR),$(FILES))

#			OBJECT FILES		#
OBJ_DIR			= obj/
OBJ				= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#___________________________
.PHONY: all clean fclean re FAKE

all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLGS) -o $(NAME) $(OBJ) $(LFLGS)
	@echo "\033[32mLEMIN OK\033[0m"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLGS) -MMD -I $(SRC_INC_DIR) -I $(LIB_INC_DIR) -o $@ -c $<

$(LIBFT): FAKE
	@$(MAKE) -C $(LIB_DIR)

clean:
	@rm -rf obj
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mLEMIN DEL\033[0m"
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
