# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <kplums@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:37 by kplums            #+#    #+#              #
#    Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl
SOURCES = main.c get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY: clean fclean all re

all: $(NAME)


$(NAME):
	@make -C libft/ fclean && make -C libft/
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -g -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft
clean:
	@rm -f $(OBJECTS)
	@make -C libft/ clean

fclean:	clean
	@rm -f $(NAME)

re: fclean all

