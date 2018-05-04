/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:13:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/04 17:13:21 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"


//Узнать тип регистра

void	ns_or(t_cursor **cur, t_map *m_map)
{
	t_cursor *temp;
	unsigned char r1;
	unsigned char r2;
	unsigned char r3;

	temp = *cur;
	r1 = m_map->map[temp->index_pos + 2];
	r2 = m_map->map[temp->index_pos + 3];
	r3 = m_map->map[temp->index_pos + 4];
	temp->registr[r3] = r1 | r2;
	if (temp->registr[r3] == 0)
		temp->carry = 1;
	else
		temp->carry = 0;
}
