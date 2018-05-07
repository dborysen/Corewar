#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:40:13 by dborysen          #+#    #+#              #
#    Updated: 2018/01/11 16:40:16 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

LIBFT = parser/libft

SRCS =  main.c\
		lexer/read_data.c\
		lexer/lexer.c\
		lexer/free_job.c\
		lexer/state_functions/0-4_state_column.c\
		lexer/state_functions/5-9_state_column.c\
		header_validation/header_validation.c\
		parser/src/parsing.c\
		parser/src/error_messege.c\
		validation.c

OBJECT = $(SRCS:.c=.o)

INCLUDES = corewar.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -I $(INCLUDES) -g $(SRCS) parser/libft/libft.a -o ./$(NAME)

%.o: %.c
	gcc $(FLAGS) -I corewar.h -c $< 

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) corewar.h

clean:
	@rm -f $(OBJECT) *.o
	@make clean -C $(LIBFT)
	@echo .o files has been deleted

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo asm binary has been deleted

re: fclean all