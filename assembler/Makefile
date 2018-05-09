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
		lexer/find_tokens.c\
		lexer/show_error.c\
		lexer/final_state_attributes.c\
		lexer/free_job.c\
		lexer/state_functions/first_five_state_column.c\
		lexer/state_functions/last_five_state_column.c\
		header_validation/header_validation.c\
		header_validation/name_and_comment_present_and_only_one.c\
		header_validation/brackets_validation.c\
		header_validation/show_header_error.c\
		header_validation/save_header.c\
		parser/src/parsing.c\
		parser/src/error_messege.c\
		validation.c\
		corefile/src/make_file.c\
		corefile/src/build_code.c\
		corefile/src/construct_data.c\
		corefile/src/convert_tokens.c\
		corefile/src/name_and_magic.c

OBJECT = $(SRCS:.c=.o)

INCLUDES = corewar.h

FLAGS = -Wall -Wextra -Werror

%.o	: %.c
		@gcc $(FLAGS) -I corewar.h -c $< -o $@
		@echo "\033[1mASM :\033[0m		 \033[37m[Compilation:\033[0m\033[36m $@\033[0m]"

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -I $(INCLUDES) -g $(SRCS) parser/libft/libft.a -o ./$(NAME)
	@echo "\033[5;32m--------------------------\033[0m"
	@echo "\033[5;32m         ASM - OK 😁       \033[0m"
	@echo "\033[5;32m--------------------------\033[0m"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) corewar.h

clean:
	@rm -f $(OBJECT) *.o
	@make clean -C $(LIBFT)
	@echo "\033[32m[.o files has been deleted]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[32m[asm binary has been deleted]\033[0m"

re: fclean all