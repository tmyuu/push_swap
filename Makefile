# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 19:52:08 by ymatsui           #+#    #+#              #
#    Updated: 2024/02/20 14:51:33 by ymatsui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./ft_printf
LFLAGS = -L./ft_printf -lftprintf

SRC_DIR = src

SRC = $(wildcard src/*.c)

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./ft_printf
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C ./ft_printf clean

fclean: clean
	rm -rf $(OBJ_DIR) $(NAME)
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
