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

#include "../corewar.h"

// int     main(int argc, char **argv)
// {
// 	t_data	*data_from_file;

//     data_from_file = NULL;
// 	if (argc == 2)
// 	{
// 		read_data(&data_from_file, *argv);
// 		validation(data_from_file);
// 		free_list(&data_from_file);
// 	}
//     return (0);
// }

int     main(void)
{
	t_data	*data_from_file;

    data_from_file = NULL;
	read_data(&data_from_file);
	validation(data_from_file, "name of program");
	free_list(&data_from_file);
    return (0);
}

// MAKE VALID ';' COMMENT STRINGS