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

CC ?= gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

SOURCE_NAME = ft_printf.c \
					pf_parse.c\
					pf_parse_tools.c\
					pf_parse_type_c.c\
					pf_parse_type_s.c\
					pf_parse_type_d.c\
					pf_parse_type_f.c\
					pf_parse_type_p.c\
					pf_parse_type_oxx.c\
					pf_parse_type_u.c\
					pf_parse_type_b.c\
					pf_unit_list.c\
					pf_print_c_s_ltr.c\
					pf_print_d.c\
					pf_print_p.c\
					pf_print_oxx.c\
					pf_print_u.c\
					pf_print_f.c\
					pf_print_b.c\
					pf_dtoa.c\
					pf_itoa.c\
					pf_type_f_tool.c\
					ft_strlen.c\
					ft_strdup.c\
					ft_lstadd_bot.c\
					ft_lstnew.c\
					ft_strchr.c\
					ft_strcpy.c\
					ft_strncpy.c\
					ft_bzero.c \
					ft_memcpy.c\
					ft_memset.c\
					ft_memalloc.c\
					ft_atoi.c\
					ft_isdigit.c\
					ft_putstr_fd.c\
					ft_putstr.c \

SOURCE_PATH = ./srcs

SOURCE = $(addprefix $(SOURCE_PATH)/, $(SOURCE_NAME))

OBJ = $(SOURCE:.c=.o)

HEADER = $(SOURCE_PATH)/ft_printf.h $(SOURCE_PATH)/pf_unit.h

all:$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

check:all
	$(CC) $(CFLAGS) $(NAME) test_fd.c -g -ggdb -I ./srcs
# 	$(CC) $(CFLAGS) $(NAME) test_pft.c -g -ggdb -I ./srcs
# 	$(CC) $(CFLAGS) $(NAME) srcs/test_fd.c  -g -fsanitize=address -I ./srcs

clean:
	rm -f $(OBJ)
	rm -f $(SOURCE_PATH)/test_fd.o
	rm -f $(SOURCE_PATH)/test_pft.o
	rm -f run_tests

fclean: clean
	rm -f $(NAME)

re:fclean all
