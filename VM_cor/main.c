/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:20:36 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/07 17:12:59 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		usage()
{
	ft_printf("Usage: ./corewar [-dump N | "
			" -n N] [-v] <champion1.cor> <...>");
}

void		ns_save_flags(char **av, t_fl *flags, int *i)
{
	static int j = 0;

	if(ft_strcmp(av[*i], "-dump") == 0)
	{
		*i += 1;
		if (!ft_isdigit(av[*i][0]))
			ns_error("not a digit after flag");
		flags->dump = ft_atoi(av[*i]);
	}
	else if(ft_strcmp(av[*i], "-n") == 0)
	{
		*i += 1;
		if (!ft_isdigit(av[*i][0]))
			ns_error("not a digit after flag");
		flags->n = ft_atoi(av[*i]);
	}
}

t_champion	*ns_check_champions(char *av, t_champion **champ, t_fl *fl)
{
	static int id = 1;
	t_champion *temp;

	temp = *champ;
	if(ft_strstr(av , ".cor"))
	{
		if (fl->n)
		{
			temp->id = fl->n;
			fl->n = 0;
		}
		else
		{
			temp->id = id;
			id++;
		}
		temp = ns_read_champion(av, &temp);
	}
	else
		ns_error("wrong champion name");
	if (id - 1 > MAX_PLAYERS)
		ns_error("to much champions");
	return (temp);
}

int			ns_check_id(t_champion *champ)
{
	while (champ->next)
	{
		if (champ->id == champ->next->id)
			return (0);
		champ = champ->next;
	}
	return (1);
}

void		ns_check_flags(int ac, char **av, t_fl *flags, t_champion **champ)
{
	int i;

	i = 1;
	t_champion *temp = *champ;
	while (i < ac)
	{
		if (av[i][0] == '-')
			ns_save_flags(av, flags, &i);
		else
			temp = ns_check_champions(av[i], &temp, flags);
		i++;
	}
	if ((*champ)->id == 0 || !ns_check_id(*champ))
		ns_error("wrong number champions");
//	if(!flags->dump && !flags->n && !flags->v)
//		ns_error("wrong num of flags");
	temp->next = NULL;
}

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
	ns_dump_flag(champ, map);
	ns_position_start(&champ);
	ns_fill_map(champ, &map);
	ns_create_cursor(&cursor, champ);
	ns_game_start(&cursor, &map, &info);
	ns_print_map(map);
	while (cursor->next)
	{
		ft_printf("start_pos = %d\n", cursor->index_pos);
		cursor = cursor->next;
	}
//	char *s = ft_itoa_base(84, 2, 1);
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
