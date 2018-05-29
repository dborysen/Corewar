/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:03:59 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/29 13:55:55 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	nc_create_viz(t_vizor *viz)
{
	viz->pause = 1;
	viz->height = 70;
	viz->width = 255;
	viz->ful = newwin(viz->height, viz->width, 0, 0);
	viz->map = newwin(viz->height - 3, viz->width - 50, 2, 2);
	viz->stat = newwin(viz->height - 6, viz->width - 200, 2, 198);
	box(viz->ful, 0, 0);
	box(viz->stat, 0, 0);
}

void	nc_get_color(t_map map, int i, t_vizor viz)
{
	if (map.color[i] == 1)
		wattron(viz.map, COLOR_PAIR(1));
	else if (map.color[i] == 2)
		wattron(viz.map, COLOR_PAIR(2));
	else if (map.color[i] == 3)
		wattron(viz.map, COLOR_PAIR(3));
	else if (map.color[i] == 4)
		wattron(viz.map, COLOR_PAIR(4));
	else if (map.color[i] == 5)
		wattron(viz.map, COLOR_PAIR(5));
	else if (map.color[i] == 6)
		wattron(viz.map, COLOR_PAIR(6));
	else if (map.color[i] == 7)
		wattron(viz.map, COLOR_PAIR(7));
	else if (map.color[i] == 8)
		wattron(viz.map, COLOR_PAIR(8));
	else if (map.color[i] == 9)
		wattron(viz.map, COLOR_PAIR(9));
	else if (map.color[i] == 10)
		wattron(viz.map, COLOR_PAIR(10));
}

void	nc_print_map(t_map map, t_vizor viz, WINDOW *winmap)
{
	int		i;
	int		count;
	int		x;

	i = 0;
	x = 0;
	count = 0;
	wmove(winmap, 0, 2);
	while (i < MEM_SIZE)
	{
		nc_get_color(map, i, viz);
		wprintw(winmap, "%02x", map.map[i]);
		wattron(winmap, COLOR_PAIR(5));
		wprintw(winmap, " ");
		count++;
		if (count == 64)
		{
			count = 0;
			x++;
			wmove(winmap, x, 2);
		}
		i++;
	}
}

void	nc_set_color(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_WHITE, COLOR_WHITE);
	init_pair(11, COLOR_RED, COLOR_BLACK);
}

void	ns_ncurses(t_map *map, t_info *info, t_cursor **cursor)
{
	t_vizor		viz;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	nc_set_color();
	nc_check_window();
	nc_create_viz(&viz);
	nc_print_map(*map, viz, viz.map);
	nc_right_print(&viz, info);
	refresh();
	wrefresh(viz.ful);
	wrefresh(viz.map);
	wrefresh(viz.stat);
	nc_wait(&viz, info, map, cursor);
}
