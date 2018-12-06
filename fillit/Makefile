# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 23:49:07 by sbednar           #+#    #+#              #
#    Updated: 2018/12/07 02:47:07 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SDIR	= ./src
ODIR	= ./obj
IDIR	= ./includes
LDIR	= ./libft

FILES	= $(shell find $(SDIR) -name "*.c" -type f)

SRC		= $(FILES:./src/%=%)
OBJ		= $(addprefix $(ODIR)/, $(SRC:.c=.o))
MAIN	= main.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:
	$(MAKE) -C $(LDIR) all
	$(MAKE) $(ODIR)
	$(MAKE) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -I $(IDIR) -L $(LDIR) -l ft -o $(NAME)

$(ODIR)/%.o:$(SDIR)/%.c
	$(CC) $(CFLAGS) -I $(IDIR) -o $@ -c $<

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

relib:
	$(MAKE) -C $(LDIR) re
	$(MAKE) re

.PHONY: all clean fclean re
