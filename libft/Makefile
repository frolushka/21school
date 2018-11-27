# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 23:40:02 by sbednar           #+#    #+#              #
#    Updated: 2018/11/27 12:21:01 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_*.c
INCLUDES=ft_*.h
OBJS=$(SRCS:.c=.o)

$(NAME): all

all:
	gcc -Wall -Wextra -Werror $(SRCS) -c -I$(INCLUDES)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
