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

NAME = libft.a
SOURCES = \
ft_putchar.c ft_strlcat.c ft_putchar_fd.c ft_strlen.c ft_putendl.c \
ft_strmap.c ft_atoi.c ft_putendl_fd.c ft_strmapi.c ft_bzero.c ft_putnbr.c \
ft_strncat.c ft_isalnum.c ft_putnbr_fd.c ft_strncmp.c ft_isalpha.c ft_putstr.c \
ft_strncpy.c ft_isascii.c ft_putstr_fd.c ft_strnequ.c ft_isdigit.c ft_strcat.c \
ft_strnew.c ft_isprint.c ft_strchr.c ft_strnstr.c ft_itoa.c ft_strclr.c \
ft_strrchr.c ft_memalloc.c ft_strcmp.c ft_strsplit.c ft_memccpy.c ft_strcpy.c \
ft_strstr.c ft_memchr.c ft_strdel.c ft_strsub.c ft_memcmp.c ft_strdup.c \
ft_strtrim.c ft_memcpy.c ft_strequ.c ft_tolower.c ft_memdel.c ft_striter.c \
ft_toupper.c ft_memmove.c ft_striteri.c ft_memset.c ft_strjoin.c \
\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
\
ft_lenarrtochar.c ft_countarrtochar.c ft_newarrchar.c ft_lstlen.c \
ft_lstdelcont.c

OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

.PHONY: clean fclean all re
.SUFFIXES:  .c .o

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@ -I.

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

