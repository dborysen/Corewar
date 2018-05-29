/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:20:36 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/29 17:12:04 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		del_champ(t_champion **champ)
{
	t_champion *del;

	while (*champ)
	{
		del = *champ;
		*champ = (*champ)->next;
		free(del->exec_code);
		free(del);
	}
	free(*champ);
}

void		del_cursor(t_cursor **cur)
{
	t_cursor *del;

	while (*cur)
	{
		del = *cur;
		*cur = (*cur)->next;
		free(del);
	}
	free(*cur);
}

void		ns_delete_struct(t_champion *champ, t_cursor *cursor)
{
	del_champ(&champ);
	del_cursor(&cursor);
}

t_cursor	*ns_start(t_fl flags, t_cursor *cursor, t_info info, t_map map)
{
	info.count_cursor = ns_count_cursor(cursor);
	if (flags.d && !flags.v)
		cursor = game_start_dump(&cursor, &map, &info, flags);
	else if (flags.v)
		ns_ncurses(&map, &info, &cursor);
	else
		cursor = game_start(&cursor, &map, &info);
	return (cursor);
}

int			main(int ac, char **av)
{
	t_fl		flags;
	t_map		map;
	t_champion	*champ;
	t_cursor	*cursor;
	t_info		info;

	if (ac < 2)
		usage();
	ns_zero_flags(&flags);
	champ = ns_zero_champ();
	cursor = ns_zero_cursor();
	ns_zero_info(&info);
	ns_check_flags(ac, av, &flags, &champ);
	ns_create_map(&map, flags);
	ns_position_start(&champ);
	ns_fill_map(champ, &map);
	ns_create_cursor(&cursor, champ);
	if (!flags.v)
		ns_dump_flag(champ);
	ns_reverse_cursor(&cursor);
	ns_reverse_champ(&champ);
	info.champion = champ;
	cursor = ns_start(flags, cursor, info, map);
	ns_delete_struct(champ, cursor);
	system("leaks a.out");
	return (0);
}
