/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zero_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:39 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/03 16:55:34 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_zero_flags(t_fl *flags)
{
	flags->dump= 0;
	flags->v = 0;
	flags->n = 0;
}

void	ns_zero_champ(t_champion **champ)
{
	t_champion *temp;

	temp = *champ;
	temp->exec_code = NULL;
	temp->file_size = 0;
	temp->id = 0;
	temp->magic = 0;
	temp->size_bytes = 0;
	temp->position_to_start = 0;
}

void	ns_zero_cursor(t_cursor **cursor)
{
	t_cursor 	*temp;
	int 		i;

	i = 0;
	temp = *cursor;
	temp->index_pos = 0;
	temp->nbr_player = 0;
	temp->step = 0;
	temp->wait_cycle = 0;
	temp->live_or_die = 0;
	while (i < 16)
		temp->registr[i++] = 0;
}

void	ns_zero_info(t_info *info)
{
	info->total_cycles = 0;
}

