/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 17:16:48 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_array_functions		g_func[16] =
{
	ns_live, ns_ld, ns_st, ns_add, ns_sub, ns_and, ns_or, ns_xor,
	ns_zjmp, ns_ldi, ns_sti, 0, ns_lld, ns_lldi, 0, ns_aff
};

void					ns_create_cursor(t_cursor **cursor, t_champion *champ)
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
		temp->registr[1] = -temp->nbr_player;
		temp->color = champ->color + 5;
		temp->champ = champ;
		temp->next = (t_cursor *)malloc(sizeof(t_cursor));
		temp = temp->next;
		champ = champ->next;
	}
	temp->next = NULL;
}

void					ns_create_cycle(t_cursor **cursor, t_map *m_map)
{
	t_cursor	*temp;
	int			i;

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
					break ;
				}
				i++;
			}
		}
		temp = temp->next;
	}
}

void					ns_do_command(t_cursor **cursor, t_cursor *temp,
						t_map *map, t_info **info)
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
	if (check_id_player(temp->champ_nbr, *info))
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

t_cursor				*ns_move_cursor(t_cursor **cursor, t_map *map,
										t_info **info)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp)
	{
		temp->before_pos = temp->index_pos;
		if (map->color[temp->index_pos] < 5 && temp->color != 10)
			map->color[temp->index_pos] = temp->color;
		else if (map->color[temp->index_pos] < 5 && temp->color == 10)
			map->color[temp->index_pos] = map->color[temp->index_pos] + 5;
		else if (map->color[temp->index_pos] == 5)
			map->color[temp->index_pos] = 10;
		temp->color = map->color[temp->index_pos];
		if (temp->wait_cycle == 1 && temp->commad > 0)
			ns_do_command(cursor, temp, map, info);
		else if (temp->wait_cycle != 0 && temp->commad != 0)
			temp->wait_cycle--;
		else
			temp->index_pos++;
		temp->index_pos = temp->index_pos < 0 ? temp->index_pos + MEM_SIZE :
						temp->index_pos % MEM_SIZE;
		temp = temp->next;
	}
	return (*cursor);
}
