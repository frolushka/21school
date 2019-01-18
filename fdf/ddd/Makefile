# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 14:55:12 by edraugr-          #+#    #+#              #
#    Updated: 2019/01/17 14:10:45 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libddd.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ddd_matrix.c \
			ddd_line.c \
			ddd_mlx.c \
			ddd_vec2.c \
			ddd_vec3.c \
			ddd_vec4.c \
			ddd_convert.c \
			#draw_rect.c \

OBJ		=	$(SRC:.c=.o)

INC		=	-I. -I../libft -I../mlx

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
