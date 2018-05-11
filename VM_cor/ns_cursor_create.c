/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 16:30:06 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

ns_array_of_functions g_func[16] =
{
		ns_live, ns_ld, ns_st, ns_add, ns_sub, ns_zjmp, ns_ldi, ns_sti, ns_lld,  ns_lldi,
		ns_aff
};

void		ns_create_cursor(t_cursor **cursor, t_champion *champ)
{
	t_cursor *temp;

	temp = *cursor;
	while (champ->next)
	{
		temp->wait_cycle = 0;
		temp->step = 0;
		temp->nbr_player = champ->id;
		temp->index_pos = champ->position_to_start;
		temp->commad = 0;
		temp->next = (t_cursor *)malloc(sizeof(t_cursor));
		temp->registr[1] = -temp->nbr_player;
		temp->champ = champ;
		temp = temp->next;
		champ = champ->next;
	}
}

void	ns_create_cycle(t_cursor **cursor, t_map *m_map)
{
	t_cursor	*temp;
	int 		i;

	temp = *cursor;
	while (temp->next)
	{
		i = 0;
		if (temp->wait_cycle == 0 && temp->commad == 0)
		{
			while (i < 16)
			{
				if (m_map->map[temp->index_pos] == g_op_tab[i].opcode)
				{
					temp->wait_cycle = g_op_tab[i].cycles;
					temp->commad = g_op_tab[i].opcode;
					break;
				}
				i++;
			}
		}
		temp = temp->next;
	}
}

void	ns_move_cursor(t_cursor **cursor, int *dead, t_map *map)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp->next)
	{
		if (temp->wait_cycle == 1 && temp->commad != 0)
		{
			/*
			 ** do instractions
			 */
			(*g_func[10])(&temp, map);
			temp->wait_cycle = 0;
			temp->commad = 0;
			*dead = 0;
		}
		else if (temp->wait_cycle != 0 && temp->commad != 0)
			temp->wait_cycle--;
		else
			temp->index_pos++;
		if (temp->index_pos >= MEM_SIZE)
			temp->index_pos %= MEM_SIZE;
		temp = temp->next;
	}
}

void	ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl)
{
	t_cursor	*temp;
	int 		dead;

	temp = *cursor;
	dead = 1;
	while (fl.dump > 0)
	{
		ns_create_cycle(&temp, m_map);
		ns_move_cursor(&temp, &dead, m_map);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == CYCLE_TO_DIE)
		{
			ns_check_lives(temp, &info);
			info->cycles = 0;
			ft_printf("die = %d : checks %d\n", info->die, info->checks);
		}
		fl.dump--;
//		ft_printf("total cycle = %d\n", info->total_cycles);
	}
}
