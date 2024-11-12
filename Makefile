NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -rf  *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
