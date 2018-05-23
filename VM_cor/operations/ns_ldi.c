/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:35:15 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/23 16:35:22 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ldi_rrr(t_cursor **cur, t_map *m_map)
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
		str = find_fbytes_tind(m_map, (temp->index_pos + ((temp->registr[reg.r1] + temp->registr[reg.r2]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 5;
	free(str);
}

void	ldi_rdr(t_cursor **cur, t_map *m_map)
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
		str = find_fbytes_tind(m_map, (temp->index_pos + ((reg.dir + temp->registr[reg.r1]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 6;
	free(str);
}

void	ldi_irr(t_cursor **cur, t_map *m_map)
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
		str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
		reg.index = unsigned_char_to_int(str);
		str = find_fbytes_tind(m_map, (temp->index_pos + ((reg.index + temp->registr[reg.r2]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 6;
	free(str);
}

void	ldi_idr(t_cursor **cur, t_map *m_map)
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
		str = find_fbytes_tind(m_map, (temp->index_pos + reg.index % IDX_MOD));
		reg.index = unsigned_char_to_int(str);
		str = find_fbytes_tind(m_map, (temp->index_pos + ((reg.index + reg.dir2) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 6;
	free(str);
}

void	ldi_drr(t_cursor **cur, t_map *m_map)
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
		str = find_fbytes_tind(m_map, (temp->index_pos + ((reg.dir + temp->registr[reg.r2]) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 6;
	free(str);
}

void	ldi_ddr(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	str = NULL;
	reg.r3 = m_map->map[(temp->index_pos + 6) % MEM_SIZE];
//	ft_printf("reg = %d : ", reg.r3);
	if (ns_check_register(1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes(m_map, temp->index_pos + 2, temp->index_pos + 3);
//		ft_printf("dir = %hd : ", reg.dir);
		reg.dir2 = ns_two_bytes(m_map, temp->index_pos + 4, temp->index_pos + 5);
//		ft_printf("dir2 = %hd : ", reg.dir2);
		str = find_fbytes_tind(m_map, (temp->index_pos + ((reg.dir + reg.dir2) % IDX_MOD)));
		reg.index = unsigned_char_to_int(str);
//		ft_printf("index = %d\n", reg.index);
		temp->registr[reg.r3] = reg.index;
	}
	temp->index_pos += 7;
	free(str);
}

void	ns_ldi(t_cursor **cur, t_map *m_map)
{
	if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_RRR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = RRR\n");
		ldi_rrr(cur, m_map);
	}
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_RDR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = RDR\n");
		ldi_rdr(cur, m_map);
	}
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_DRR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = DRR\n");
		ldi_drr(cur, m_map);
	}
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_IRR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = IRR\n");
		ldi_irr(cur, m_map);
	}
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_IDR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = IDR\n");
		ldi_idr(cur, m_map);
	}
	else if (m_map->map[((*cur)->index_pos + 1) % MEM_SIZE] == T_DDR)
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = DDR\n");
		ldi_ddr(cur, m_map);
	}
	else
	{
//		if ((*cur)->index_pos == 206)
//			ft_printf("LDI = ELSE\n");
		(*cur)->index_pos += ns_step_wrong_codage(m_map->map[((*cur)->index_pos + 1) % MEM_SIZE]);
	}
}


