/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:24:34 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/25 15:47:41 by ssavchen         ###   ########.fr       */
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

void	nc_next_step(t_vizor *viz, t_info *info, t_map *map, t_cursor **cursor)
{
	int		key;

	while (info->end_game == 0)
	{
		if ((viz)->pause == 1)
			(viz)->pause = 0;
		timeout(1);
		usleep((useconds_t)(350000 / info->cycles_limit));
		key = getch();
		if (key == 27)
			nc_offline(viz);
		else if (key == ' ')
			nc_wait(viz, info, map, cursor);
		else if (key == 'q' || key == 'w' || key == 'e' || key == 'r')
			nc_qwer(key, info, viz);
		cursor = nc_game_start(cursor, &map, info);
		nc_print_all(*map, viz, info);
	}
	nc_winner(viz, info);
	timeout(-1);
	if (getch() == 27)
		nc_offline(viz);
}

void	nc_wait(t_vizor *viz, t_info *info, t_map *map, t_cursor **cursor)
{
	int		key;

	if (viz->pause == 0)
	{
		viz->pause = 1;
		nc_right_print(viz, info);
		wrefresh(viz->stat);
	}
	key = getch();
	if (key == 'q' || key == 'w' || key == 'e' || key == 'r')
		nc_qwer(key, info, viz);
	else if (key == ' ')
		nc_next_step(viz, info, map, cursor);
	else if (key == 27)
		nc_offline(viz);
	if (viz->pause == 1)
		nc_wait(viz, info, map, cursor);
}

void	nc_right_print(t_vizor *viz, t_info *info)
{
	wattron(viz->stat, COLOR_PAIR(5));
	wattron(viz->stat, A_BOLD);
	if (viz->pause == 1)
		mvwprintw(viz->stat, 3, 5, "** PAUSED  **");
	else
		mvwprintw(viz->stat, 3, 5, "** RUNNING **");
	mvwprintw(viz->stat, 6, 4, "Cycle/second limit : %4d", info->cycles_limit);
	mvwprintw(viz->stat, 9, 4, "Cycle : %d", info->total_cycles);
	mvwprintw(viz->stat, 12, 4, "Processes : %d", info->count_cursor);
	mvwprintw(viz->stat, 15, 4, "CYCLE_TO_DIE : %d", info->die);
	mvwprintw(viz->stat, 18, 4, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(viz->stat, 21, 4, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(viz->stat, 24, 4, "MAX_CHECKS : %d", MAX_CHECKS);
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
