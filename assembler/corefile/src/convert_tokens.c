/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:19:10 by klee              #+#    #+#             */
/*   Updated: 2018/05/08 14:19:11 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

int				codage_args(int size, t_tokens *tokens)
{
	if (tokens->token == T_DIR)
		return (size + 2);
	if (tokens->token == T_REG)
		return (size + 1);
	if (tokens->token == T_IND)
		return (size + 3);
	return (ERROR);
}

int				code_dir(t_tokens *tokens, t_str_tokens *input,
				t_str_tokens *start_of_list, unsigned char **code)
{
	int				t_dir;
	unsigned int	result;

	result = 0;
	t_dir = search_size_of_label(input->valid);
	if (tokens->current_str_piece[1] == ':')
	{
		if (valid_label(
			tokens->current_str_piece + 2, start_of_list) == ERROR)
			return (error_messege(input, tokens, g_position));
		result = position_of_label(
			tokens->current_str_piece + 2, input, start_of_list);
	}
	else
		result = ft_atoi(tokens->current_str_piece + 1);
	write_dir_in_code(code, result, t_dir);
	return (OK);
}

void			when_size_dir_two(unsigned char **code, unsigned int result)
{
	result = (unsigned short int)result;
	(*code)[0] = result >> 8;
	(*code)++;
	(*code)[0] = result & 0xff;
	(*code)++;
}

void			when_size_dir_four(unsigned char **code, unsigned int result)
{
	(*code)[0] = result >> 24;
	(*code)++;
	(*code)[0] = (result & 0xff0000) >> 16;
	(*code)++;
	(*code)[0] = (result & 0xff00) >> 8;
	(*code)++;
	(*code)[0] = (result & 0xff);
	(*code)++;
}

void			when_size_dir_eight(unsigned char **code, unsigned int result)
{
	(*code)[0] = (result & 0xff00000000000000) >> 56;
	(*code)++;
	(*code)[0] = (result & 0xff000000000000) >> 48;
	(*code)++;
	(*code)[0] = (result & 0xff0000000000) >> 40;
	(*code)++;
	(*code)[0] = (result & 0xff00000000) >> 32;
	(*code)++;
	(*code)[0] = (result & 0xff000000) >> 24;
	(*code)++;
	(*code)[0] = (result & 0xff0000) >> 16;
	(*code)++;
	(*code)[0] = (result & 0xff00) >> 8;
	(*code)++;
	(*code)[0] = (result & 0xff);
	(*code)++;
}
