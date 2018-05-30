/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:57:54 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 18:12:44 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ns_reverse_cursor(t_cursor **cursor)
{
	t_cursor *prev;
	t_cursor *current;
	t_cursor *next;

	prev = NULL;
	current = *cursor;
	while (current->next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	free(current);
	*cursor = prev;
}

int			check_id_player(int id, t_info *info)
{
	t_champion *temp;

	temp = info->champion;
	while (temp->next)
	{
		if (id == temp->id)
			return (1);
		temp = temp->next;
	}
	return (0);
}

char		*find_name_id(int id, t_info *info)
{
	t_champion *temp;

	temp = info->champion;
	while (temp->next)
	{
		if (id == temp->id)
			return (temp->champ_name);
		temp = temp->next;
	}
	return (NULL);
}
