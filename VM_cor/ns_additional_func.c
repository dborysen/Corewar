/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:49:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/25 15:34:05 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int		unsigned_char_to_int(unsigned char *str)
{
	int nbr;

	nbr = str[0] << 24;
	nbr += str[1] << 16;
	nbr += str[2] << 8;
	nbr += str[3];
	return (nbr);
}

void	ns_position_start(t_champion **champ)
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
		temp->position_to_start += 64 / len + before_pos;
		before_pos = temp->position_to_start;
		temp = temp->next;
	}
}
