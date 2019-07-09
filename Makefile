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
					pf_unit_list.c\

SOURCE_PATH = ./srcs

SOURCE = $(addprefix $(SOURCE_PATH)/, $(SOURCE_NAME))

OBJ = $(SOURCE:.c=.o)

HEADER = ft_printf.h pf_unit.h

LIBFTA = libft/libft.a

INC = -I ./libft

all:$(NAME)

$(NAME): $(OBJ) $(LIBFTA)
	ar rc $(NAME) $(OBJ) $(LIBFTA)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(LIBFTA): FORCE
	make -C ./libft

FORCE:


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all