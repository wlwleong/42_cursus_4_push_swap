# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 21:14:03 by wlow              #+#    #+#              #
#    Updated: 2022/04/16 16:13:00 by wlwleong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar
ARFLAGS =	rcs
RM	=	rm -rf

FILES	=	ft_isdigit.c ft_memmove.c ft_atoi.c ft_strncmp.c ft_strdup.c
FILES	+=	ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
FILES	+=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
FILES	+=	ft_lstadd_back.c ft_lstclear.c

HEADER	=	libft.h

OBJ_DIR	=	../objects
OBJECTS	=	$(FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJECTS) $(HEADER)
		@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
		@echo "\033[33m----Compiling libft----"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)

fclean:	clean
		@$(RM) $(NAME)

re: 		fclean all

.PHONY: 	clean fclean all re
