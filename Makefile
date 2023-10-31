SRCS	=	functions.c		\
			ft_itoa.c		\
			ft_printf.c		\
			ft_uns_itoa.c	\
			types.c			\

OBJS	=	$(SRCS:.c=.o)
NAME	=	libftprintf.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re
