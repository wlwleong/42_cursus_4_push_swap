# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 16:31:15 by wlwleong          #+#    #+#              #
#    Updated: 2022/04/16 16:31:23 by wlwleong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c push_swap.c push_swap_utils.c

SOURCES_DIR		=	.
HEADER_DIR		=	.
OBJ_DIR			=	objects

HEADER			=	$(HEADER_DIR)/push_swap.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -ggdb3
RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

all: 				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
					@echo "\033[32mPush_swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(LIBFT):
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
					@$(RM) $(OBJ_DIR)

fclean: 			clean
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME)
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:					fclean all

.PHONY:				all clean fclean re libft
