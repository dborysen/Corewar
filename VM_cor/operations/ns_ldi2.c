/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_ldi2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:35:15 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:45:38 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ldi_rrr(t_cursor **cur, t_map *m_map)
{
	t_cursor		*tmp;
	t_reg			reg;
	unsigned char	*str;

	tmp = *cur;
	str = NULL;
	reg.r1 = m_map->map[(tmp->index_pos + 2) % MEM_SIZE];
	reg.r2 = m_map->map[(tmp->index_pos + 3) % MEM_SIZE];
	reg.r3 = m_map->map[(tmp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		str = find_fbytes_tind(m_map, (tmp->index_pos +
				((tmp->registr[reg.r1] + tmp->registr[reg.r2]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		tmp->registr[reg.r3] = reg.index;
	}
	tmp->index_pos += 5;
	free(str);
}

void	ldi_rdr(t_cursor **cur, t_map *m_map)
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
							((reg.dir + temp->registr[reg.r1]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 6;
	free(str);
}
