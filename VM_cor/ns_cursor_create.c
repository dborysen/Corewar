/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_cursor_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:09:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/03 15:05:13 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		champ = champ->next;
		temp->next = (t_cursor *)malloc(sizeof(t_cursor));
		temp = temp->next;
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

void	ns_move_cursor(t_cursor **cursor, int *dead)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp->next)
	{
		if (temp->wait_cycle == 0 && temp->commad != 0)
		{
			//do instractions
			ft_printf("HELLO\n");
			temp->wait_cycle = 0;
			temp->commad = 0;
			*dead = 0;
		}
		else if (temp->wait_cycle != 0 && temp->commad != 0)
		{
			ft_printf("wait cycle = %d\n", temp->wait_cycle);
			temp->wait_cycle--;
			ft_printf("opcode = %d\n", temp->commad);
		}
		else
			temp->index_pos++;
		temp = temp->next;
	}
}

void	ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info)
{
	t_cursor	*temp;
	int 		dead;

	temp = *cursor;
	dead = 1;
	while (dead)
	{
		ns_create_cycle(&temp, m_map);
		ns_move_cursor(&temp, &dead);
		info->total_cycles++;
		ft_printf("total cycle = %d\n", info->total_cycles);
	}
}
