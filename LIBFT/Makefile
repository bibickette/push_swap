# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:04:16 by phwang            #+#    #+#              #
#    Updated: 2024/03/16 21:22:25 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of my prog
NAME = libft.a
FT_PRINTF = ft_printf/libftprintf.a

#DIRECTORIES
SRC_DIR = src
OBJ_DIR = obj

#SRC FILES AND OBJECTS FILES, ALL FILES with the command : find . -name "ft_*.c"
SRC =  \
	ft_atoi.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

#PROGRESS BAR
TOTAL_SRCS := $(words $(SRC))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[34m
COLOR_BLUE = \e[34m

#COMPILER & FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Not a file
.PHONY: all clean fclean re 

#make start here
#compile the NAME then clean the OBJ
all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

#creer un dossier pour ranger les .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects Libft: $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♥"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"
	
	
#create the lib with the objects
$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(COLOR_BLUE)\nCompiling Libft...$(COLOR_RESET)"
	@make -s -C ft_printf
	@cp $(FT_PRINTF) .
	@mv libftprintf.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN)Libft complete !$(COLOR_RESET)        "

#cleaning the objects files
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C ft_printf clean

#first do clean then rm the lib
fclean: clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting Libft... ✘✘✘$(COLOR_RESET)"
	@rm -f $(NAME)
	@make -s -C ft_printf fclean
	@echo "$(COLOR_GREEN)✘✘✘ Libft fcleaned ! ✘✘✘$(COLOR_RESET)        "

re: fclean all
