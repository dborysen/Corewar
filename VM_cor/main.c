/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:20:36 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/15 17:41:27 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int ac, char **av)
{
	t_fl		flags;
	t_map		map;
	t_champion	*champ;
	t_cursor	*cursor;
	t_info		info;

	champ = (t_champion *)malloc(sizeof(t_champion));
	cursor = (t_cursor *)malloc(sizeof(t_cursor));
	if (ac < 2)
		usage();
	ns_zero_flags(&flags);
	ns_zero_champ(&champ);
	ns_zero_cursor(&cursor);
	ns_zero_info(&info);
	ns_check_flags(ac, av, &flags, &champ);
	ns_create_map(&map);
	ns_dump_flag(champ);
	ns_position_start(&champ);
	ns_fill_map(champ, &map);
	ns_create_cursor(&cursor, champ);
	ns_reverse_cursor(&cursor);
	cursor = ns_game_start(&cursor, &map, &info, flags);
	ns_print_map(map);
	while (cursor)
	{
		ft_printf("pos = %d : ", cursor->index_pos);
		ft_printf("com = %d\n", cursor->commad);
		cursor = cursor->next;
	}
//	rev(s, (int)ft_strlen(s));
//	ft_printf("%s\n", s);
//	while (champ->next)
//	{
////		ft_printf("champ name = %s\n", champ->prog_name);
////		ft_printf("champ coment = %s\n", champ->comment);
////		ft_printf("champ realprogsize = %lld\n", champ->real_program_size);
////		ft_printf("champ progsize = %u\n", champ->prog_size);
////		ft_printf("champ magic = %u\n", champ->magic);
////		int i = 0;
////		while (champ->exec_code[i])
////		{
////			ft_printf("champ exec = %x\n", champ->exec_code[i]);
////			i++;
////		}
//		ft_printf("start pos = %d\n", champ->position_to_start);
//		ft_printf("id = %lld\n", champ->id);
//		champ = champ->next;
//	}
//	ft_printf("%d %d %d\n", flags.dump_is, flags.s_is, flags.v_is);

	return (0);
}
