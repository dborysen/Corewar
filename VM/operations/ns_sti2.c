/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_sti2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:30:37 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 15:45:32 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_on_map_rid(t_map **map, t_cursor *temp, t_reg reg)
{
	unsigned char	*str;
	unsigned char	*move_bytes;

	reg.index = ns_two_bytes((*map), temp->index_pos + 3, temp->index_pos + 4);
	move_bytes = find_fbytes_tind(*map,
								(temp->index_pos + (reg.index % IDX_MOD)));
	reg.index = unsigned_char_to_int(move_bytes);
	reg.dir2 = ns_two_bytes((*map), temp->index_pos + 5, temp->index_pos + 6);
	str = int_to_char(temp->registr[reg.r1]);
	reg.index = temp->index_pos + ((reg.index + reg.dir2) % IDX_MOD);
	reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
	ns_on_map(map, reg, str, temp);
	free(str);
	free(move_bytes);
}

void	set_on_map_rir(t_map **map, t_cursor *temp, t_reg reg)
{
	unsigned char	*str;
	unsigned char	*move_bytes;

	reg.r3 = (*map)->map[temp->index_pos + 5];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		reg.index = ns_two_bytes((*map), temp->index_pos + 3,
								temp->index_pos + 4);
		move_bytes = find_fbytes_tind(*map, (temp->index_pos +
											(reg.index % IDX_MOD)));
		reg.index = unsigned_char_to_int(move_bytes);
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = temp->index_pos + ((reg.index + temp->registr[reg.r3])
									% IDX_MOD);
		reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
		ns_on_map(map, reg, str, temp);
		free(str);
		free(move_bytes);
	}
}

void	set_on_map_rdr(t_map **map, t_cursor *temp, t_reg reg)
{
	unsigned char *str;

	reg.r3 = (*map)->map[(temp->index_pos + 5) % MEM_SIZE];
	if (ns_check_register(reg.r1, 1, reg.r3))
	{
		reg.dir = ns_two_bytes((*map), temp->index_pos + 3,
							temp->index_pos + 4);
		str = int_to_char(temp->registr[reg.r1]);
		reg.index = temp->index_pos +
					((reg.dir + temp->registr[reg.r3]) % IDX_MOD);
		reg.index = reg.index < 0 ? reg.index + MEM_SIZE : reg.index % MEM_SIZE;
		ns_on_map(map, reg, str, temp);
		free(str);
	}
}
