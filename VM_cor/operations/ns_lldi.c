/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:26:30 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/17 17:58:19 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ns_lldi4(t_cursor **cur, t_map *m_map, t_reg reg, unsigned char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_DDR)
	{
		reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
		if (ns_check_register(1, 1, reg.r3))
		{
			reg.dir = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
			reg.dir2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + reg.dir2)));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 7;
	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_IDR)
	{
		reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
		if (ns_check_register(1, 1, reg.r3))
		{
			reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
			reg.dir2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index % IDX_MOD)));
			reg.index = unsigned_char_to_int(str);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index + reg.dir2)));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 6;
	}
	else
		temp->index_pos += ns_step_wrong_codage(m_map->map[(temp->index_pos + 1) % MEM_SIZE]);
	return (reg.r3);
}

int		ns_lldi3(t_cursor **cur, t_map *m_map, t_reg reg, unsigned char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_IRR)
	{
		reg.r2 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
		reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
		if (ns_check_register(1, reg.r2, reg.r3))
		{
			reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index % IDX_MOD)));
			reg.index = unsigned_char_to_int(str);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.index + temp->registr[reg.r2])));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 6;
	}
	else
		reg.r3 = (ns_lldi4(cur, m_map, reg, str));
	return (reg.r3);
}

int		ns_lldi2(t_cursor **cur, t_map *m_map, t_reg reg, unsigned char *str)
{
	t_cursor 	*temp;

	temp = *cur;
	if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_DRR)
	{
		reg.r2 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
		reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
		if (ns_check_register(1, reg.r2, reg.r3))
		{
			reg.dir = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + temp->registr[reg.r2])));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 6;
	}
	else if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RDR)
	{
		reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
		reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
		if (ns_check_register(1, 1, reg.r3))
		{
			reg.dir = ns_two_bytes(m_map, temp->index_pos + 3, temp->index_pos + 4);
			str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + temp->registr[reg.r1])));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 6;
	}
	else
		reg.r3 = ns_lldi3(cur, m_map, reg, str);
	return (reg.r3);
}

void	ns_lldi(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	ns_zero_reg(&reg);
	if (m_map->map[(temp->index_pos + 1) % MEM_SIZE] == T_RRR)
	{
		reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
		reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
		reg.r3 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
		if (ns_check_register(reg.r1, reg.r2, reg.r3))
		{
			str = find_fbytes_tind(m_map, (temp->index_pos + (temp->registr[reg.r1] + temp->registr[reg.r2])));
			reg.index = unsigned_char_to_int(str);
			temp->registr[reg.r3] = reg.index;
		}
		temp->index_pos += 5;
	}
	else
		reg.r3 = ns_lldi2(cur, m_map, reg, str);
	if (ns_check_register(1, 1, reg.r3) && temp->registr[reg.r3] == 0)
		temp->carry = 1;
	else
		temp->carry = 0;
}
