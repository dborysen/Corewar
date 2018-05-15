/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:32:43 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/15 16:13:41 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_on_map_rrr(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;

	map_t = *map;
	i = 0;
	reg.r2 = map_t->map[(temp->index_pos + 3) % MEM_SIZE];
	reg.r3 = map_t->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = (temp->index_pos + ((temp->registr[reg.r2] + temp->registr[reg.r3]) % IDX_MOD));
		reg.index = reg.index % MEM_SIZE;
		while (i < 4)
		{
			pos = reg.index + i;
			if (pos < 0)
				pos = MEM_SIZE + pos;
			if (pos >= MEM_SIZE)
				pos = pos % MEM_SIZE;
			map_t->map[pos] = (unsigned char)str[i];
			i++;
		}
	}
}

void	set_on_map_rdr(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;

	map_t = *map;
	i = 0;
	reg.r3 = map_t->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes(map_t, (temp->index_pos + 3) % MEM_SIZE, (temp->index_pos + 4) % MEM_SIZE);
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = (temp->index_pos + ((reg.dir + temp->registr[reg.r3]) % IDX_MOD));
		reg.index = reg.index % MEM_SIZE;
		while (i < 4)
		{
			pos = reg.index + i;
			if (pos < 0)
				pos = MEM_SIZE + pos;
			if (pos >= MEM_SIZE)
				pos = pos % MEM_SIZE;
			map_t->map[pos] = (unsigned char)str[i];
			i++;
		}
	}
}

void	set_on_map_rdd(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;

	map_t = *map;
	i = 0;
	reg.dir = ns_two_bytes(map_t, (temp->index_pos + 3) % MEM_SIZE, (temp->index_pos + 4) % MEM_SIZE);
	reg.dir2 = ns_two_bytes(map_t, (temp->index_pos + 5) % MEM_SIZE, (temp->index_pos + 6) % MEM_SIZE);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + ((reg.dir + reg.dir2) % IDX_MOD));
	reg.index = reg.index % MEM_SIZE;
	while (i < 4)
	{
		pos = reg.index + i;
		if (pos < 0)
			pos = MEM_SIZE + pos;
		if (pos >= MEM_SIZE)
			pos = pos % MEM_SIZE;
		map_t->map[pos] = (unsigned char)str[i];
		i++;
	}
}

void	set_on_map_rid(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;
	char	*move_bytes;

	map_t = *map;
	i = 0;
	reg.index = ns_two_bytes(map_t, (temp->index_pos + 3) % MEM_SIZE, (temp->index_pos + 4) % MEM_SIZE);
	move_bytes = find_fbytes_tind(*map, (temp->index_pos + (reg.index % IDX_MOD)));
	reg.index = char_to_int(move_bytes);
	reg.dir2 = ns_two_bytes(map_t, (temp->index_pos + 5) % MEM_SIZE, (temp->index_pos + 6) % MEM_SIZE);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + ((reg.index + reg.dir2) % IDX_MOD));
	reg.index = reg.index % MEM_SIZE;
	while (i < 4)
	{
		pos = reg.index + i;
		if (pos < 0)
			pos = MEM_SIZE + pos;
		if (pos >= MEM_SIZE)
			pos = pos % MEM_SIZE;
		map_t->map[pos] = (unsigned char)str[i];
		i++;
	}
}

void	set_on_map_rir(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;
	char 	*move_bytes;

	map_t = *map;
	i = 0;
	reg.r3 = map_t->map[temp->index_pos + 5];
	if (ns_check_register(1, 1, reg.r3))
	{
		reg.index = ns_two_bytes(map_t, (temp->index_pos + 3) % MEM_SIZE, (temp->index_pos + 4) % MEM_SIZE);
		move_bytes = find_fbytes_tind(*map, (temp->index_pos + (reg.index % IDX_MOD)));
		reg.index = char_to_int(move_bytes);
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = (temp->index_pos + ((reg.index + temp->registr[reg.r3]) % IDX_MOD));
		reg.index %= MEM_SIZE;
		while (i < 4)
		{
			pos = reg.index + i;
			if (pos < 0)
				pos += MEM_SIZE;
			if (pos >= MEM_SIZE)
				pos %= MEM_SIZE;
			map_t->map[pos] = (unsigned char)str[i];
			i++;
		}
	}
}

void	ns_sti(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*temp;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RRR)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rrr(&m_map, *cur, reg);
		temp->index_pos += 5;
	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RDR)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rdr(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RDD)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rdd(&m_map, *cur, reg);
		temp->index_pos += 7;
	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RID)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rid(&m_map, *cur, reg);
		temp->index_pos += 7;

	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RIR)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map_rir(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
}
