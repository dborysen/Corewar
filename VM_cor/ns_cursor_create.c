/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/24 18:27:31 by myprosku         ###   ########.fr       */
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
		temp->color = champ->color + 5;
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

void		ns_reverse_champ(t_champion **champ)
{
	t_champion *prev;
	t_champion *current;
	t_champion *next;

	prev = NULL;
	current = *champ;
	while (current->next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*champ = prev;
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

int			check_id_playe(int id, t_info *info)
{
	t_champion *temp;

	temp = info->champion;
	while (temp)
	{
		if (id == temp->id)
			return (1);
		temp = temp->next;
	}
	return (0);
}

char		*find_name_id(int id, t_info *info)
{
	t_champion *temp;

	temp = info->champion;
	while (temp)
	{
		if (id == temp->id)
			return (temp->champ_name);
		temp = temp->next;
	}
	return (NULL);
}

t_cursor	*ns_move_cursor(t_cursor **cursor, t_map *map, t_info **info)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp)
	{
		temp->index_pos = temp->index_pos < 0 ? temp->index_pos + MEM_SIZE :
						  temp->index_pos % MEM_SIZE;
		temp->before_pos = temp->index_pos;
		if (map->color[temp->index_pos] < 5)
			map->color[temp->index_pos] = temp->color;
		else if (map->color[temp->index_pos] == 5)
			map->color[temp->index_pos] = 10;
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
			if (check_id_playe(temp->champ_nbr, *info))
			{
				if (!map->d && !map->v)
					ft_printf("A process shows that player %d (%s) is alive\n",
							  temp->champ_nbr, find_name_id(temp->champ_nbr, *info));
				(*info)->winner_nbr = temp->champ_nbr;
				(*info)->winner_name = find_name_id(temp->champ_nbr, *info);
			}
			temp->champ_nbr = 0;
			temp->commad = 0;
			temp->wait_cycle = 0;
		}
		else if (temp->wait_cycle != 0 && temp->commad != 0) {
			temp->wait_cycle--;
		}
		else
			temp->index_pos++;
		temp->index_pos = temp->index_pos < 0 ? temp->index_pos + MEM_SIZE :
						  temp->index_pos % MEM_SIZE;
		temp = temp->next;
	}
	return (*cursor);
}

t_cursor	*game_start_dump(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl)
{
	t_cursor *temp;

	info->winner_nbr = info->champion->id;
	info->winner_name = info->champion->champ_name;
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
	if (info->end_game == 1)
		ft_printf("Player %d, (\"%s\") has won !!\n", info->winner_nbr, info->winner_name);
	return (*cursor);
}

t_cursor	*game_start(t_cursor **cursor, t_map *m_map, t_info *info)
{
	t_cursor *temp;

	info->winner_nbr = info->champion->id;
	info->winner_name = info->champion->champ_name;
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
	ft_printf("Player %d, (\"%s\") has won !!\n", info->winner_nbr, info->winner_name);
	return (*cursor);
}


