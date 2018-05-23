/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:46:57 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/23 17:46:36 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	nc_print_all(t_map map, t_vizor *viz, t_info *info)
{
	nc_print_map(map, *viz, viz->map);
	nc_right_print(viz, info);
	wrefresh(viz->map);
	wrefresh(viz->stat);
}

void	nc_winner(t_vizor *viz, t_info *info)
{
	mvwprintw((viz)->stat, 30, 3, "WINNER IS: ");
	wattron(viz->stat, COLOR_PAIR(info->winner_col));
	mvwprintw((viz)->stat, 30, 3 + 11, "%s", info->winner_name);
	wattron(viz->stat, COLOR_PAIR(5));
	mvwprintw((viz)->stat, 36, 3, "PRESS ESC TO EXIT! F*CK YOU");
	wrefresh(viz->stat);
}

void	nc_qwer(int key, t_info *info, t_vizor *viz)
{
	if (key == 'q' && info->cycles_limit > 10)
		info->cycles_limit -= 10;
	else if (key == 'w' && info->cycles_limit > 1)
		info->cycles_limit--;
	else if (key == 'e' && info->cycles_limit < 1000)
		info->cycles_limit++;
	else if (key == 'r' && info->cycles_limit < 989)
		info->cycles_limit += 10;
	nc_right_print(viz, info);
	wrefresh(viz->stat);
}

void		clear_map(t_cursor *cur, t_map **map)
{
	while (cur)
	{
		if ((*map)->color[cur->before_pos] >= 6 && (*map)->color[cur->before_pos] <= 9)
			(*map)->color[cur->before_pos] = cur->color - 5;
		else if ((*map)->color[cur->before_pos] == 10)
			(*map)->color[cur->before_pos] = 5;
		cur = cur->next;
	}
}

t_cursor	**nc_game_start(t_cursor **cursor, t_map **m_map, t_info *info, t_fl fl)
{
	t_cursor *temp;
	t_map		*map_t;

	map_t = *m_map;
	temp = *cursor;
	clear_map(temp, m_map);
	info->winner_name = (*cursor)->champ->champ_name;
	info->winner_nbr = (*cursor)->champ->id;
	info->winner_col = (*cursor)->champ->color;
	ns_create_cycle(&temp, map_t);
	*cursor = ns_move_cursor(&temp, map_t, &info);
	info->total_cycles++;
	info->cycles++;
	if (info->cycles == info->die)
	{
		ns_check_lives(cursor, &info);
		info->cycles = 0;
	}
	return cursor;
}
