/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:30:21 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 15:11:46 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_create_map(t_map *memory_map, t_fl flags)
{
	int i;

	i = 0;
	memory_map->d = flags.d;
	memory_map->v = flags.v;
	while (i < MEM_SIZE)
	{
		memory_map->map[i] = 0;
		memory_map->color[i] = 5;
		i++;
	}
}

void	ns_ch_map(t_champion *champ, t_map **map)
{
	int				i;
	unsigned int	ind;
	t_map			*memory_map;

	ind = 0;
	memory_map = *map;
	i = champ->position_to_start;
	while (i < MEM_SIZE)
	{
		if (ind < champ->size_bytes)
		{
			memory_map->map[i] = champ->exec_code[ind++];
			if (memory_map->color[i] != champ->color + 5)
				memory_map->color[i] = champ->color;
		}
		i++;
	}
}

void	ns_fill_map(t_champion *champ, t_map *map)
{
	while (champ->next)
	{
		map->color[champ->position_to_start] = champ->color + 5;
		ns_ch_map(champ, &map);
		champ = champ->next;
	}
}

void	ns_print_map(t_map memory_map)
{
	int i;
	int hex;
	int count;

	i = 0;
	hex = 0;
	count = 0;
	while (i < MEM_SIZE)
	{
		if (count == 0)
		{
			hex == 0 ? ft_printf("0x%#.4x :", hex) : ft_printf("%#.4x :", hex);
			hex += 64;
		}
		ft_printf(" %02x", memory_map.map[i]);
		count++;
		if (count == 64)
		{
			ft_printf(" \n");
			count = 0;
		}
		i++;
	}
}
