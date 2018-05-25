/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:46:57 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/25 14:47:18 by myprosku         ###   ########.fr       */
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
		if ((*map)->color[cur->before_pos % MEM_SIZE] >= 6 && (*map)->color[cur->before_pos % MEM_SIZE] <= 9)
			(*map)->color[cur->before_pos % MEM_SIZE] = cur->color - 5;
		else if ((*map)->color[cur->before_pos % MEM_SIZE] == 10)
			(*map)->color[cur->before_pos % MEM_SIZE] = 5;
		cur = cur->next;
	}
}
