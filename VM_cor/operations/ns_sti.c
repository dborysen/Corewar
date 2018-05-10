/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:32:43 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/10 14:59:33 by myprosku         ###   ########.fr       */
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
	reg.r2 = map_t->map[temp->index_pos + 3];
	reg.r3 = map_t->map[temp->index_pos + 4];
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + (temp->registr[reg.r2] + temp->registr[reg.r3]) % IDX_MOD);
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

void	set_on_map_rdr(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;

	map_t = *map;
	i = 0;
	reg.dir = (map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	reg.r3 = map_t->map[temp->index_pos + 4];
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + (reg.dir + temp->registr[reg.r3]) % IDX_MOD);
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

void	set_on_map_rdd(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map	*map_t;

	map_t = *map;
	i = 0;
	reg.dir = (map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	reg.dir2 = (map_t->map[temp->index_pos + 5] << 8) | (map_t->map[temp->index_pos + 6]);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + (reg.dir + reg.dir2) % IDX_MOD);
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
	int i;
	int pos;
	char *str;
	t_map *map_t;
	char *move_bytes;

	map_t = *map;
	i = 0;
	reg.index = (short)(map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	move_bytes = find_fbytes_tind(*map, (reg.index % IDX_MOD));
	reg.index = char_to_int(move_bytes);
	reg.dir2 = (map_t->map[temp->index_pos + 5] << 8) | (map_t->map[temp->index_pos + 6]);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + (reg.index + reg.dir2) % IDX_MOD);
	reg.index = reg.index % MEM_SIZE;
	while (i < 4) {
		pos = reg.index + i;
		if (pos < 0)
			pos = MEM_SIZE + pos;
		if (pos >= MEM_SIZE)
			pos = pos % MEM_SIZE;
		map_t->map[pos] = (unsigned char) str[i];
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
	reg.index = (short)(map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	move_bytes = find_fbytes_tind(*map, (temp->index_pos + (reg.index % IDX_MOD)));
	reg.index = char_to_int(move_bytes);
	reg.r3 = map_t->map[temp->index_pos + 5];
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = (temp->index_pos + (reg.index + temp->registr[reg.r3]) % IDX_MOD);
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

void	ns_sti(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*temp;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	if (m_map->map[temp->index_pos + 1] == T_RRR)
	{
		set_on_map_rrr(&m_map, *cur, reg);
		temp->index_pos += 5;
	}
	else if (m_map->map[temp->index_pos + 1] == T_RDR)
	{
		set_on_map_rdr(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
	else if (m_map->map[temp->index_pos + 1] == T_RDD)
	{
		set_on_map_rdd(&m_map, *cur, reg);
		temp->index_pos += 7;
	}
	else if (m_map->map[temp->index_pos + 1] == T_RID)
	{
		set_on_map_rid(&m_map, *cur, reg);
		temp->index_pos += 7;

	}
	else if (m_map->map[temp->index_pos + 1] == T_RIR)
	{
		set_on_map_rir(&m_map, *cur, reg);
		temp->index_pos += 6;
	}
}
