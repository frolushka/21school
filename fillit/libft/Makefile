# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 23:40:02 by sbednar           #+#    #+#              #
#    Updated: 2018/12/07 02:36:00 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

SDIR	= ./src
IDIR	= ./includes
ODIR	= ./obj

FILES	= $(shell find $(SDIR) -name "*.c" -type f)

SRC		= $(FILES:./src/%=%)
OBJ		= $(addprefix $(ODIR)/, $(SRC:.c=.o))

CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(ODIR)/%.o:$(SDIR)/%.c
	$(CC) $(CFLAGS) -I $(IDIR) -o $@ -c $<

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
