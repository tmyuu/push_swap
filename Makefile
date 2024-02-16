# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 19:52:08 by ymatsui           #+#    #+#              #
#    Updated: 2024/02/16 16:48:07 by ymatsui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
      push_swap.c \
      stack_prep.c \
      stack_utils.c \
      dfs.c \
      ft_push_utils.c \
      ft_rotate_utils.c \
      ft_r_rotate_utils.c \
      ft_search_utils.c \
      ft_swap_utils.c \
      
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
