/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:58:58 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:13:39 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_ld2(t_cursor **cur, t_map *m_map, t_reg reg, unsigned char *str)
{
	t_cursor *temp;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, 1))
	{
		reg.index = ns_two_bytes(m_map, temp->index_pos + 2,
								temp->index_pos + 3);
		str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r1] = reg.index;
		temp->carry = temp->registr[reg.r1] == 0 ? 1 : 0;
	}
	temp->index_pos += 5;
	free(str);
}

void	ns_ld(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	str = NULL;
	ns_zero_reg(&reg);
	if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 4) == T_DR)
	{
		reg.r1 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
		if (ns_check_register(reg.r1, 1, 1))
		{
			str = find_fbytes_tind(m_map, temp->index_pos + 2);
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r1] = reg.index;
			temp->carry = temp->registr[reg.r1] == 0 ? 1 : 0;
		}
		temp->index_pos += 7;
	}
	else if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 4) == T_IR)
		ns_ld2(cur, m_map, reg, str);
	else
		temp->index_pos += ns_step_wrong_codage(m_map->map[(temp->index_pos + 1)
														% MEM_SIZE]);
	free(str);
}
