/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zero_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:39 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 15:52:15 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ns_zero_flags(t_fl *flags)
{
	flags->dump = 0;
	flags->d = 0;
	flags->v = 0;
	flags->n = 0;
}

t_champion	*ns_zero_champ(void)
{
	t_champion *temp;

	temp = (t_champion *)malloc(sizeof(t_champion));
	temp->exec_code = NULL;
	temp->file_size = 0;
	temp->id = 0;
	temp->magic = 0;
	temp->size_bytes = 0;
	temp->position_to_start = 0;
	temp->color = 0;
	return (temp);
}

t_cursor	*ns_zero_cursor(void)
{
	t_cursor	*temp;
	int			i;

	i = 0;
	temp = (t_cursor *)malloc(sizeof(t_cursor));
	temp->index_pos = 0;
	temp->nbr_player = 0;
	temp->step = 0;
	temp->wait_cycle = 0;
	temp->live_or_die = 0;
	temp->carry = 0;
	temp->color = 0;
	temp->champ = NULL;
	while (i < REG_NUMBER + 1)
		temp->registr[i++] = 0;
	return (temp);
}

void		ns_zero_info(t_info *info)
{
	info->total_cycles = 0;
	info->cycles_limit = 50;
	info->count_cursor = 0;
	info->cycles = 0;
	info->checks = MAX_CHECKS;
	info->winner_nbr = 0;
	info->winner_name = NULL;
	info->die = CYCLE_TO_DIE;
	info->end_game = 0;
	info->zdvig = 15;
}

void		ns_zero_reg(t_reg *reg)
{
	reg->r1 = 0;
	reg->r2 = 0;
	reg->r3 = 0;
	reg->dir = 0;
	reg->dir2 = 0;
	reg->index = 0;
}
