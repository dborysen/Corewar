# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 15:43:03 by klee              #+#    #+#              #
#    Updated: 2018/04/24 15:43:06 by klee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parser
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS_PREFIX = ./src
SRCS = parsing.c error_messege.c
OBJ = $(SRCS:.c=.o)
SRCS_DIR = $(addprefix $(SRCS_PREFIX)/, $(SRCS))
LIB = ./libft/libft.a
INCL = ./incl
INCL_LIB = ./libft/includes

all:
	make re -C libft/
	$(CC) $(FLAGS) -I $(INCL) -I $(INCL_LIB) -c $(SRCS_DIR)
clean:
	rm -f $(OBJ)
	make clean -C libft/
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
re: fclean all