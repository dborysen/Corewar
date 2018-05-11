/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:09:04 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 15:35:25 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_aff(t_cursor **cur, t_map *m_map)
{
	t_reg reg;

	if (m_map->map[(*cur)->index_pos + 1] == T_REG)
	{
		reg.r1 =  m_map->map[(*cur)->index_pos + 2];
		if (ns_check_register(reg.r1, 1, 1))
			ft_printf("Aff = %C\n", (*cur)->registr[reg.r1] % 256);
	}
	(*cur)->index_pos += 3;
}
