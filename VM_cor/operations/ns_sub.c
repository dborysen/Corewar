/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:09:29 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/17 15:08:42 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_sub(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_RRR)
	{
		reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
		reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
		reg.r3 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
		if (reg.r1 == 14 || reg.r2 == 14 || reg.r3 == 14)
			ft_printf("ADD\n");
		if (ns_check_register(reg.r1, reg.r2, reg.r3))
		{
			temp->registr[reg.r3] = temp->registr[reg.r1] - temp->registr[reg.r2];
			temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
		}
		temp->index_pos += 5;
	}
	else
		temp->index_pos += ns_step_wrong_codage(m_map->map[(temp->index_pos + 1) % MEM_SIZE]);
}