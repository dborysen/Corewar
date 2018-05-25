/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_xor2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:16 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:03:18 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_ddr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;
	unsigned char	*str2;
	int				index2;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = unsigned_char_to_int(str);
	str2 = find_fbytes_tind(m_map, temp->index_pos + 6);
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 10) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 11;
	free(str);
	free(str2);
}

void	ns_drr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = unsigned_char_to_int(str);
	reg.r2 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 7) % MEM_SIZE];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ temp->registr[reg.r2];
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 8;
	free(str);
}

void	ns_rir_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, temp->index_pos + reg.index % IDX_MOD);
	reg.index = unsigned_char_to_int(str);
	reg.r3 = m_map->map[temp->index_pos + 5];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		temp->registr[reg.r3] = temp->registr[reg.r1] ^ reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}

void	ns_rdr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	str = find_fbytes_tind(m_map, temp->index_pos + 3);
	reg.index = unsigned_char_to_int(str);
	reg.r3 = m_map->map[(temp->index_pos + 7) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		temp->registr[reg.r3] = temp->registr[reg.r1] ^ reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 8;
}

void	ns_rrr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;

	temp = *cur;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = temp->registr[reg.r1] ^ temp->registr[reg.r2];
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 5;
}
