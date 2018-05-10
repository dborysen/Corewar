/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:26:30 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/10 15:32:30 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ns_lldi4(t_cursor **cur, t_map *m_map, t_reg reg, char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_DDR)
	{
		reg.r3 = m_map->map[temp->index_pos + 6];
		reg.dir = (m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		reg.dir2 = (m_map->map[temp->index_pos + 4] << 8) | (m_map->map[temp->index_pos + 5]);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + reg.dir2)));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 7;
	}
	else if (m_map->map[temp->index_pos + 1] == T_IDR)
	{
		reg.r3 = m_map->map[temp->index_pos + 6];
		reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		reg.dir2 = (m_map->map[temp->index_pos + 4] << 8) | (m_map->map[temp->index_pos + 5]);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index % IDX_MOD)));
		reg.index = char_to_int(str);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index + reg.dir2)));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 6;
	}
	return (reg.r3);
}

int		ns_lldi3(t_cursor **cur, t_map *m_map, t_reg reg, char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_IRR)
	{
		reg.r2 = m_map->map[temp->index_pos + 4];
		reg.r3 = m_map->map[temp->index_pos + 5];
		reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index % IDX_MOD)));
		reg.index = char_to_int(str);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index + temp->registr[reg.r2])));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 6;
	}
	else
		reg.r3 = (ns_lldi4(cur, m_map, reg, str));
	return (reg.r3);
}

int		ns_lldi2(t_cursor **cur, t_map *m_map, t_reg reg, char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_DRR)
	{
		reg.r2 = m_map->map[temp->index_pos + 4];
		reg.r3 = m_map->map[temp->index_pos + 5];
		reg.dir = (m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + temp->registr[reg.r2])));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 6;
	}
	else if (m_map->map[temp->index_pos + 1] == T_DDR)
	{
		reg.r3 = m_map->map[temp->index_pos + 6];
		reg.dir = (m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		reg.dir2 = (m_map->map[temp->index_pos + 4] << 8) | (m_map->map[temp->index_pos + 5]);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + reg.dir2)));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 7;
	}
	else
		reg.r3 = ns_lldi3(cur, m_map, reg, str);
	return (reg.r3);
}

void	ns_lldi(t_cursor **cur, t_map *m_map)
{
	t_cursor 	*temp;
	t_reg		reg;
	char 		*str;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_RRR)
	{
		reg.r1 = m_map->map[temp->index_pos + 2];
		reg.r2 = m_map->map[temp->index_pos + 3];
		reg.r3 = m_map->map[temp->index_pos + 4];
		str = find_fbytes_tind(m_map, (temp->index_pos + (temp->registr[reg.r1] + temp->registr[reg.r2])));
		reg.index = char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->index_pos += 5;
	}
	else
		reg.r3 = ns_lldi2(cur, m_map, reg, str);
	if (temp->registr[reg.r3] == 0)
		temp->carry = 1;
	else
		temp->carry = 0;
}