/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:49:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/08 18:16:45 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int				unsigned_char_to_int(unsigned char *str)
{
	int nbr;

	nbr = str[0] << 24;
	nbr += str[1] << 16;
	nbr += str[2] << 8;
	nbr += str[3];
	return (nbr);
}

//char	*int_to_char(int nbr)
//{
//	char *str;
//
//	str = (char *)malloc(sizeof(unsigned char) + 5);
//	ft_printf("nbr = %d\n", nbr);
//	str[0] = (char)nbr >> 24;
//			ft_printf("bytes = %02x\n", str[0]);
//	str[1] = ((char)nbr >> 16) - (((char)nbr >> 24) << 8);
//	ft_printf("bytes = %02x\n", str[1]);
//	str[2] = ((char)nbr >> 8) - (((char)nbr >> 16) << 8);
//	ft_printf("bytes = %02x\n", str[2]);
//	str[3] = ((char)nbr);
//	ft_printf("bytes = %02x\n", str[3]);
//	str[4] = '\0';
//	return (str);
//}

char	*int_to_char(int nbr)
{
	char *str;

	str = (char *)malloc(sizeof(char) + 5);
	str[0] = (char)nbr >> 24;
	str[1] = (char)nbr >> 16;
	str[2] = (char)nbr >> 8;
	str[3] = (char)nbr;
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

char	*find_fbytes_tind(t_map *map, int index)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) + 5);
	while (i < 4)
	{
		str[i] = map->map[index + i];
		i++;
	}
	return str;
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

void 			ns_error(char *err_message)
{
	ft_printf("Error with problem: %s.\n", err_message);
	exit(0);
}

int 			ns_check_register(unsigned char r1, unsigned char r2, unsigned char r3)
{
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (0);
	if (r1 == 0 || r2 == 0 || r3 == 0)
		return (0);
	return (1);
}


