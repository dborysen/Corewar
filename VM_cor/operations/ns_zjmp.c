/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:47:23 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/21 16:21:22 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_zjmp(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;

	temp = *cur;
	if (temp->carry == 1)
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 1, temp->index_pos + 2);
		temp->index_pos += reg.dir % IDX_MOD;
		temp->index_pos = temp->index_pos < 0 ? temp->index_pos + MEM_SIZE :
												temp->index_pos % MEM_SIZE;
	}
	else
		temp->index_pos += 3;
}
