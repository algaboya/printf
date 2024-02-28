NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_put_char.c ft_put_str.c ft_put_low_hex.c ft_put_up_hex.c ft_put_nbr.c ft_put_nbr_unsigned.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
