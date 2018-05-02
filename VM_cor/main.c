/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:20:36 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/26 15:37:34 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		usage()
{
	ft_printf("Usage: ./corewar [-d N -s N -v N | "
			" -n ] [-a] <champion1.cor> <...>");
}

void		ns_save_flags(char **av, t_fl *flags, int *i)
{
	if(ft_strcmp(av[*i], "-d") == 0)
	{
		flags->d_is = 1;
		*i += 1;
		if (!ft_isdigit(av[*i][0]))
			ns_error("not a digit after flag");
		flags->d_num = (unsigned int)ft_atoi(av[*i]);
	}
	else if(ft_strcmp(av[*i], "-v") == 0)
	{
		flags->v_is = 1;
		*i += 1;
		flags->v_num = (unsigned int)ft_atoi(av[*i]);
	}
	else if(ft_strcmp(av[*i], "-s") == 0)
	{
		flags->s_is = 1;
		*i += 1;
		flags->s_num = (unsigned int)ft_atoi(av[*i]);
	}
	else if(ft_strcmp(av[*i], "-a") == 0)
		flags->a_is = 1;
	else if(ft_strcmp(av[*i], "-n") == 0)
		flags->n_is = 1;
}


t_champion	*ns_check_champions(char *av, t_champion **champ)
{
	static int id = 1;
	t_champion *temp;

	temp = *champ;
	if(ft_strstr(av , ".cor"))
	{
		temp->id = id;
		id++;
		temp = ns_read_champion(av, &temp);
	}
	else
		ns_error("wrong champion name");
	if (temp->id > MAX_PLAYERS)
		ns_error("to much champions");
	return (temp);
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
			temp = ns_check_champions(av[i], &temp);
		i++;
	}
	if ((*champ)->id == 0)
		ns_error("wrong number champions");
	if(!flags->a_is && !flags->d_is && !flags->n_is)
		ns_error("wrong num of flags");
	temp->next = NULL;
}

int			main(int ac, char **av)
{
	t_fl		flags;
	t_map		map;
	t_champion	*champ;

	champ = (t_champion *)malloc(sizeof(t_champion));
	if (ac < 2)
		usage();
	ns_zero_flags(&flags);
	ns_zero_champ(&champ);
	ns_check_flags(ac, av, &flags, &champ);
	ns_create_map(&map);
	ns_dump_flag(champ, map);
	ns_position_start(&champ);
	ns_fill_map(champ, &map);
	ns_print_map(map);

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
//	ft_printf("%d %d %d\n", flags.d_is, flags.s_is, flags.v_is);

	return (0);
}
