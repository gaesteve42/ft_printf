SRCS	= ft_printf.c \
		ft_print_hexa.c \
		fonctions.c

NAME	= libftprintf.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

