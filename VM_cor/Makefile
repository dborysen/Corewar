# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 13:21:38 by myprosku          #+#    #+#              #
#    Updated: 2018/05/30 13:47:36 by myprosku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIBFT = ./libft/

SRCS =  main.c create_map.c dump_flag.c ns_additional_func.c ns_additional_func2.c \
        ns_additional_func3.c ns_cursor_create.c ns_error.c ns_read_champion.c \
        ns_save_fch.c ns_zero_struct.c start_game.c \
        operations/ns_add.c operations/ns_aff.c operations/ns_and.c operations/ns_and2.c \
        operations/ns_fork.c operations/ns_ld.c operations/ns_ldi.c operations/ns_ldi2.c \
        operations/ns_live.c operations/ns_lld.c operations/ns_lldi.c operations/ns_lldi2.c \
        operations/ns_or.c operations/ns_or2.c operations/ns_st.c operations/ns_sti.c \
        operations/ns_sti2.c operations/ns_sub.c operations/ns_xor.c operations/ns_xor2.c \
        operations/ns_zjmp.c ncurses/first.c ncurses/second.c ncurses/third.c

OBJECT = $(SRCS:.c=.o)

INCLUDES = corewar.h

FLAGS = -Wall -Wextra -Werror

%.o	: %.c
		@gcc $(FLAGS) -c $< -o $@
		@echo "\033[1mVM :\033[0m		 \033[37m[Compilation:\033[0m\033[36m $@\033[0m]"

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -lncurses -I $(INCLUDES) $(SRCS) ./libft/libft.a -o ./$(NAME)
	@echo "\033[5;32m--------------------------\033[0m"
	@echo "\033[5;32m   Virtual machine - OK   \033[0m"
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
	@echo "\033[32m[corewar binary has been deleted]\033[0m"

re: fclean all