/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:47:23 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/18 17:27:33 by myprosku         ###   ########.fr       */
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
	}
	else
		temp->index_pos += 3;
}
