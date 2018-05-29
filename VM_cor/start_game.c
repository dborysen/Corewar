/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:58:46 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 18:12:11 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*game_start_dump(t_cursor **cursor, t_map *m_map,
							t_info *info, t_fl fl)
{
	t_cursor *temp;

	info->winner_nbr = (*cursor)->champ->id;
	info->winner_name = (*cursor)->champ->champ_name;
	while (fl.dump > 0 && info->end_game == 0)
	{
		temp = *cursor;
		ns_create_cycle(&temp, m_map);
		*cursor = ns_move_cursor(&temp, m_map, &info);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == info->die)
		{
			ns_check_lives(cursor, &info, &m_map);
			info->cycles = 0;
		}
		fl.dump--;
	}
	if (fl.dump == 0 && info->end_game == 0)
		ns_print_map(*m_map);
	if (info->end_game == 1)
		ft_printf("Player %d, (\"%s\") has won !!\n",
				info->winner_nbr, info->winner_name);
	return (*cursor);
}

t_cursor	*game_start(t_cursor **cursor, t_map *m_map, t_info *info)
{
	t_cursor *temp;

	info->winner_nbr = (*cursor)->champ->id;
	info->winner_name = (*cursor)->champ->champ_name;
	while (info->end_game == 0)
	{
		temp = *cursor;
		ns_create_cycle(&temp, m_map);
		*cursor = ns_move_cursor(&temp, m_map, &info);
		info->total_cycles++;
		info->cycles++;
		if (info->cycles == info->die)
		{
			ns_check_lives(cursor, &info, &m_map);
			info->cycles = 0;
		}
	}
	ft_printf("Player %d, (\"%s\") has won !!\n",
			info->winner_nbr, info->winner_name);
	return (*cursor);
}

t_cursor	**nc_game_start(t_cursor **cursor, t_map **m_map, t_info *info)
{
	t_cursor	*temp;
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
		ns_check_lives(cursor, &info, m_map);
		info->cycles = 0;
	}
	return (cursor);
}
