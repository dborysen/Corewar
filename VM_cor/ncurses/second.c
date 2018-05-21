/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:24:34 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/21 12:33:25 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	nc_offline(t_vizor *viz)
{
	delwin(viz->stat);
	delwin(viz->map);
	delwin(viz->ful);
	endwin();
	exit(0);
}

void	nc_wait(t_vizor *viz, t_info *info)
{
	int		key;

	if (viz->state == 1)
	{
		nc_right_print(viz, info);
		viz->state = 0;
		wrefresh(viz->stat);
	}
	key = getch();
	if (key == 'q' && viz->limit > 10)
		viz->limit -= 10;
	else if (key == 'w' && viz->limit > 1)
		viz->limit--;
	else if (key == 'e' && viz->limit < 1000)
		viz->limit++;
	else if (key == 'r' && viz->limit < 989)
		viz->limit += 10;
	else if (key == 27)
		nc_offline(viz);
	nc_right_print(viz, info);
	wrefresh(viz->stat);
	nc_wait(viz, info);
}

void	nc_right_print(t_vizor *viz, t_info *info)
{
	mvwprintw(viz->stat, 3, 3, "Cycle/second limit : %4d", viz->limit);
	mvwprintw(viz->stat, 6, 3, "Cycle : %d", info->total_cycles);
	mvwprintw(viz->stat, 9, 3, "Processes : %d", viz->proc);
	mvwprintw(viz->stat, 12, 3, "CYCLE_TO_DIE : %d", info->die);
	mvwprintw(viz->stat, 15, 3, "CYCLE_DELTA : %d", info->checks);
	mvwprintw(viz->stat, 18, 3, "NBR_LIVE : %d", viz->proc);
	mvwprintw(viz->stat, 21, 3, "MAX_CHECKS : %d", info->checks);
}

void	nc_check_window(void)
{
	if (COLS < 260 || LINES < 74)
	{
		ft_printf("YO YO YO YO\n Take relax!\n");
		ft_printf("Make window bigger!\n");
		endwin();
		exit(0);
	}
}