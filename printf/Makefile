# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 00:43:10 by sbednar           #+#    #+#              #
#    Updated: 2018/12/19 01:36:40 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	test

LDIR	= ./libft
LNAME	= ./libft/libft.a

SRC		=	ft_printf.c \
			main.c
OBJ		=	$(SRC:.c=.o)

CC		=	gcc -g
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LNAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I. -I$(LDIR) -L$(LDIR) -lft -o $(NAME)

$(LNAME):
	$(MAKE) -C $(LDIR) all

%.o:%.c
	$(CC) $(CFLAGS) -I. -I$(LDIR) -o $@ -c $<

clean:
	$(MAKE) -C $(LDIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(LNAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
