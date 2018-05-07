/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:58:01 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/07 15:18:59 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_add(t_cursor **cur, t_map *m_map)
{
	t_cursor *temp;
	unsigned char r1;
	unsigned char r2;
	unsigned char r3;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == 0x54)
	{
		ft_printf("HERE\n");
		r1 = m_map->map[temp->index_pos + 2];
		r2 = m_map->map[temp->index_pos + 3];
		r3 = m_map->map[temp->index_pos + 4];
		if (ns_check_register(r1, r2, r3))
		{
			temp->registr[r3] = r1 + r2;
			temp->index_pos += 5;
			if (temp->registr[r3] == 0)
				temp->carry = 1;
			else
				temp->carry = 0;
		}
		else
			temp->index_pos += 5;
	}
	else
		temp->index_pos += 2;
}