/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:54 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/24 14:46:55 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int     main(void)
{
	t_data	*data_from_file;

    data_from_file = NULL;
    read_data(&data_from_file);
	validation(data_from_file);
    free_list(&data_from_file);
    return (0);
}

int		validation(t_data *data_from_file)
{
	t_str_tokens	*str_tokens;
	int				skipped_rows;

	str_tokens = NULL;
	skipped_rows = rows_before_operation(data_from_file);
	lexer(data_from_file, str_tokens);
	return (OK);
}
