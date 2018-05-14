/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:11:53 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/11 16:20:16 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_and(t_cursor **cur, t_map *m_map)
{
	if (m_map->map[(*cur)->index_pos + 1] == T_RRR)
		ns_rrr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_RDR)
		ns_rdr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_RIR)
		ns_rir_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_DRR)
		ns_drr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_DDR)
		ns_ddr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == t_DIR)
		ns_dir_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IRR)
		ns_irr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IDR)
		ns_idr_and(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IIR)
		ns_iir_and(cur, m_map);

}

void	ns_iir_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;
	char		*str2;
	int			index2;

	temp = *cur;
	reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = char_to_int(str);
	index2 = (short)(m_map->map[temp->index_pos + 4] << 8) | (m_map->map[temp->index_pos + 5]);
	str2 = find_fbytes_tind(m_map, (temp->index_pos + index2));
	index2 = char_to_int(str2);
	reg.r3 = m_map->map[temp->index_pos + 6];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 7;
}

void	ns_idr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;
	char		*str2;
	int			index2;

	temp = *cur;
	reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = char_to_int(str);
	str2 = find_fbytes_tind(m_map, temp->index_pos + 4);
	index2 = char_to_int(str2);
	reg.r3 = m_map->map[temp->index_pos + 8];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

void	ns_irr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;

	temp = *cur;
	reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = char_to_int(str);
	reg.r2 = m_map->map[temp->index_pos + 4];
	reg.r3 = m_map->map[temp->index_pos + 5];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & reg.r2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
}

void	ns_dir_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;
	char		*str2;
	int			index2;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = char_to_int(str);
	index2 = (short)(m_map->map[temp->index_pos + 6] << 8) | (m_map->map[temp->index_pos + 7]);
	str2 = find_fbytes_tind(m_map, temp->index_pos + index2);
	index2 = char_to_int(str2);
	reg.r3 = m_map->map[temp->index_pos + 8];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

void	ns_ddr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;
	char		*str2;
	int			index2;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = char_to_int(str);
	str2 = find_fbytes_tind(m_map, temp->index_pos + 6);
	index2 = char_to_int(str2);
	reg.r3 = m_map->map[temp->index_pos + 10];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 11;
}

void	ns_drr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = char_to_int(str);
	reg.r2 = m_map->map[temp->index_pos + 6];
	reg.r3 = m_map->map[temp->index_pos + 7];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.index & reg.r2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 8;
}

void	ns_rir_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	reg.index = (short)(m_map->map[temp->index_pos + 2] << 8) | (m_map->map[temp->index_pos + 3]);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = (short)char_to_int(str);
	reg.r3 = m_map->map[temp->index_pos + 5];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.r1 & reg.index;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
}

void	ns_rdr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	str = find_fbytes_tind(m_map, temp->index_pos + 3);
	reg.index = char_to_int(str);
	reg.r3 = m_map->map[temp->index_pos + 7];
	temp->registr[reg.r3] = reg.r1 & reg.index;
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 8;
}

void	ns_rrr_and(t_cursor **cur, t_map *m_map)
{
	t_cursor *temp;
	unsigned char r1;
	unsigned char r2;
	unsigned char r3;

	temp = *cur;
	if (m_map->map[temp->index_pos + 1] == T_RRR)
	{
		r1 = m_map->map[temp->index_pos + 2];
		r2 = m_map->map[temp->index_pos + 3];
		r3 = m_map->map[temp->index_pos + 4];
		if (ns_check_register(r1, r2, r3))
		{
			temp->registr[r3] = r1 & r2;
			temp->index_pos += 5;
			if (temp->registr[r3] == 0)
				temp->carry = 1;
			else
				temp->carry = 0;
		}
		else
			temp->index_pos += 5;
	}
}
