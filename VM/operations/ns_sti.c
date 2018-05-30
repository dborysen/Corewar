/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:51:06 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 15:49:31 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_on_map(t_map **map, t_reg reg, unsigned char *str, t_cursor *temp)
{
	int		i;
	int		pos;
	t_map	*map_t;

	i = 0;
	map_t = *map;
	while (i < 4)
	{
		pos = reg.index + i;
		pos = pos < 0 ? pos + MEM_SIZE : pos % MEM_SIZE;
		map_t->map[pos] = str[i];
		map_t->color[pos] = temp->champ->color;
		i++;
	}
}

void	set_on_map_rrr(t_map **map, t_cursor *temp, t_reg reg)
{
	unsigned char *str;

	reg.r2 = (*map)->map[(temp->index_pos + 3) % MEM_SIZE];
	reg.r3 = (*map)->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = temp->index_pos + ((temp->registr[reg.r2] +
				temp->registr[reg.r3]) % IDX_MOD);
		reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
		ns_on_map(map, reg, str, temp);
		free(str);
	}
}

void	set_on_map_rdd(t_map **map, t_cursor *temp, t_reg reg)
{
	unsigned char *str;

	reg.dir = ns_two_bytes((*map), temp->index_pos + 3, temp->index_pos + 4);
	reg.dir2 = ns_two_bytes((*map), temp->index_pos + 5, temp->index_pos + 6);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = temp->index_pos + ((reg.dir + reg.dir2) % IDX_MOD);
	reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
	ns_on_map(map, reg, str, temp);
	free(str);
}

void	ns_sti2(t_cursor **cur, t_map *m_map, t_reg reg)
{
	t_cursor *temp;

	temp = *cur;
	if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 2) == T_RDD)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rdd(&m_map, *cur, reg);
		temp->index_pos += 7;
	}
	else if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 2) == T_RID)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rid(&m_map, *cur, reg);
		temp->index_pos += 7;
	}
	else
		temp->index_pos += ns_step_wrong_codage(
				m_map->map[(temp->index_pos + 1) % MEM_SIZE]);
}

void	ns_sti(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*temp;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 2) == T_RRR)
	{
		set_on_map_rrr(&m_map, *cur, reg);
		temp->index_pos += 5;
	}
	else if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 2) == T_RDR)
	{
		set_on_map_rdr(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
	else if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 2) == T_RIR)
	{
		set_on_map_rir(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
	else
		ns_sti2(cur, m_map, reg);
}
