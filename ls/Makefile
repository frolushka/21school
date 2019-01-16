# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/31 20:35:25 by sbednar           #+#    #+#              #
#    Updated: 2018/12/31 21:11:32 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

LIB_DIR		=	./lib
SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc

FT_DIR		=	$(addprefix $(LIB_DIR)/,libft)
FT_INC_DIR	=	$(addprefix $(FT_DIR)/,inc)

FT			=	$(addprefix $(FT_DIR)/,libft.a)

SRC			= 	ft_ls.c \
				main.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=

all: $(NAME)

$(NAME): $(FT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -I$(FT_INC_DIR) -L$(FT_DIR) -lft -o $(NAME)

$(FT):
	$(MAKE) -C $(FT_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(FT_INC_DIR) -o $@ -c $<

clean:
	$(MAKE) -C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re