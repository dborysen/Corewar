/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:49:08 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 16:51:59 by myprosku         ###   ########.fr       */
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

void	ns_check_lives(t_cursor **cur, t_info **info)
{
	int count;

	count = 0;
	while ((*cur)->next)
	{
		if ((*cur)->live_or_die)
		{
			(*cur)->live_or_die = 0;
			count++;
		}
		(*cur) = (*cur)->next;
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
