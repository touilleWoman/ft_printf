
.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

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

fclean: clean
	rm -f $(NAME)

re:fclean all


