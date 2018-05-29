/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:09:04 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 15:59:17 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_aff(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*tmp;

	tmp = *cur;
	if (m_map->map[(tmp->index_pos + 1) % MEM_SIZE] == REG_CODE)
	{
		reg.r1 = m_map->map[(tmp->index_pos + 2) % MEM_SIZE];
		if (ns_check_register(reg.r1, 1, 1) && !m_map->d && !m_map->v)
			ft_printf("Aff = %C\n", tmp->registr[reg.r1] % 256);
		tmp->index_pos += 3;
	}
	else
		tmp->index_pos += ns_step_wrong_codage(m_map->map[(tmp->index_pos + 1)
															% MEM_SIZE]);
}
