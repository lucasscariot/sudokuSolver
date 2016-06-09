# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 09:44:59 by lscariot          #+#    #+#              #
#    Updated: 2016/06/09 18:58:16 by lscariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= sudokuSolver

LINK	= ../sudokuSolver

CC		= clang

S_DIR	=

O_DIR	=

I_DIR	=

LFLAGS	=  -O3 -g -Wall -Wextra -Werror $(I_DIR) $(LIBS_DIR)

CFLAGS	=  -O3 -g -Wall -Wextra -Werror $(I_DIR) $(LIBS_DIR)

FILES	=	main.c				parsing/ft_save_grid.c		\
			errors/ft_error.c	algo/ft_algo.c				\

LIBS_F	= ./libft/libft.a

SRC		= $(addprefix $(S_DIR),$(FILES))

OBJS	= $(addprefix $(O_DIR),$(FILES:.c=.o))

LIBS	= $(addprefix -L. -l,$(LIBS_F))

RM		= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@echo ""
	@make -C libft
	@$(CC) -I./includes $(CFLAGS) $(LIBS_F) $^ -o $(LINK)
	@echo "\033[32m$(NAME) created.\033[0m"

$(O_DIR)%.o:		$(S_DIR)%.c
	@$(CC) $(LFLAGS) -I./includes -c $< -o $@
	@echo "\033[33m.\033[0m\c"

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: 	clean
	@$(RM) $(LINK)
	@make -C libft fclean
	@echo "\033[31m$(NAME) cleaned.\033[0m"

re:			fclean all

.PHONY: re clean fclean all
