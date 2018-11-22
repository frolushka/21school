# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 23:40:02 by sbednar           #+#    #+#              #
#    Updated: 2018/11/22 23:27:46 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out
SRCS=../srcs/ft_*.c
INCLUDES=../srcs/ft_*.h

$(NAME): all

all:
	gcc $(SRCS) main.c -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
