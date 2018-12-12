# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 23:49:07 by sbednar           #+#    #+#              #
#    Updated: 2018/12/11 21:58:24 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
DNAME	= fillit.dSYM

SDIR	= ./src
ODIR	= ./obj
IDIR	= ./includes
LDIR	= ./libft
LIDIR	= $(LDIR)/includes

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
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -I $(IDIR) -I $(LIDIR) -L $(LDIR) -l ft -o $(NAME)

$(ODIR)/%.o:$(SDIR)/%.c
	$(CC) $(CFLAGS) -I $(IDIR) -I $(LIDIR) -o $@ -c $<

debug:
	$(MAKE) -C $(LDIR) all
	$(MAKE) $(ODIR)
	$(MAKE) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME) : $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) $(MAIN) -I $(IDIR) -I $(LIDIR) -L $(LDIR) -l ft -o $(NAME)

$(ODIR)/%.o:$(SDIR)/%.c
	$(CC) -g $(CFLAGS) -I $(IDIR) -I $(LIDIR) -o $@ -c $<

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

dfclean: clean
	rm -f $(NAME)
	rm -rf $(DNAME)

cleanlib:
	$(MAKE) -C $(LDIR) clean
	$(MAKE) clean

fcleanlib:
	$(MAKE) -C $(LDIR) fclean
	$(MAKE) fclean

re: fclean all

dre: dfclean debug

relib:
	$(MAKE) -C $(LDIR) re
	$(MAKE) re

.PHONY: all clean fclean re
