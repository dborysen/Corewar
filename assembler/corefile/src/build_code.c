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

unsigned char	*build_code(
	t_str_tokens *input, t_str_tokens *start_of_list)
{
	unsigned char			*code;
	unsigned char			*start_of_code;
	t_tokens				*tokens;

	code = NULL;
	tokens = input->valid;
	start_of_code = code;
	if (input->size > 0)
	{
		code = malloc(sizeof(char) * input->size);
		start_of_code = code;
		while (tokens)
		{
			if (tokens->token != T_LAB && tokens->token != EOL)
				convert_token(tokens, input, start_of_list, &code);
			tokens = tokens->next;
		}
	}
	return (start_of_code);
}

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

int				code_reg(
	t_tokens *tokens, t_str_tokens *input, unsigned char **code)
{
	char	*str;
	int		result;

	str = tokens->current_str_piece;
	str++;
	result = ft_atoi(str);
	if (result >= 100)
		return (error_messege(input, tokens, g_position));
	else
	{
		(*code)[0] = result;
		(*code)++;
		return (OK);
	}
	return (result);
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
