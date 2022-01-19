# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 12:30:12 by mobrycki          #+#    #+#              #
#    Updated: 2021/05/29 12:30:15 by mobrycki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= 	algo.c \
			algoritmo.c \
			ritmo_supp_algo.c \
			algoritmo_continue.c \
			supp_algoritmo.c \
			moves.c \
			moves_due.c \
			moves_tre.c \
			moves_quattro.c \
			push_five.c \
			push_swap.c \
			push_three.c \
			push_four.c \
			push_two.c \
			ritmo.c \
			utils_due.c \
			utils.c \

OBJ		= $(SRCS:%.c=%.o)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all		:	$(NAME)

clean	:
			@rm -f *.txt
			@rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

