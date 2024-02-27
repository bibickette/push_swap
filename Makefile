# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 13:47:56 by phwang            #+#    #+#              #
#    Updated: 2024/02/27 14:04:34 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJ_DIR = obj
SRC_DIR = src

LIBFT = -L./LIBFT -lft

SRC = \
	cmd_swap.c \
	cmd_push.c \
	cmd_reverse.c \
	cmd_rotate.c \
	ft_find.c \
	ft_set.c \
	ft_free.c \
	ft_count \
	hell_sort.c \
	tiny_sort.c \
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
	make -s -C LIBFT
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean :
	make -s -C LIBFT clean
	rm -rf $(OBJ_DIR)

fclean : clean
	make -s -C LIBFT fclean
	rm -f $(NAME)

re : fclean all