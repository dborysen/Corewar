/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:30:21 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/25 17:19:08 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_create_map(t_map *memory_map)
{
	int i;
	int j;

	i = 0;
	if (!(memory_map->map = (unsigned char **)malloc(sizeof(char *) * 64)))
		return ;
	while (i < 64)
	{
		if (!(memory_map->map[i] = (unsigned char *)malloc(sizeof(char) * 64 + 1)))
			return;
		j = 0;
		while (j < 64)
		{
			memory_map->map[i][j] = 0;
			j++;
		}
		memory_map->map[i][j] = '\0';
		i++;
	}
}

void	ns_ch_map(t_champion *champ, t_map **map)
{
	int		i;
	int 	j;
	int 	ind;
	t_map	*memory_map;

	i = champ->position_to_start;
	ind = 0;
	memory_map = *map;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if (ind < champ->prog_size)
				memory_map->map[i][j] = champ->exec_code[ind++];
			j++;
		}
		i++;
	}
}

void	ns_fill_map(t_champion *champ, t_map *map)
{
	while (champ->next)
	{
		ns_ch_map(champ, &map);
		champ = champ->next;
	}
}

void	ns_print_map(t_map memory_map)
{
	int i;
	int j;
	int hex;

	i = 0;
	j = 0;
	hex = 0;
	while (i < 64)
	{
		j = 0;
		hex == 0 ? ft_printf("0x%#.4x :", hex) : ft_printf("%#.4x :", hex);
		while (j < 64)
		{
			ft_printf(" %02x", memory_map.map[i][j]);
			j++;
		}
		ft_printf("\n");
		hex += 64;
		i++;
	}
}
