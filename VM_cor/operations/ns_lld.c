/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:13:52 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 16:23:59 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

unsigned char	*find_twobytes(t_map *map, int index)
{
	unsigned char	*str;
	int				i;
	int				pos;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) + 3);
	index = index < 0 ? index + MEM_SIZE : index % MEM_SIZE;
	while (i < 2)
	{
		pos = index + i;
		pos = pos < 0 ? pos + MEM_SIZE : pos % MEM_SIZE;
		str[i] = map->map[pos];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void			ns_ll(t_cursor **cur, t_map *map, t_reg reg, unsigned char *str)
{
	t_cursor *temp;

	temp = *cur;
	reg.r1 = map->map[(temp->index_pos + 4) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, 1))
	{
		reg.index = ns_two_bytes(map, temp->index_pos + 2,
								temp->index_pos + 3);
		str = find_twobytes(map, temp->index_pos + reg.index);
		reg.index = unsigned_char_to_int(str);
		temp->registr[reg.r1] = reg.index;
		temp->carry = temp->registr[reg.r1] == 0 ? 1 : 0;
	}
	temp->index_pos += 5;
	free(str);
}

void			ns_lld(t_cursor **cur, t_map *m_map)
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
		ns_ll(cur, m_map, reg, str);
	else
		temp->index_pos += ns_step_wrong_codage(m_map->map[(temp->index_pos + 1)
														% MEM_SIZE]);
	free(str);
}
