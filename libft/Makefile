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

FILES	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILES	+=	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c
FILES	+=	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c
FILES	+=	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c
FILES	+=	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c
FILES	+=	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c
FILES	+=	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c
FILES	+=	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
FILES	+=	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

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
