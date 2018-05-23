/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/23 17:14:07 by myprosku         ###   ########.fr       */
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
		temp->color = champ->color + 5;
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

t_cursor	*ns_move_cursor(t_cursor **cursor, t_map *map, t_info **info)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp)
	{
		temp->index_pos = temp->index_pos < 0 ? temp->index_pos + MEM_SIZE :
						  temp->index_pos % MEM_SIZE;
		map->color[temp->index_pos] = temp->color;
		if (temp->wait_cycle == 1 && temp->commad > 0)
		{
			if (temp->commad == 12)
			{
				*cursor = ns_fork(cursor, &temp, map, 1);
				(*info)->count_cursor++;
			}
			else if (temp->commad == 15)
			{
				*cursor = ns_fork(cursor, &temp, map, 0);
				(*info)->count_cursor++;
			}
			else
				(*g_func[temp->commad - 1])(&temp, map);
			if (temp->champ->life == 1)
			{
				(*info)->winner_nbr = temp->champ->id;
				(*info)->winner_name = temp->champ->champ_name;
			}
			temp->commad = 0;
			temp->wait_cycle = 0;
		}
		else if (temp->wait_cycle != 0 && temp->commad != 0) {
			temp->wait_cycle--;
		}
		else
			temp->index_pos++;
		temp = temp->next;
	}
	return (*cursor);
}

t_cursor	*game_start_dump(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl)
{
	t_cursor *temp;

	info->winner_nbr = (*cursor)->champ->id;
	info->winner_name = (*cursor)->champ->champ_name;
	while (fl.dump > 0 && info->end_game == 0)
	{
		temp = *cursor;
		ns_create_cycle(&temp, m_map);
		*cursor = ns_move_cursor(&temp, m_map, &info);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == info->die)
		{
			ns_check_lives(cursor, &info);
			info->cycles = 0;
		}
		fl.dump--;
	}
	if (fl.dump == 0)
		ns_print_map(*m_map);
	return (*cursor);
}

t_cursor	*game_start(t_cursor **cursor, t_map *m_map, t_info *info)
{
	t_cursor *temp;

	info->winner_nbr = (*cursor)->champ->id;
	info->winner_name = (*cursor)->champ->champ_name;
	while (info->end_game == 0)
	{
		temp = *cursor;
		ns_create_cycle(&temp, m_map);
		*cursor = ns_move_cursor(&temp, m_map, &info);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == info->die)
		{
			ns_check_lives(cursor, &info);
			info->cycles = 0;
		}
	}
	return (*cursor);
}


