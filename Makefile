# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 13:47:56 by phwang            #+#    #+#              #
#    Updated: 2024/03/01 16:13:08 by phwang           ###   ########.fr        #
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
	ft_set_utils.c \
	ft_free.c \
	ft_count \
	hell_mekherbo_magic.c \
	hell_more.c \
	hell_sort.c \
	tiny_sort.c \
	build_pile.c \
	split_for_pushswap.c \
	check.c \
	main.c \
	print.c

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))


CC = cc
CFLAGS = -Wall -Wextra -Werror

#PROGRESS BAR
TOTAL_SRCS := $(words $(SRC))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[0;35m
COLOR_BLUE = \e[0;35m

.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects Push_Swap: $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "⭓"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"
	
$(NAME) : $(OBJ_DIR) $(OBJ)
	@echo "$(COLOR_BLUE)\nCompiling Push_Swap...$(COLOR_RESET)"
	@make -s -C LIBFT
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(COLOR_GREEN)Compilation complete !$(COLOR_RESET)        "

clean :
	@make -s -C LIBFT clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting Push_Swap... ✘✘✘$(COLOR_RESET)"
	@make -s -C LIBFT fclean
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)✘✘✘ Push_Swap fcleaned ! ✘✘✘$(COLOR_RESET)        "

re : fclean all