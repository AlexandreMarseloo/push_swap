
LIBFT = ./libft/libft.a

NAME = push_swap

SRCS = sources/test07.c

CC = gcc

INCLUDES = ./includes/push_swap.h

CFLAGS = -Werror -Wextra -Wall

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(INCLUDES) ./libft/libft.a $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
