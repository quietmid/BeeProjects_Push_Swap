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

LIBFT = ./libft/libft.a

SRC = ./SRC/instruction.c \
	  ./SRC/push_swap.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Color ANSI Code
BOLD   := \033[1m./SRC/
RED    := \033[31;1m
GREEN  := \033[32;1m
YELLOW := \033[33;1m
BLUE   := \033[34;1m
MAGENTA   := \033[35;1m
CYAN      := \033[36;1m
WHITE     := \033[37;1m
RESET     := \x1b[0m #reseting the text formatting to default state

OBJECTS_DIR = obj
OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
		@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
		@echo "$(CYAN)--------------------------------"
		@echo "$(NAME) = You can now Push Swap and Rotate!"
		@echo "$(CYAN)--------------------------------$(RESET)"

$(LIBFT):
		@$(MAKE) -C ./libft

$(OBJECTS_DIR)/%.o: ./SRC/%.c
		@mkdir -p $(OBJECTS_DIR)
		@echo "Compiled $(GREEN) $^ $(RESET)"
		@$(CC) $(CFLAGS) -c -o $@ $^

clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJECTS_DIR)/*.o
		@if [ -f "$(OBJECTS_DIR)" ]; then rmdir -p $(OBJECTS_DIR); fi
		@echo "$(WHITE) $(OBJECTS_DIR) $(GREEN) REMOVED"

fclean: clean
		@$(MAKE) fclean -C ./libft
		@rm -rf $(NAME)
		@echo "$(WHITE) $(PROJECT) $(RESET) $(GREEN) SO CLEANED"

re: fclean all

.PHONY: all clean fclean re bonus