# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:03:39 by jlu               #+#    #+#              #
#    Updated: 2024/02/06 17:10:35 by jlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = push swap
NAME = push_swap

SRC =

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus