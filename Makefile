# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tristan <tristan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:22:29 by tristan           #+#    #+#              #
#    Updated: 2024/01/30 12:04:27 by tristan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

NAME = ft_ping

SRC = src/ft_ping.c \
	src/utils.c \

OBJ = $(SRC:.c=.o)

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

				
all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
		$(RM) $(OBJ)
		make -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all