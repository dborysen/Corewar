/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:53:27 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/30 14:14:37 by ssavchen         ###   ########.fr       */
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
	mvwprintw((viz)->stat, info->zdvig, 4, "THE WINNER IS: ");
	wattron(viz->stat, COLOR_PAIR(info->winner_col));
	mvwprintw((viz)->stat, info->zdvig, 4 + 15, "%s", info->winner_name);
	wattron(viz->stat, COLOR_PAIR(5));
	mvwprintw((viz)->stat, info->zdvig + 3, 4, "PRESS ESC TO EXIT!");
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
	else if (key == 'r' && info->cycles_limit <= 990)
		info->cycles_limit += 10;
	else if (key == 'r' && info->cycles_limit >= 991
			&& info->cycles_limit <= 999)
		info->cycles_limit = 1000;
	else if (key == 'q' && info->cycles_limit > 1
			&& info->cycles_limit <= 10)
		info->cycles_limit = 1;
	nc_right_print(viz, info);
	wrefresh(viz->stat);
}

void	clear_map(t_cursor *cur, t_map **map)
{
	while (cur)
	{
		if ((*map)->color[cur->before_pos % MEM_SIZE] >= 6
			&& (*map)->color[cur->before_pos % MEM_SIZE] <= 9)
			(*map)->color[cur->before_pos % MEM_SIZE] = cur->color - 5;
		else if ((*map)->color[cur->before_pos % MEM_SIZE] == 10)
			(*map)->color[cur->before_pos % MEM_SIZE] = 5;
		cur = cur->next;
	}
}

void	nc_players_print(t_vizor *viz, t_info *info)
{
	t_champion	*tmp;

	info->zdvig = 15;
	tmp = info->champion;
	while (tmp->next)
	{
		mvwprintw(viz->stat, info->zdvig, 4, "Player - %d : ", tmp->id);
		wattron(viz->stat, COLOR_PAIR(tmp->color));
		mvwprintw(viz->stat, info->zdvig, 16 + ft_intlen(tmp->id), "\"%s\"",
				tmp->champ_name);
		info->zdvig += 3;
		tmp = tmp->next;
		wattron(viz->stat, COLOR_PAIR(5));
	}
}
