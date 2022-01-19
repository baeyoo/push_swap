# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 12:30:22 by mobrycki          #+#    #+#              #
#    Updated: 2021/05/29 12:30:24 by mobrycki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= checker
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
SRCS	= 	checker.c \
			gnl.c \
			moves.c \
			moves_2.c \
			moves_3.c \
			push.c \
			push_two.c \
			doppini.c \
			utils.c \

OBJ		= $(SRCS:%.c=%.o)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all		:	$(NAME)

clean	:
			@rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

