/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lldi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:47:23 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:41:18 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	lldi_rrr(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	str = NULL;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		str = find_fbytes_tind(m_map, (temp->index_pos +
							(temp->registr[reg.r1] + temp->registr[reg.r2])));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 5;
	free(str);
}

void	lldi_rdr(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	str = NULL;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 3, temp->index_pos + 4);
		str = find_fbytes_tind(m_map, (temp->index_pos +
									(reg.dir + temp->registr[reg.r1])));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}
