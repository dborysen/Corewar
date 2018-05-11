/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:38:50 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 15:42:04 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_on_map(t_map **map, t_cursor *temp, t_reg reg)
{
	int		i;
	int		pos;
	char	*str;
	t_map 	*map_t;

	map_t = *map;
	i = 0;
	reg.index = (short)(map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = temp->index_pos + (reg.index % IDX_MOD);
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

void	ns_st(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*temp;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	if (m_map->map[temp->index_pos + 1] == T_RR)
	{
		if (ns_check_register(reg.r1, 1, 1))
			temp->registr[m_map->map[temp->index_pos + 3]] = temp->registr[reg.r1];
		temp->index_pos += 4;
	}
	else if (m_map->map[temp->index_pos + 1] == T_RI)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map(&m_map, temp, reg);
		temp->index_pos += 5;
	}
}
