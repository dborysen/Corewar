/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_save_fch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:57:53 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/11 15:58:37 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ns_save_flags(char **av, t_fl *flags, int *i)
{
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

t_champion	*ns_save_champs(t_champion **champ, unsigned char *file_info, int fd)
{
	t_champion *temp;

	temp = *champ;
	ns_save_magic(&temp, file_info);
	ns_save_program_name(&temp, file_info);
	ns_save_program_size(&temp, file_info);
	ns_save_comment(&temp, file_info);
	ns_save_execute_code(&temp, file_info, fd);
	temp->next = (t_champion *)malloc(sizeof(t_champion));
	temp = temp->next;
	return (temp);
}

t_champion	*ns_read_champion(char *av, t_champion **champ)
{
	int 			fd;
	off_t 			size_file;
	unsigned char	*file_info;
	t_champion		*temp;

	temp = *champ;
	if ((fd = open(av, O_RDONLY)) == -1)
		ns_error("wrong file name");
	size_file = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	file_info = (unsigned char *)ft_strnew((size_t)size_file);
	read(fd, file_info, (size_t)size_file);
	temp->file_size = (size_t)size_file;
	if (temp->file_size > sizeof(header_t) + CHAMP_MAX_SIZE)
		ns_error("large file");
	return (ns_save_champs(&temp, file_info, fd));
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