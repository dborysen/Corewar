/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:12:40 by klee              #+#    #+#             */
/*   Updated: 2018/05/08 14:12:41 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

t_byte_tab		g_b_tab[17] =
{
	{"live", 4, 0x01},
	{"ld", 4, 0x02},
	{"st", 0, 0x03},
	{"add", 0, 0x04},
	{"sub", 0, 0x05},
	{"and", 4, 0x06},
	{"or", 4, 0x07},
	{"xor", 4, 0x08},
	{"zjmp", 2, 0x09},
	{"ldi", 2, 0x0a},
	{"sti", 2, 0x0b},
	{"fork", 2, 0x0c},
	{"lld", 4, 0x0d},
	{"lldi", 2, 0x0e},
	{"lfork", 2, 0x0f},
	{"aff", 0, 0x10},
	{0, 0, 0}
};

int				convert_token(
	t_tokens *tokens, t_str_tokens *input,
	t_str_tokens *start_of_list, unsigned char **code)
{
	if (tokens->token == OPERATION)
		return (code_op(tokens, input, code));
	if (tokens->token == T_REG)
		return (code_reg(tokens, input, code));
	if (tokens->token == T_DIR)
		return (code_dir(tokens, input, start_of_list, code));
	if (tokens->token == T_IND)
		return (code_ind(tokens, input, start_of_list, code));
	else
		return (1);
	return (ERROR);
}

int				code_op(
	t_tokens *tokens, t_str_tokens *input, unsigned char **code)
{
	int		i;

	i = 0;
	while (g_b_tab[i].name)
	{
		if (ft_strcmp(g_b_tab[i].name, tokens->current_str_piece) == 0)
		{
			(*code)[0] = g_b_tab[i].code;
			(*code)++;
			break ;
		}
		i++;
	}
	if (op_with_codage(tokens) == OK)
	{
		(*code)[0] = codage(input);
		(*code)++;
	}
	return (OK);
}

int				code_ind(t_tokens *tokens, t_str_tokens *input,
	t_str_tokens *start_of_list, unsigned char **code)
{
	int res;

	if (tokens->current_str_piece[0] == ':')
	{
		if (valid_label(
		tokens->current_str_piece + 2, start_of_list) == ERROR)
			return (error_messege(input, tokens, g_position));
		res = position_of_label(
		tokens->current_str_piece + 1, input, start_of_list);
	}
	else
		res = ft_atoi(tokens->current_str_piece);
	when_size_dir_two(code, res);
	return (OK);
}

int				codage(t_str_tokens *input)
{
	int			size;
	t_tokens	*tokens;
	int			i;

	tokens = input->valid;
	size = 0;
	i = 3;
	while (i > 0 && tokens)
	{
		if (tokens->token == T_REG
			|| tokens->token == T_DIR || tokens->token == T_IND)
		{
			size = codage_args(size, tokens);
			size = size << 2;
			i--;
		}
		tokens = tokens->next;
	}
	if (i > 0)
		size = size << 2;
	return (size);
}

int				search_size_of_label(t_tokens *tokens)
{
	int		i;

	i = 0;
	if (tokens->token == T_LAB)
		tokens = tokens->next;
	while (g_b_tab[i].name)
	{
		if (ft_strcmp(g_b_tab[i].name, tokens->current_str_piece) == 0)
			return (g_b_tab[i].size);
		i++;
	}
	return (ERROR);
}
