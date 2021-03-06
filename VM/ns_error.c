/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:33:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/30 13:07:14 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_error(char *err_message)
{
	ft_printf("\n\e[1;31mError:\e[0m \e[1;37m%s.\e[0m\n\n", err_message);
	exit(0);
}

void	usage(void)
{
	ft_printf("Usage: ./corewar [-dump N | "
					" -n N] [-v] <champion1.cor> <...>");
}

int		ns_check_register(int r1, int r2, int r3)
{
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (0);
	if (r1 <= 0 || r2 <= 0 || r3 <= 0)
		return (0);
	return (1);
}

int		ns_check_id(t_champion *champ)
{
	while (champ->next)
	{
		if (champ->id == champ->next->id)
			return (0);
		champ = champ->next;
	}
	return (1);
}
