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

t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
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
	int		op;
	int		i;

	i = 1;
	op = 0;
	while (input)
	{
		if (after_label(input, i + count) == ERROR)
			op = ERROR;
		input = input->next;
		i++;
	}
	return (op);
}

int			after_label(t_str_tokens *input, int index)
{
	t_tokens	*input_tokens;
	char		*operation;
	t_op		args;

	input_tokens = input->valid;
	operation = NULL;
	if (input_tokens->token == EOL || input_tokens->token == COMMENT)
		return (OK);
	if (input_tokens->token == T_LAB)
		input_tokens = input_tokens->next;
	if (input_tokens->token == OPERATION)
		operation = input_tokens->current_str_piece;
	else if (input_tokens->token == EOL)
		return (OK);
	else if (input_tokens->token == T_ERROR)
		return (ERROR);
	else
		return (error_messege(input, input_tokens, index));
	args = f_arguments(operation);
	if (args.name != 0)
		return (check_the_args(args, input, index));
	else
		return (error_messege_for_operation(input, input_tokens, index));
	return (OK);
}

/*
** find array of arguments in g_op_tab
*/

t_op		f_arguments(char *operation)
{
	int		i;

	i = 0;
	if (operation == NULL)
		return (g_op_tab[16]);
	while (i < 17)
	{
		if (ft_strcmp(g_op_tab[i].name, operation) == 0)
			return (g_op_tab[i]);
		i++;
	}
	return (g_op_tab[16]);
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
		input_tokens = input_tokens->next;
	input_tokens = input_tokens->next;
	result = number_of_arguments(args, input, index) == -1 ? (-1) : 0;
	while (input_tokens && i < args.numb)
	{
		if (input_tokens->token == T_ERROR)
			return (ERROR);
		if (input_tokens->token != SEP_CHAR && input_tokens->token != COMMENT)
		{
			if (((input_tokens->token & args.arg[i]) == 0))
				result = (error_messege_for_arguments(
					input, input_tokens, args, index));
			i++;
		}
		input_tokens = input_tokens->next;
	}
	return (result);
}

int			number_of_arguments(t_op args, t_str_tokens *input, int index)
{
	int			i[2];
	t_tokens	*input_tokens;

	i[0] = 0;
	i[1] = 0;
	input_tokens = input->valid;
	if (input_tokens->token == T_LAB)
		input_tokens = input_tokens->next;
	input_tokens = input_tokens->next;
	while (input_tokens)
	{
		if (input_tokens->token == T_ERROR)
			return (0);
		if (input_tokens->token != EOL && input_tokens->token != COMMENT)
		{
			(input_tokens->token == SEP_CHAR) ? i[1]++ : i[0]++;
			if (i[0] > args.numb || i[1] >= args.numb)
				return (error_messege(input, input_tokens, index));
		}
		input_tokens = input_tokens->next;
	}
	if (i[0] < args.numb)
		return (error_messege_if_not_enough(input, args, index));
	return (0);
}
