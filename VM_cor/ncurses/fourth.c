/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:55:29 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/25 13:10:40 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	nc_print_borderf(t_vizor *viz)
{
	int y;

	y = 0;
	while (y < viz->width)
	{

		mvwprintw(viz->ful, 1, y, "a");
		y++;
	}
}