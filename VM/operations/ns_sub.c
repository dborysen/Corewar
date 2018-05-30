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
	t_cursor	*tmp;
	t_reg		reg;

	tmp = *cur;
	if ((m_map->map[tmp->index_pos + 1] >> 2) == T_RRR)
	{
		reg.r1 = m_map->map[(tmp->index_pos + 2) % MEM_SIZE];
		reg.r2 = m_map->map[(tmp->index_pos + 3) % MEM_SIZE];
		reg.r3 = m_map->map[(tmp->index_pos + 4) % MEM_SIZE];
		if (ns_check_register(reg.r1, reg.r2, reg.r3))
		{
			tmp->registr[reg.r3] = tmp->registr[reg.r1] - tmp->registr[reg.r2];
			tmp->carry = tmp->registr[reg.r3] == 0 ? 1 : 0;
		}
		tmp->index_pos += 5;
	}
	else
		tmp->index_pos += ns_step_wrong_codage(
				m_map->map[(tmp->index_pos + 1) % MEM_SIZE]);
}
