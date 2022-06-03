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

SOURCES_FILES	=	main.c push_swap.c push_swap_utils.c operation_s_p.c
SOURCES_FILES	+=	operation_r.c operation_rr.c sort_small.c sort_utils_1.c
SOURCES_FILES	+=	sort_medium.c sort_medium_utils.c sort_utils_2.c
SOURCES_FILES	+=	sort_big.c sort_big_utils.c

BONUS_FILES		=	main_bonus.c
BONUS_FILES		+=	operation_s_p_bonus.c operation_r_bonus.c
BONUS_FILES		+=	operation_rr_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus
HEADER_DIR		=	includes
OBJ_DIR			=	objects

HEADER			=	$(HEADER_DIR)/push_swap.h
BONUS_HEADER	=	$(HEADER_DIR)/checker_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_SOURCES	=	$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJECTS	=	$(BONUS_SOURCES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	push_swap
BONUS_NAME		=	checker
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -ggdb3
RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(BONUS_HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

all: 				$(NAME)

bonus:				$(BONUS_NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
					@echo "\033[32mPush_swap Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(BONUS_NAME):		$(LIBFT) $(OBJ_DIR) $(BONUS_OBJECTS) $(BONUS_HEADER)
					@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(NAME)
					@cp $(NAME) $(BONUS_NAME)
					@echo "\033[32mPush_swap Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(LIBFT):
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
					@$(RM) $(OBJ_DIR)

fclean: 			clean
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME) $(BONUS_NAME)
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:					fclean all

.PHONY:				all clean fclean re libft bonus
