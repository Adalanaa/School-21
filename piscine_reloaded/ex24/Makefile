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

all:
	@gcc -c -I includes srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
	@ar rc libft.a ft_putstr.o ft_strlen.o ft_putchar.o ft_strcmp.o ft_swap.o
clean:
	@rm -f libft.a
fclean:	clean
	@rm -f ft_putstr.o ft_strlen.o ft_putchar.o ft_strcmp.o ft_swap.o
re:	fclean all

