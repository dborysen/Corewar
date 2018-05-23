/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:56:51 by klee              #+#    #+#             */
/*   Updated: 2018/05/11 19:56:52 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

int			plus_validation(t_str_tokens *input)
{
	t_str_tokens		*start_of_list;
	t_str_tokens		*copy_input;
	unsigned char		*code;

	copy_input = input;
	start_of_list = input;
	code = NULL;
	while (copy_input)
	{
		g_position++;
		if (build_code(copy_input, start_of_list, &code) == ERROR)
		{
			free(code);
			return (ERROR);
		}
		free(code);
		copy_input = copy_input->next;
	}
	return (OK);
}

int			all_headers_filled(t_header_data header)
{
	if (header.bot_comment == NULL || header.bot_name == NULL)
		return (ERROR);
	return (OK);
}
