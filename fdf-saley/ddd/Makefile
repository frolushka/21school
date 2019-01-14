# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 14:55:12 by edraugr-          #+#    #+#              #
#    Updated: 2018/12/22 08:11:31 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libddd.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ddd_matrix.c \
			ddd_line.c \
			draw_rect.c \
			ddd_mlx.c \
			ddd_vec2.c \
			ddd_vec3.c \
			ddd_vec4.c \
			ddd_convert.c

OBJ		= $(SRC:.c=.o)

INC		= -I. -I../libft -I../minilibx

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
