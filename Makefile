# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 09:16:21 by jleblond          #+#    #+#              #
#    Updated: 2019/07/09 09:16:23 by jleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SOURCE_NAME = ft_printf.c \
					pf_parse.c\
					pf_deal_with_double_percentage.c\
					pf_parse_tools.c\
					pf_parse_type_c_s.c\
					pf_parse_type_d.c\
					pf_unit_list.c\
					pf_field_check.c \
					pf_print_c_s_ltr.c\
					ft_strlen.c\
					ft_strdup.c\
					ft_lstadd_top.c\
					ft_lstadd_bot.c\
					ft_lstnew.c\
					ft_strchr.c\
					ft_strcpy.c\
					ft_strncpy.c\
					ft_bzero.c \
					ft_memcpy.c\
					ft_memset.c\
					ft_atoi.c\
					ft_isdigit.c\
					ft_putstr.c\
					ft_strcat.c\
					pf_test_functions.c\

SOURCE_PATH = ./srcs

SOURCE = $(addprefix $(SOURCE_PATH)/, $(SOURCE_NAME))

OBJ = $(SOURCE:.c=.o)

HEADER = ft_printf.h pf_unit.h

all:$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<


check:all
	$(CC) $(CFLAGS) $(NAME) srcs/test.c  -g -ggdb -fsanitize=address -I ./srcs

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all

