/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/14 16:09:40 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

ns_array_of_functions g_func[16] =
{
		ns_live, ns_ld, ns_st, ns_add, ns_sub, ns_and, ns_or, ns_xor,
		ns_zjmp, ns_ldi, ns_sti, 0, ns_lld, ns_lldi, 0, ns_aff
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

void		ns_reverse_cursor(t_cursor **cursor)
{
	t_cursor *prev;
	t_cursor *current;
	t_cursor *next;

	prev = NULL;
	current = *cursor;
	while (current->next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*cursor = prev;
}

void	ns_create_cycle(t_cursor **cursor, t_map *m_map)
{
	t_cursor	*temp;
	int 		i;

	temp = *cursor;
	while (temp)
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

void	ns_move_cursor(t_cursor ***cursor, int *dead, t_map *map)
{
	t_cursor **temp;
	t_cursor *tmp;

	temp = *cursor;
	tmp = *temp;
	while (tmp)
	{
		if (tmp->wait_cycle == 1 && tmp->commad != 0)
		{
			if (tmp->commad == 12 || tmp->commad == 15)
			{
				if (tmp->commad == 12)
					ns_fork(cursor, &tmp, map, 1);
				else
					ns_fork(cursor, &tmp, map, 0);
			}
			else
				(*g_func[tmp->commad - 1])(&tmp, map);
			tmp->wait_cycle = 0;
			tmp->commad = 0;
			*dead = 0;
		}
		else if (tmp->wait_cycle != 0 && tmp->commad != 0)
			tmp->wait_cycle--;
		else
			tmp->index_pos++;
		if (tmp->index_pos >= MEM_SIZE)
			tmp->index_pos %= MEM_SIZE;
		if (tmp->index_pos < 0)
			tmp->index_pos += MEM_SIZE;
		tmp = tmp->next;
	}
}

void	ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl)
{
	int 		dead;

	dead = 1;
	while (fl.dump > 0)
	{
		ns_create_cycle(cursor, m_map);
		ns_move_cursor(&cursor, &dead, m_map);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == CYCLE_TO_DIE)
		{
			ns_check_lives(cursor, &info);
			info->cycles = 0;
		}
		fl.dump--;
	}
}
