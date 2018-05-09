/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:10:03 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/03 16:10:04 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		validation(t_data *data_from_file, char *name_of_program)
{
	int				skipped_rows;
	t_str_tokens	*str_tokens;
	header_data_t	header_data;

	str_tokens = NULL;
	skipped_rows = 0;
	if (header_validation(data_from_file) == OK)
	{
		header_data = fill_header_data(data_from_file, name_of_program);
		skipped_rows = rows_before_operation(data_from_file);
		lexer(data_from_file, &str_tokens);
		if (parsing(str_tokens, skipped_rows) == OK)
			corefile(str_tokens, header_data, skipped_rows);
		free_str_tokens(&str_tokens);
		ft_strdel(&header_data.bot_comment);
		ft_strdel(&header_data.bot_name);
		ft_strdel(&header_data.program_name);
	}
	return (OK);
}
