# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:32:24 by sbednar           #+#    #+#              #
#    Updated: 2018/11/20 16:39:27 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=srcs
INCLUDES=includes

$(NAME): all

all:
	gcc -Wall -Werror -Wextra -c $(SRCS)/ft_*.c -l $(INCLUDES)
	ar rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
