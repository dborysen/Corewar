/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:30:21 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/24 16:34:00 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_create_map(t_map *memory_map)
{
	int i;

	i = 0;
	if (!(memory_map->map = (char **)malloc(sizeof(char *) * 64)))
		return ;
	while (i < 64)
	{
		
		i++;
	}
}
