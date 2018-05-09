/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:15:43 by klee              #+#    #+#             */
/*   Updated: 2018/05/08 14:15:44 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

void			construct_data(t_str_tokens *input)
{
	int				position;
	t_str_tokens	*track;

	position = 0;
	track = input;
	while (track)
	{
		track->position = position;
		track->size = count_bytes(track);
		position = position + track->size;
		track = track->next;
	}
}

int				count_bytes(t_str_tokens *input)
{
	t_tokens	*tokens;
	int			t_dir;
	int			size;

	size = 0;
	tokens = input->valid;
	if (tokens->token == T_LAB)
		tokens = tokens->next;
	if (tokens->token == OPERATION)
	{
		size++;
		t_dir = search_size_of_label(tokens);
		if (op_with_codage(tokens) == OK)
			size++;
		tokens = tokens->next;
		size = size + size_of_arg(tokens, t_dir);
	}
	return (size);
}

int				op_with_codage(t_tokens *tokens)
{
	if (!ft_strcmp(tokens->current_str_piece, "live"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "zjmp"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "fork"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "lfork"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "aff"))
		return (ERROR);
	return (OK);
}

int				size_of_arg(t_tokens *tokens, int t_dir)
{
	int			size;

	size = 0;
	while (tokens)
	{
		if (tokens->token == T_REG)
			size = size + 1;
		if (tokens->token == T_DIR)
			size = size + t_dir;
		if (tokens->token == T_IND)
			size = size + 2;
		tokens = tokens->next;
	}
	return (size);
}

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
