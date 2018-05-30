/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:49:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 17:18:42 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				unsigned_char_to_int(unsigned char *str)
{
	int num;

	num = str[0] << 24;
	num += str[1] << 16;
	num += str[2] << 8;
	num += str[3];
	return (num);
}

unsigned char	*int_to_char(int nbr)
{
	unsigned char *str;

	str = (unsigned char *)malloc(sizeof(unsigned char) + 5);
	str[0] = (unsigned char)(nbr >> 24);
	str[1] = (unsigned char)(nbr >> 16);
	str[2] = (unsigned char)(nbr >> 8);
	str[3] = (unsigned char)nbr;
	str[4] = '\0';
	return (str);
}

short			ns_two_bytes(t_map *map, int pos1, int pos2)
{
	pos1 = pos1 < 0 ? pos1 + MEM_SIZE : pos1 % MEM_SIZE;
	pos2 = pos2 < 0 ? pos2 + MEM_SIZE : pos2 % MEM_SIZE;
	return ((map->map[pos1] << 8) | (map->map[pos2]));
}

unsigned char	*find_fbytes_tind(t_map *map, int index)
{
	unsigned char	*str;
	int				i;
	int				pos;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) + 5);
	index = index < 0 ? index + MEM_SIZE : index % MEM_SIZE;
	while (index < 0)
		index += MEM_SIZE;
	while (i < 4)
	{
		pos = index + i;
		pos = pos < 0 ? pos + MEM_SIZE : pos % MEM_SIZE;
		str[i] = map->map[pos];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void			ns_position_start(t_champion **champ)
{
	int			len;
	int			before_pos;
	t_champion	*temp;

	temp = *champ;
	len = 0;
	before_pos = 0;
	while (temp->next)
	{
		len++;
		temp = temp->next;
	}
	temp = *champ;
	temp = temp->next;
	while (temp->next)
	{
		temp->position_to_start += MEM_SIZE / len + before_pos;
		before_pos = temp->position_to_start;
		temp = temp->next;
	}
}
