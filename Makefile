# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 10:02:08 by mbarutel          #+#    #+#              #
#    Updated: 2022/10/09 10:05:30 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = ft_select

CC 		= gcc
INC 	= -Iincs/
FLAG 	= -Werror -Wextra -Wall

LIBFT 		= libft
LIBFT_INC	= -L$(LIBFT) -lft
SRC_DIR 	= srcs/
OBJ_DIR 	= objs/

# Colors
DEF_COLOR 	= \033[0;39m
RED 		= \033[1;91m
BLUE 		= \033[1;94m
MAGENTA 	= \033[1;95m
CYAN 		= \033[1;96m

FILE = main

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@make -C $(LIBFT)
	@$(CC)  $(FLAG) $(OBJ) -o $@ $(LIBFT_INC)
	@echo "$(BLUE)Generated Executable -> $@$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -c $(INC) $(FLAG) $< -o $@
	@echo "$(CYAN)Generated Object File -> $<$(DEF_COLOR)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Deleted Objects Directory -> $(NAME)$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "$(MAGENTA)Deleted Library -> $(NAME)$(DEF_COLOR)"
	
re: fclean $(OBJ_DIR) all

.PHONY: all clean fclean re
