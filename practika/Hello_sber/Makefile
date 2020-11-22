# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <kplums@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:18:23 by kplums            #+#    #+#              #
#    Updated: 2019/10/18 14:32:12 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mission_sber
SRC = main_sber.c
GCC = gcc -Wall -Wextra -Werror

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): clean
	$(GCC) $(SRC)  -o $(NAME)

clean:
	rm -f $(NAME)

