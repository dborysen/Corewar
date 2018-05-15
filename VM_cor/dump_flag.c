/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:02:24 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/14 14:35:44 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_dump_flag(t_champion *champ)
{
	t_champion *temp;

	temp = champ;
	ft_printf("Introducing contestants...\n");
	while (temp->next)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
				  temp->id, temp->size_bytes, temp->champ_name, temp->champ_comment);
		temp = temp->next;
	}
}
