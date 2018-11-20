# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:43:21 by sbednar           #+#    #+#              #
#    Updated: 2018/11/20 17:06:48 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_display_file
SRCS=srcs
INCLUDES=includes

$(NAME): all

all:
	gcc -Wall -Werror -Wextra $(SRCS)/*.c -I $(INCLUDES) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
