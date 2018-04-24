/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:40:23 by klee              #+#    #+#             */
/*   Updated: 2018/04/17 17:40:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../libft/includes/libft.h"


t_op		op_tab[17]=
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

/*
** check all list
*/

int			parsing(t_str_tokens *input, int count)
{
	int		*op;
	int		i;

	i = 1;
	while(input)
	{
		op = after_label(input, i + count);
		input = input->next;
		i++;
	}
	return (0);
}

int			*after_label(t_str_tokens *input, int index)
{
	t_tokens	*input_tokens;
	char	*operation;
	t_op		args;

	input_tokens = input->valid;
	operation = NULL;
	if (input_tokens->token == T_LAB)
		input_tokens = input_tokens->next;
	if (input_tokens->token == OPERATION)
		operation = input_tokens->current_str_piece;
	else
		error_messege(input, input_tokens, index);
	args = f_arguments(operation);
	if (args.name != 0)
		check_the_args(args, input, index);
	return(0);
}

/*
** find array of arguments in op_tab
*/

t_op			f_arguments(char *operation)
{
	int		i;

	i = 0;
	if (operation == NULL)
		return (op_tab[16]);
	while (i < 17)
	{
		if (ft_strcmp(op_tab[i].name, operation) == 0)
			return (op_tab[i]);
		i++;
	}
	return (op_tab[16]);
}

/*
** check arguments
*/

int			check_the_args(t_op args, t_str_tokens *input, int index)
{
	int			i;
	t_tokens	*input_tokens;
	int			result;

	i = 0;
	result = 0;
	input_tokens = input->valid;
	if (input_tokens->token == T_LAB)
	{
		input_tokens = input_tokens->next;
		input_tokens = input_tokens->next;
	}
	result = number_of_arguments(args, input, index) == -1 ? (-1) : 0;
	while (input_tokens && i < args.numb)
	{
		if (input_tokens->token != SEP_CHAR)
		{
			if (((input_tokens->token & args.arg[i]) == 0))
				result = (error_messege_for_arguments(input_tokens, args, i));
			i++;
		}
		input_tokens = input_tokens->next;
	}
	return (result);
}

int			number_of_arguments(t_op args, t_str_tokens *input, int index)
{
	int			i;
	t_tokens	*input_tokens;

	i = 0;
	input_tokens = input->valid;
	if (input_tokens->token == T_LAB)
	{
		input_tokens = input_tokens->next;
		input_tokens = input_tokens->next;
	}
	if (input_tokens->token == OPERATION)
		input_tokens = input_tokens->next;
	while (input_tokens)
	{
		if (input_tokens->token != SEP_CHAR && input_tokens->token != EOL)
		{
			i++;
			if (i > args.numb)
				return (error_messege(input, input_tokens, index));
		}
		input_tokens = input_tokens->next;
	}
	if (i < args.numb)
		return error_messege_if_not_enough(args);
	return (0);
}

/*
**	error messege
*/

int			error_messege(t_str_tokens *input,
			t_tokens *input_tokens,int index)
{
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	ft_printf("Syntax error at token [TOKEN][%03d:%03d]\"%s\"\n",index,
	(ft_strstr(input->current_str,input_tokens->current_str_piece)
	- input->current_str), input_tokens->current_str_piece);
	return (ERROR);
}

int		error_messege_for_arguments(t_tokens *input_tokens, t_op args, int i)
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
	i, str, args.str);
	return (ERROR);
}

int			error_messege_if_not_enough(t_op args)
{
	ft_printf("Invalid parameter count for instruction %s\n", args.name);
	return (ERROR);
}