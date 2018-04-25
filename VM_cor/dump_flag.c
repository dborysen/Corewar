/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:02:24 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/24 18:11:37 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_dump_flag(t_champion *champ, t_map memory_map)
{
	t_champion *temp;

	temp = champ;
	while (temp->next)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
				  temp->id, temp->prog_size, temp->prog_name, temp->comment);
		temp = temp->next;
	}
}


