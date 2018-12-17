# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 00:43:10 by sbednar           #+#    #+#              #
#    Updated: 2018/12/16 18:25:08 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

#LDIR	= ./libft
#LNAME	= ./libft/libft.a

SRC		= ft_printf.c
OBJ		= $(SRC:.c=.o)
MAIN	= main.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(CFLAGS) $(OBJ) -I. -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
