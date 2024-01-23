SRCS	=	ft_printf.c / functions.c

NAME	=	libftprintf.a

GCC		=	gcc -Wall -Wextra -Werror

RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

.c.o:		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

clean:		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(OBJS)

re:			fclean $(NAME)

.SHORTCUT:	all clean fclean re

