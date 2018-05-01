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

FT_PRINTF = ft_printf

SRCS =  main.c lexer/read_data.c lexer/lexer.c lexer/free_job.c lexer/state_functions/0-4_state_column.c lexer/state_functions/5-9_state_column.c header_validation/header_validation.c parser/src/parsing.c parser/src/error_messege.c

OBJECT = main.o read_data.o lexer.o free_job.o 0-4_state_column.o 5-9_state_column.o parser/parsing.o parser/error_message.o header_validation.o parsing.o error_messege.o

INCLUDES = lexer/ft_printf/ft_printf.h 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(FT_PRINTF)
	@gcc $(FLAGS) -I corewar.h $(SRCS) parser/libft/libft.a -o ./$(NAME)

%.o: %.c
	gcc $(FLAGS) -I lem_in.h -c $< 

comp:
	make -C parser
	@gcc  $(FLAGS) -I ../corewar.h $(SRCS) -g parser/libft/libft.a -o ./$(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) corewar.h

clean:
	@rm -f $(OBJECT)
	@make clean -C $(FT_PRINTF)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)

re: fclean all