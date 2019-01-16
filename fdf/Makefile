# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/06 16:23:16 by sbednar           #+#    #+#              #
#    Updated: 2019/01/16 00:03:29 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRC_DIR		=	./src
OBJ_DIR		=	./obj

DDD_DIR		=	./ddd
MLX_DIR		=	./mlx
FT_DIR		=	./libft

SRC			= 	main.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS		=	-I./src -I./ddd -I./mlx -I./libft
LIBS		=	-L./libft -L./mlx -L./ddd -lft -lmlx -lddd -framework OpenGL -framework AppKit

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-o1

all: $(NAME)
	@echo "\033[92m\033[1mALL DONE\033[0m\033[0m"

$(NAME):
	@echo "\033[91m\033[1m[1/6] \033[97m\033[1mddd all:\033[0m"
	@$(MAKE) -C $(DDD_DIR) all
	@echo "\033[91m\033[1m[2/6] \033[97m\033[1mmlx all:\033[0m"
	@$(MAKE) -C $(MLX_DIR) all
	@echo "\033[91m\033[1m[3/6] \033[97m\033[1mlibft all:\033[0m"
	@$(MAKE) -C $(FT_DIR) all
	@echo "\033[91m\033[1m[4/6] \033[97m\033[1mobjects folder create:\033[0m"
	mkdir -p $(OBJ_DIR)
	@echo "\033[91m\033[1m[5/6] \033[97m\033[1mc files compile:\033[0m"
	@$(MAKE) $(OBJ)
	@echo "\033[91m\033[1m[6/6] \033[97m\033[1mexecutable compile:\033[0m"
	$(CC) $(CFLAGS) $(INCS) $(LIBS) $(OBJ)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	@echo "\033[91m\033[1m[1/4] \033[97m\033[1mddd clean:\033[0m"
	@$(MAKE) -C $(DDD_DIR) clean
	@echo "\033[91m\033[1m[2/4] \033[97m\033[1mmlx clean:\033[0m"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[91m\033[1m[3/4] \033[97m\033[1mlibft clean:\033[0m"
	@$(MAKE) -C $(FT_DIR) clean
	@echo "\033[91m\033[1m[4/4] \033[97m\033[1mobjects folder delete:\033[0m"
	rm -rf $(OBJ_DIR)
	@echo "\033[92m\033[1mCLEAN DONE\033[0m\033[0m"

fclean: clean
	@echo "\033[91m\033[1m[1/4] \033[97m\033[1mddd full clean:\033[0m"
	@$(MAKE) -C $(DDD_DIR) clean
	@echo "\033[91m\033[1m[2/4] \033[97m\033[1mmlx full clean:\033[0m"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[91m\033[1m[3/4] \033[97m\033[1mlibft full clean:\033[0m"
	@$(MAKE) -C $(FT_DIR) clean
	@echo "\033[91m\033[1m[4/4] \033[97m\033[1mexecutable delete:\033[0m"
	rm -f $(NAME)
	@echo "\033[92m\033[1mFCLEAN DONE\033[0m\033[0m"

re: fclean all
	@echo "\033[92m\033[1mRE DONE\033[0m\033[0m"

.PHONY: all clean fclean re