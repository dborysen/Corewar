/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zero_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:39 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 16:23:35 by myprosku         ###   ########.fr       */
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
	temp->life = 0;
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
	temp->carry = 0;
	while (i < 16)
		temp->registr[i++] = 0;
}

void	ns_zero_info(t_info *info)
{
	info->total_cycles = 0;
	info->cycles = 0;
	info->checks = MAX_CHECKS;
	info->winner = 0;
	info->die = CYCLE_TO_DIE;
}

void	ns_zero_reg(t_reg *reg)
{
	reg->r1 = 0;
	reg->r2 = 0;
	reg->r3 = 0;
	reg->dir = 0;
	reg->dir2 = 0;
	reg->index = 0;
}
