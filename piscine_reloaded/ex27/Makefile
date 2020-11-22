# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <kplums@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:55:18 by kplums            #+#    #+#              #
#    Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_display_file.c
NAME = ft_display_file
OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Werror -Wall -Wextra -c $(SOURCE)
	@gcc -Werror -Wall -Wextra -I ft_head.h $(OBJECT) -o $(NAME)
clean:
	@rm -f $(OBJECT)
fclean:	clean
	@rm -f $(NAME)