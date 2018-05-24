/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:26:30 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/23 14:24:24 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	lldi_rrr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	reg.r2 = m_map->map[(temp->index_pos + 3) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, reg.r2, reg.r3))
	{
		str = find_fbytes_tind(m_map, (temp->index_pos + (temp->registr[reg.r1] + temp->registr[reg.r2])));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 5;
	free(str);
}

void	lldi_rdr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	reg.r1 = m_map->map[(temp->index_pos + 2) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 3, temp->index_pos + 4);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + temp->registr[reg.r1])));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}

void	lldi_drr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	reg.r2 = m_map->map[(temp->index_pos + 4) % MEM_SIZE];
	reg.r3 = m_map->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(1, reg.r2, reg.r3))
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + temp->registr[reg.r2])));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}

void	lldi_irr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
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
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}

void	lldi_idr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
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
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 6;
	free(str);
}

void	lldi_ddr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
	if (ns_check_register(1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
		reg.dir2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
		str = find_fbytes_tind(m_map, (temp->index_pos + (reg.dir + reg.dir2)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
		temp->carry = temp->registr[reg.r3] == 0 ? 1 : 0;
	}
	temp->index_pos += 7;
	free(str);
}
void	ns_lldi(t_cursor **cur, t_map *m_map)
{
	if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_RRR) == T_RRR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = RRR\n");
		lldi_rrr(cur, m_map);
	}
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_RDR) == T_RDR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = RDR\n");
		lldi_rdr(cur, m_map);
	}
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_DRR) == T_DRR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = DRR\n");
		lldi_drr(cur, m_map);
	}
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_IRR) == T_IRR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = IRR\n");
		lldi_irr(cur, m_map);
	}
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_IDR) == T_IDR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = IDR\n");
		lldi_idr(cur, m_map);
	}
	else if ((m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] & T_DDR) == T_DDR)
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = DDR\n");
		lldi_ddr(cur, m_map);
	}
	else
	{
//		if ((*cur)->index_pos == 314)
//			ft_printf("LLDI = ELSE\n");
		(*cur)->index_pos += ns_step_wrong_codage(m_map->map[((*cur)->index_pos + 1) % MEM_SIZE]);
	}
}
