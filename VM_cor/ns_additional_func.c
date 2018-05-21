/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:49:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/18 18:26:07 by myprosku         ###   ########.fr       */
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

char	*int_to_char2(int nbr)
{
	char *str;

	str = (char *)malloc(sizeof(char) + 5);
	str[0] = (char)(nbr >> 24);
	ft_printf("0 = %02x\n", str[0]);

	str[1] = ((char)(nbr >> 16)) - (((char)(nbr >> 24)) << 8);
	ft_printf("0 = %02x\n", str[1]);

	str[2] = ((char)(nbr >> 8)) - (((char)(nbr >> 16)) << 8);
	ft_printf("0 = %02x\n", str[2]);

	str[3] = (char)nbr;
	ft_printf("0 = %02x\n", str[3]);

	str[4] = '\0';
	return (str);
}

char	*int_to_charpr(int nbr)
{
	char *str;

	ft_printf("D = %d\n", nbr);
	str = (char *)malloc(sizeof(char) + 5);
	str[0] = (char)(nbr >> 24);
	ft_printf("0 = %02x\n", str[0]);
	ft_printf("0nb = %d\n", str[0]);

	str[1] = (char)(nbr >> 16);
	ft_printf("1 = %02x\n", str[1]);

	str[2] = (char)(nbr >> 8);
	ft_printf("2 = %02x\n", str[2]);

	str[3] = (char)nbr;
	ft_printf("3 = %02x\n", str[3]);

	str[4] = '\0';
	return (str);
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

int		char_to_int(char *str)
{
	int num;

	num = str[0] << 24;
	num += str[1] << 16;
	num += str[2] << 8;
	num += str[3];
	return (num);
}

unsigned char	*find_fbytes_tindpr(t_map *map, unsigned int index)
{
	unsigned  char	*str;
	int				i;
	int				pos;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) + 5);
	index = index % MEM_SIZE;
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

unsigned char	*find_fbytes_tind(t_map *map, int index)
{
	unsigned  char	*str;
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
