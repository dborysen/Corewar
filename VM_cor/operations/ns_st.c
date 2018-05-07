/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:38:50 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/07 18:00:13 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_on_map(t_map **map, t_cursor *temp, unsigned char r)
{
	int i;
	int pos;
	int ret;
	unsigned char *str;
	t_map *map_t = *map;

	i = 0;
	ret = (map_t->map[temp->index_pos + 3] << 8) | (map_t->map[temp->index_pos + 4]);
	str = int_to_unsigned_char(r);
//	while (i < 4)
//		ft_printf("bytes = %02x\n", str[i++]);
//	i = 0;
	pos = temp->index_pos + (ret % IDX_MOD);
	pos = pos % MEM_SIZE;
	while (i < 4)
	{
		pos += i;
		if (pos < 0)
			pos = MEM_SIZE + pos;
		if (pos >= MEM_SIZE)
			pos = pos % MEM_SIZE;
		map_t->map[pos] = str[i];
		i++;
	}
}

void	ns_st(t_cursor **cur, t_map *m_map)
{
	unsigned char	r;
	t_cursor		*temp;

	temp = *cur;
	r = m_map->map[temp->index_pos + 2];
	if (m_map->map[temp->index_pos + 1] == T_RR)
	{
		temp->registr[m_map->map[temp->index_pos + 3]] = r;
		temp->index_pos += 4;
	}
	else if (m_map->map[temp->index_pos + 1] == T_RI)
	{
		set_on_map(&m_map, temp, r);
		temp->index_pos += 5;
	}
}
