# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 20:15:23 by edraugr-          #+#    #+#              #
#    Updated: 2018/12/22 03:54:02 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

LDIR	= ./minilibx
LNAME	= ./minilibx/libmlx.a
L2DIR	= ./libft
L2NAME	= ./libft/libft.a
L3DIR	= ./ddd
L3NAME	= ./ddd/libddd.a

SRC		= $(wildcard *.c)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
MAIN	= main.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(LNAME) $(OBJ)
		$(CC) $(OBJ) -I. -I$(LDIR) -I$(L2DIR) -I$(L3DIR) -L$(LDIR) -L$(L2DIR) -L$(L3DIR) -lmlx -lft -lddd -framework OpenGL -framework AppKit -o $(NAME)

$(LNAME):
		$(MAKE) -C $(LDIR) all
		$(MAKE) -C $(L2DIR) all
		$(MAKE) -C $(L3DIR) all

%.o:%.c
		$(CC)  -I. -I$(LDIR) -I$(L2DIR) -I$(L3DIR) -o $@ -c $<

clean:
		$(MAKE) -C $(LDIR) clean
		$(MAKE) -C $(L2DIR) clean
		$(MAKE) -C $(L3DIR) clean
		rm -f $(OBJ)

fclean: clean
		rm -f $(LNAME)
		rm -rf $(L2NAME)
		rm -rf $(L3NAME)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
