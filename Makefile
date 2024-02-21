# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 13:47:56 by phwang            #+#    #+#              #
#    Updated: 2024/02/21 17:54:34 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJ_DIR = obj
SRC_DIR = src

LIBFT = -L./LIBFT -lft

SRC = \
	swap.c \
	push.c \
	reverse.c \
	rotate.c \
	count \
	build_pile.c \
	split_for_pushswap.c \
	check.c \
	main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))


CC = cc
CFLAGS = -Wall -Wextra -Werror


.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME) : $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all