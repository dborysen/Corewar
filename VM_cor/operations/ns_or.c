/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:13:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/14 16:55:18 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** be careful with T_IND(mb mistake)
*/

#include "../corewar.h"

void	ns_or(t_cursor **cur, t_map *m_map)
{
	if (m_map->map[(*cur)->index_pos + 1] == T_RRR)
		ns_rrr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_RDR)
		ns_rdr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_RIR)
		ns_rir_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_DRR)
		ns_drr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_DDR)
		ns_ddr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == t_DIR)
		ns_dir_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IRR)
		ns_irr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IDR)
		ns_idr_or(cur, m_map);
	else if (m_map->map[(*cur)->index_pos + 1] == T_IIR)
		ns_iir_or(cur, m_map);

}

void	ns_iir_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 7;
}

void	ns_idr_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

void	ns_irr_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | reg.r2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
}

void	ns_dir_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

void	ns_ddr_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 11;
}

void	ns_drr_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.index | reg.r2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 8;
}

void	ns_rir_or(t_cursor **cur, t_map *m_map)
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
		temp->registr[reg.r3] = reg.r1 | reg.index;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
}

void	ns_rdr_or(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	char		*str;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	str = find_fbytes_tind(m_map, temp->index_pos + 3);
	reg.index = char_to_int(str);
	reg.r3 = m_map->map[temp->index_pos + 7];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.r1 | reg.index;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 8;
}

void	ns_rrr_or(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	reg.r2 = m_map->map[temp->index_pos + 3];
	reg.r3 = m_map->map[temp->index_pos + 4];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.r1 | reg.r2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 5;
}


//Узнать тип регистра

//void	ns_or(t_cursor **cur, t_map *m_map)
//{
//	t_cursor *temp;
//	unsigned char r1;
//	unsigned char r2;
//	unsigned char r3;
//
//	temp = *cur;
//	r1 = m_map->map[temp->index_pos + 2];
//	r2 = m_map->map[temp->index_pos + 3];
//	r3 = m_map->map[temp->index_pos + 4];
//	temp->registr[r3] = r1 | r2;
//	if (temp->registr[r3] == 0)
//		temp->carry = 1;
//	else
//		temp->carry = 0;
//}
