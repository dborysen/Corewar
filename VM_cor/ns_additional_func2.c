/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:49:08 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/16 15:18:10 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 			ns_error(char *err_message)
{
	ft_printf("Error with problem: %s.\n", err_message);
	exit(0);
}

void		usage()
{
	ft_printf("Usage: ./corewar [-dump N | "
					  " -n N] [-v] <champion1.cor> <...>");
}

int 			ns_check_register(int r1, int r2, int r3)
{
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (0);
	if (r1 == 0 || r2 == 0 || r3 == 0)
		return (0);
	return (1);
}

int			ns_check_id(t_champion *champ)
{
	while (champ->next)
	{
		if (champ->id == champ->next->id)
			return (0);
		champ = champ->next;
	}
	return (1);
}

t_cursor		*get_nth(t_cursor *head, t_cursor *temp)
{
	int counter;

	counter = 0;
	while (head != temp)
	{
		head = head->next;
		counter++;
	}
	return (head);
}

void			ns_delete_nth(t_cursor **head, t_cursor *temp)
{
	t_cursor *prev;
	t_cursor *elm;

	if (head == NULL)
		return ;
	else
	{
		prev = get_nth(*head, temp);
		elm = prev->next;
		prev->next = elm->next;
		free(elm);
	}
}

void	ns_check_lives(t_cursor **cur, t_info **info)
{
	int			count;
	t_cursor	*temp;

	count = 0;
	temp = *cur;
	while (temp)
	{
		if (temp->live_or_die)
		{
			temp->live_or_die = 0;
			count++;
		}
		else
			ns_delete_nth(cur, temp);
		temp = temp->next;
	}
	if (count >= 21)
		(*info)->checks -= 1;
	if ((*info)->checks <= 0)
	{
		(*info)->die -= CYCLE_DELTA;
		(*info)->checks = MAX_CHECKS;
	}
	if (count < 21)
	{
		(*info)->die -= CYCLE_DELTA;
		(*info)->checks = MAX_CHECKS;
	}
}

short	ns_two_bytes(t_map *map, int pos1, int pos2)
{

	return ((map->map[pos1] << 8) | (map->map[pos2]));
}
