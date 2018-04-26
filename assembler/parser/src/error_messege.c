/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messege.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:22:27 by klee              #+#    #+#             */
/*   Updated: 2018/04/26 14:22:32 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../libft/includes/libft.h"

/*
**	error messege
*/

int			error_messege(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	char	*str;

	str = " ";
	if (input_tokens->token == T_DIR)
		str = " DIRECT ";
	if (input_tokens->token == T_IND)
		str = " INDIRECT ";
	if (input_tokens->token == T_REG)
		str = " REGISTER ";
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	ft_printf("Syntax error at token [TOKEN][%03d:%03d]%s\"%s\"\n",
	index, (ft_strstr(input->current_str, input_tokens->current_str_piece)
	- input->current_str), str, input_tokens->current_str_piece);
	return (ERROR);
}

int			error_messege_for_arguments(t_tokens *input_tokens,
t_op args, int i)
{
	char	*str;

	str = NULL;
	if (input_tokens->token == T_DIR)
		str = "register";
	if (input_tokens->token == T_IND)
		str = "indirect";
	if (input_tokens->token == T_REG)
		str = "direct";
	if (input_tokens->token == EOL)
		str = "end of line";
	ft_printf("Invalid parameter %d type %s for instruction %s\n",
	i, str, args.name);
	return (ERROR);
}

int			error_messege_if_not_enough(t_op args)
{
	ft_printf("Invalid parameter count for instruction %s\n", args.name);
	return (ERROR);
}

int			error_messege_for_operation(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d]\
	INSTRUCTION\"%s\"\n", index,
	(ft_strstr(input->current_str, input_tokens->current_str_piece)
	- input->current_str), input_tokens->current_str_piece);
	return (ERROR);
}
