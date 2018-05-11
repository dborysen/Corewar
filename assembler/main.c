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

void	show_usage(char *str)
{
	ft_printf("\n\e[1;37mUSAGE:	%s <sourcefile.s>\e[0m\n\n", str);
}

int		main(int argc, char **argv)
{
	t_data	*data_from_file;
	int		i;

	i = 1;
	data_from_file = NULL;
	if (argc > 1)
		while (i < argc)
		{
			ft_printf("\n\n\e[1;4;37m%s\e[0m\n", argv[i]);
			read_data(&data_from_file, argv[i]);
			validation(data_from_file, argv[i]);
			free_list(&data_from_file);
			i++;
		}
	else
		show_usage(argv[argc - 1]);
	return (0);
}
