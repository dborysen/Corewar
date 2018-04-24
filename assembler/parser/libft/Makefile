# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 17:20:55 by klee              #+#    #+#              #
#    Updated: 2018/02/07 10:37:46 by klee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = f_accurancy_and_other.c\
	f_find_function.c\
	f_m_type_list.c\
	f_srch.c\
	f_support.c\
	ft_printf.c\
	lists.c\
	type_1.c\
	type_2.c\
	type_3.c\
	f_flags_plus.c\
	f_precision.c

SRCS_PREFIX = srcs

SRCS_DIR = $(addprefix $(SRCS_PREFIX)/, $(SRCS))

OBJECT = $(SRCS:.c=.o)


INLCUDE = ./includes/

all: $(NAME)

$(NAME):
	@make -C libft
	@mv libft/libft.a ./$(NAME)
	@gcc -Wall -Wextra -Werror -I $(INLCUDE) -c $(SRCS_DIR)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECT)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
