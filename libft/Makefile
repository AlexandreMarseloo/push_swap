# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 13:59:44 by almarsel          #+#    #+#              #
#    Updated: 2020/10/10 07:18:41 by almarsel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putstr.c ft_isdigit.c ft_atoll.c ft_strcmp.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstget_min.c ft_lstget_max.c ft_lstswap.c

OBJET = $(SRCS:.c=.o)

INCLUDE = libft.h

all : $(NAME)

$(NAME): $(OBJET) $(INCLUDE)
	ar -rc $(NAME) $(OBJET)
	ranlib $(NAME)

clean :
	rm -f $(OBJET)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
