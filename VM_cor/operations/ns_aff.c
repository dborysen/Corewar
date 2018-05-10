/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:09:04 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/10 17:14:32 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_aff(t_cursor **cur, t_map *m_map)
{
	t_reg reg;

	if (m_map->map[(*cur)->index_pos + 1] == T_REG)
	{
		reg.r1 =  m_map->map[(*cur)->index_pos + 2];
		ft_printf("Aff = %C\n", (*cur)->registr[reg.r1] % 256);
	}
	(*cur)->index_pos += 3;
}
