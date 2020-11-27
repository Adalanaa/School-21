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

ARRAY_FILES		=	ft_countarrtochar.c \
					ft_lenarrtochar.c \
					ft_newarrchar.c

CHAR_FILES		=	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_tolower.c \
					ft_toupper.c

GNL_FILES		=	get_next_line.c

INT_FILES		=	ft_int_abs.c \
					ft_int_abs_min.c \
					ft_int_arr_check.c \
					ft_int_arr_max.c \
					ft_int_arr_min.c \
					ft_int_max.c \
					ft_int_min.c

LIST_FILES		=	ft_lst1add.c \
					ft_lst1del.c \
					ft_lst1delcont.c \
					ft_lst1delone.c \
					ft_lst1delone.c \
					ft_lst1map.c \
					ft_lst1new.c

MEMORY_FILES	=	ft_bzero.c \
					ft_malloc.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c

OUTPUT_FILES 	=	ft_error.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
                    ft_putnbr_fd.c \
					ft_putstr.c \
					ft_putstr_fd.c \

PRINTF_FILES	=	a_ft_printf.c \
					b_parser.c \
					c_doit.c \
					d_buff_write.c \
					doit_c.c \
					doit_di.c \
					doit_f.c \
					doit_lf.c \
					doit_ouxx_1.c \
					doit_ouxx_2.c \
					doit_p.c \
					doit_persent.c \
					doit_s.c

STRING_FILES		=	ft_checkline_int_space.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
                    ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strnstr.c \
					ft_strsub.c \
					ft_strtrim.c

XTOY_FILES		=	ft_atoi.c \
					ft_atoi_longlong.c \
					ft_itoa.c \
					ft_itoa_base.c

#			HEADERS			#
INCLUDES 		=	ft_printf.h \
					get_next_line.h \
					libft.h
INCL_DIR = ./includes/
HEADERS = $(addprefix $(INCL_DIR), $(INCLUDES))
DEPS = $(HEADERS) Makefile

# 			COMPILING		#
CFLGS = -Wall -Werror -Wextra
CC = gcc
IFLAGS = -I $(INCL_DIR)

#			SRC FILES			#
SRC_DIR		=	./src/
ARRAY_DIR	=	$(SRC_DIR)array/
CHAR_DIR	=	$(SRC_DIR)char/
GNL_DIR		=	$(SRC_DIR)gnl/
INT_DIR		=	$(SRC_DIR)int/
LIST_DIR	=	$(SRC_DIR)list/
MEMORY_DIR	=	$(SRC_DIR)memory/
OUTPUT_DIR	=	$(SRC_DIR)output/
PRINTF_DIR	=	$(OUTPUT_DIR)/ft_printf/
STRING_DIR	=	$(SRC_DIR)string/
XTOY_DIR	=	$(SRC_DIR)xtoy/

ARRAY_SRC	= 	$(addprefix $(ARRAY_DIR),$(ARRAY_FILES))
CHAR_SRC	= 	$(addprefix $(CHAR_DIR),$(CHAR_FILES))
GNL_SRC		= 	$(addprefix $(GNL_DIR),$(GNL_FILES))
INT_SRC		= 	$(addprefix $(INT_DIR),$(INT_FILES))
LIST_SRC	= 	$(addprefix $(LIST_DIR),$(LIST_FILES))
MEMORY_SRC	= 	$(addprefix $(MEMORY_DIR),$(MEMORY_FILES))
OUTPUT_SRC	= 	$(addprefix $(OUTPUT_DIR),$(OUTPUT_FILES))
PRINTF_SRC	= 	$(addprefix $(PRINTF_DIR),$(PRINTF_FILES))
STRING_SRC	= 	$(addprefix $(STRING_DIR),$(STRING_FILES))
XTOY_SRC	= 	$(addprefix $(XTOY_DIR),$(XTOY_FILES))

ALL_SRC		+=	$(ARRAY_SRC) $(CHAR_SRC) $(GNL_SRC) $(INT_SRC) $(LIST_SRC) \
				$(MEMORY_SRC) $(OUTPUT_SRC) $(PRINTF_SRC) $(STRING_SRC) \
				$(XTOY_SRC)

#			OBJECT FILES		#
OBJ_DIR			=	obj/
ARRAY_OBJ_DIR	=	$(OBJ_DIR)array/
CHAR_OBJ_DIR	=	$(OBJ_DIR)char/
GNL_OBJ_DIR		=	$(OBJ_DIR)gnl/
INT_OBJ_DIR		=	$(OBJ_DIR)int/
LIST_OBJ_DIR	=	$(OBJ_DIR)list/
MEMORY_OBJ_DIR	=	$(OBJ_DIR)memory/
OUTPUT_OBJ_DIR	=	$(OBJ_DIR)output
PRINTF_OBJ_DIR	=	$(OUTPUT_OBJ_DIR)/ft_printf/
STRING_OBJ_DIR	=	$(OBJ_DIR)string/
XTOY_OBJ_DIR	=	$(OBJ_DIR)xtoy/

OBJ				= 	$(ALL_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#___________________________
.PHONY: all clean fclean re so

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLIBFT OK\033[0m"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(ARRAY_OBJ_DIR) $(CHAR_OBJ_DIR) $(GNL_OBJ_DIR) $(INT_OBJ_DIR) \
	$(LIST_OBJ_DIR) $(MEMORY_OBJ_DIR) $(OUTPUT_OBJ_DIR) $(PRINTF_OBJ_DIR) \
	$(STRING_OBJ_DIR) $(XTOY_OBJ_DIR)
	$(CC) $(CFLGS) -MD -I $(INCL_DIR) $< -c -o $@

clean:
	@rm -rf $(OBJ_DIR);

fclean: clean
	@rm -rf $(NAME);
	@echo "\033[31mLIBFT DEL\033[0m"

re: fclean all

