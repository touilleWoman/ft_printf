<<<<<<< HEAD
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

=======
>>>>>>> 0fca97f66ba6da7912f3d26d8c01072cd31f3657

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

<<<<<<< HEAD
SOURCE_NAME = ft_printf.c \
					pf_parse.c\
					pf_deal_with_double_percentage.c\
					pf_unit_list.c\
					ft_strlen.c\
					ft_strdup.c\
					ft_lstadd_top.c\
					ft_lstadd_bot.c\
					ft_lstnew.c\
					ft_strchr.c\
					ft_memcpy.c\


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
	$(CC) $(CFLAGS) $(NAME) srcs/test.c

clean:
	rm -f $(OBJ)
=======
SOURCE = ft_printf.c \
			pf_parse.c\
			pf_parse_cut_tu_unit.c\
			pf_unit_list.c\

OFILE = $(SOURCE:.c=.o)

HEADER = ft_printf.h pf_unit.h

LIBFTA = libft/libft.a

INC = -I ./libft

all:$(NAME)

$(NAME): $(OFILE)
	$(CC) $(CFLAGS) $(OFILE) $(LIBFTA) $(INC) -L  -o $(NAME)

%.o: %.c $(HEADER) $(LIBFTA)
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(LIBFTA): FORCE
	make -C ./libft

FORCE:

clean:
	rm -f $(OFILE)
>>>>>>> 0fca97f66ba6da7912f3d26d8c01072cd31f3657

fclean: clean
	rm -f $(NAME)

<<<<<<< HEAD
re:fclean all
=======
re:fclean all


>>>>>>> 0fca97f66ba6da7912f3d26d8c01072cd31f3657
