/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:12:12 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:37:43 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_xor(t_cursor **cur, t_map *m_map)
{
	if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_RRR)
		ns_rrr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_RDR)
		ns_rdr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_RIR)
		ns_rir_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_DRR)
		ns_drr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_DDR)
		ns_ddr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == X_DIR)
		ns_dir_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_IRR)
		ns_irr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_IDR)
		ns_idr_xor(cur, m_map);
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] >> 2) == T_IIR)
		ns_iir_xor(cur, m_map);
	else
		(*cur)->index_pos += ns_step_wrong_codage(
				m_map->map[((*cur)->index_pos + 1) % MEM_SIZE]);
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
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
	reg.index = unsigned_char_to_int(str);
	index2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
	str2 = find_fbytes_tind(m_map, (temp->index_pos + index2 % IDX_MOD));
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 7;
	free(str);
	free(str2);
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
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
	reg.index = unsigned_char_to_int(str);
	str2 = find_fbytes_tind(m_map, temp->index_pos + 4);
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 8) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 9;
	free(str);
	free(str2);
}

void	ns_irr_xor(t_cursor **cur, t_map *m_map)
{
	t_cursor		*temp;
	t_reg			reg;
	unsigned char	*str;

	temp = *cur;
	reg.index = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
	str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
	reg.index = unsigned_char_to_int(str);
	reg.r2 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ temp->registr[reg.r2];
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
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
	str2 = find_fbytes_tind(m_map, temp->index_pos + index2 % IDX_MOD);
	index2 = unsigned_char_to_int(str2);
	reg.r3 = m_map->map[(temp->index_pos + 8) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		temp->registr[reg.r3] = reg.index ^ index2;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 9;
	free(str);
	free(str2);
}
