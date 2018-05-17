/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:12:12 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/15 18:27:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** be careful with T_IND(mb mistake)
*/

#include "../corewar.h"

void	ns_xor(t_cursor **cur, t_map *m_map)
{
	if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_RRR)
		ns_rrr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_RDR)
		ns_rdr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_RIR)
		ns_rir_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_DRR)
		ns_drr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_DDR)
		ns_ddr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == t_DIR)
		ns_dir_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_IRR)
		ns_irr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_IDR)
		ns_idr_xor(cur, m_map);
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_IIR)
		ns_iir_xor(cur, m_map);
	else
	(*cur)->index_pos += ns_step_wrong_codage(m_map->map[((*cur)->index_pos + 1) % MEM_SIZE]);
}

void	ns_iir_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;
	unsigned char	*str2;
	int				index2;

	temp = *cur;
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = unsigned_char_to_int(str);
	index2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
	str2 = find_fbytes_tind(m_map, (temp->index_pos + index2));
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 7;
}

void	ns_idr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;
	unsigned char	*str2;
	int				index2;

	temp = *cur;
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = unsigned_char_to_int(str);
	str2 = find_fbytes_tind(m_map, temp->index_pos + 4);
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 8) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

void	ns_irr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_reg		reg;
	unsigned char		*str;

	temp = *cur;
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = unsigned_char_to_int(str);
	reg.r2 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ temp->registr[reg.r2];
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
}

void	ns_dir_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;
	unsigned char	*str2;
	int				index2;

	temp = *cur;
	str = find_fbytes_tind(m_map, temp->index_pos + 2);
	reg.index = unsigned_char_to_int(str);
	index2 = ns_two_bytes(m_map, temp->index_pos + 6, temp->index_pos + 7);
	str2 = find_fbytes_tind(m_map, temp->index_pos + index2);
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 8) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 9;
}

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
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 11;
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
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 8;
}

void	ns_rir_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	reg.r1 = m_map->map[temp->index_pos + 2];
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index));
	reg.index = unsigned_char_to_int(str);
	reg.r3 = m_map->map[temp->index_pos + 5];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		temp->registr[reg.r3] = temp->registr[reg.r1] ^ reg.index;
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 6;
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
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
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
		if (temp->registr[reg.r3] == 0)
			temp->carry = 1;
		else
			temp->carry = 0;
	}
	temp->index_pos += 5;
}
