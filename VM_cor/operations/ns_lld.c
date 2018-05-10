/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:13:52 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/10 13:29:27 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_lld(t_cursor **cur, t_map *m_map)
{
	t_cursor 	*temp;
	t_reg		reg;
	char 		*str;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_DR)
	{
		reg.r1 = m_map->map[temp->index_pos + 6];
		str = find_fbytes_tind(m_map, temp->index_pos + 2);
		reg.index = char_to_int(str); // reg.dir ?? cast to short
		temp->registr[reg.r1] = reg.index;
		temp->index_pos += 7;
	}
	else if (m_map->map[temp->index_pos + 1] == T_IR)
	{
		reg.r1 = m_map->map[temp->index_pos + 4];
		reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
		reg.index = char_to_int(str);
		temp->registr[reg.r1] = reg.index;
		temp->index_pos += 5;
	}
	if (temp->registr[reg.r1] == 0)
		temp->carry = 1;
	else
		temp->carry = 0;
}
