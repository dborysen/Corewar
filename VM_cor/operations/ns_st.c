/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:38:50 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/24 16:17:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_on_map(t_map **map, t_cursor *temp, t_reg reg)
{
	int				i;
	int				pos;
	unsigned char	*str;
	t_map			*map_t;

	map_t = *map;
	i = 0;
	reg.index = ns_two_bytes(map_t, temp->index_pos + 3, temp->index_pos + 4);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = temp->index_pos + reg.index % IDX_MOD;
	reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
	while (i < 4)
	{
		pos = reg.index + i;
		pos = pos < 0 ? pos + MEM_SIZE : pos % MEM_SIZE;
		map_t->map[pos] = str[i];
		map_t->color[pos] = temp->champ->color;
		i++;
	}
}

void	ns_st(t_cursor **cur, t_map *m_map)
{
	t_reg		reg;
	t_cursor	*temp;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 4) == T_RR)
	{
		reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
		if (ns_check_register(reg.r1, reg.r2, 1))
			temp->registr[reg.r2] = temp->registr[reg.r1];
		temp->index_pos += 4;
	}
	else if ((m_map->map[(temp->index_pos + 1) % MEM_SIZE] >> 4) == T_RI)
	{
		if (ns_check_register(reg.r1, 1, 1))
			set_on_map(&m_map, temp, reg);
		temp->index_pos += 5;
	}
	else
		temp->index_pos += ns_step_wrong_codage(
				m_map->map[(temp->index_pos + 1) % MEM_SIZE]);
}
