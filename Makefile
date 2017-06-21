#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 14:13:03 by efedorov          #+#    #+#              #
#    Updated: 2017/02/23 14:31:46 by efedorov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC =  main.c \
	fill_map.c \
	create_map.c \
	ft_atoi.c \
	ft_putendl.c \
	ft_strnew.c \
	ft_strsplit.c \
	ft_putchar.c \
	get_next_line.c \
	ft_strsub.c \
	ft_putstr.c \
	ft_strjoin.c \
	ft_strlen.c \

OBJ = $(SRC:.c=.o)

HEADER = fdf.h

OFLAGS = -Wall -Wextra -Werror -c

FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OFLAGS) $(SRC)
		gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
