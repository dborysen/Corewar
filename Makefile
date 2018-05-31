#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 15:58:45 by dborysen          #+#    #+#              #
#    Updated: 2018/05/30 15:58:45 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM = assembler

VM = VM

all:
	@make -C $(ASM)
	@cp assembler/asm ./
	@make -C $(VM)
	@cp VM/corewar ./

clean:
	@make clean -C $(ASM)
	@make clean -C $(VM)

fclean:
	@make fclean -C $(ASM)
	@rm -f asm
	@make fclean -C $(VM)
	@rm -f corewar

re: fclean all
