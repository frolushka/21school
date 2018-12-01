# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 19:18:44 by sbednar           #+#    #+#              #
#    Updated: 2018/12/01 22:23:27 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = get_next_line.c main.c
OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -L. -l_ft -o $(NAME)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c -Ilibft $(SRCS)

debug:
	gcc $(FLAGS) $(SRCS) -L. -l_ft -Ilibft -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
