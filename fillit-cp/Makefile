# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 23:49:07 by sbednar           #+#    #+#              #
#    Updated: 2018/12/14 00:03:25 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

LDIR	= ./libft
LNAME	= ./libft/libft.a

SRC		= ft_dlist.c \
	ft_matrix_figs.c \
	ft_matrix.c \
	ft_reader.c \
	ft_solver.c
OBJ		= $(SRC:.c=.o)
MAIN	= main.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(LNAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -I. -I$(LDIR) -L$(LDIR) -lft -o $(NAME)

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
