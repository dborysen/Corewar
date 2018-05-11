/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:13:52 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 16:06:26 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_lld2(t_cursor **cur, t_map *m_map, t_reg reg, char *str)
{
	t_cursor *temp;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 4];
	if (ns_check_register(reg.r1, 1, 1))
	{
		reg.index = (short) (m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
		str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
		reg.index = char_to_int(str);
		temp->registr[reg.r1] = reg.index;
		if (temp->registr[reg.r1] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 5;
}

void	ns_lld(t_cursor **cur, t_map *m_map)
{
	t_cursor 	*temp;
	t_reg		reg;
	char 		*str;

	temp = *cur;
	str = NULL;
	ns_zero_reg(&reg);
	if (m_map->map[temp->index_pos + 1] == T_DR)
	{
		reg.r1 = m_map->map[temp->index_pos + 6];
		if (ns_check_register(reg.r1, 1, 1))
		{
			str = find_fbytes_tind(m_map, temp->index_pos + 2);
			reg.index = char_to_int(str); // reg.dir ?? cast to short
			temp->registr[reg.r1] = reg.index;
			if (temp->registr[reg.r1] == 0)
				temp->carry = 1;
			else
				temp->carry = 0;
		}
		temp->index_pos += 7;
	}
	else if (m_map->map[temp->index_pos + 1] == T_IR)
		ns_lld2(cur, m_map, reg, str);
}
