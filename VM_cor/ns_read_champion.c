/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_read_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:23:34 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/25 17:20:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	ns_save_program_size(t_champion **champ, unsigned char *content_file)
{
	unsigned char	str[4];
	int				i;
	t_champion		*temp;

	temp = *champ;
	i = 0;
	while (i < 4)
	{
		str[i] = content_file[PROG_NAME_LENGTH + 8 + i];
		i++;
	}
	str[i] = '\0';
	temp->prog_size = (unsigned int)unsigned_char_to_int(str);
}

void	ns_save_magic(t_champion **champ, unsigned char *content_file)
{
	unsigned char	magic[4];
	int				i;
	t_champion		*temp;

	temp = *champ;
	i = 0;
	while (i < 4)
	{
		magic[i] = content_file[i];
		i++;
	}
	magic[i] = '\0';
	temp->magic = (unsigned int)unsigned_char_to_int(magic);
}

void	ns_save_comment(t_champion **champ, unsigned char *content_file)
{
	int			i;
	t_champion	*temp;

	temp = *champ;
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		temp->comment[i] = content_file[i + PROG_NAME_LENGTH + 12];
		i++;
	}
	temp->comment[i] = '\0';
}

void 	ns_save_program_name(t_champion **champ, unsigned char *content_file)
{
	int 		i;
	t_champion	*temp;

	i = 0;
	temp = *champ;
	while (i < PROG_NAME_LENGTH)
	{
		temp->prog_name[i] = content_file[i + 4];
		i++;
	}
	temp->prog_name[i] = '\0';
}

void	ns_save_execute_code(t_champion **champ, unsigned char *content_file)
{
	unsigned int	i;
	t_champion		*temp;

	temp = *champ;
	i = 0;
	temp->exec_code = (unsigned char*)ft_strnew(temp->real_program_size);
	while (i < temp->prog_size)
	{
		temp->exec_code[i] = content_file[i + PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
		i++;
	}
	temp->exec_code[i] = '\0';
}

t_champion	*ns_save_champs(t_champion **champ, unsigned char *content_file)
{
	t_champion *temp;

	temp = *champ;
	ns_save_magic(&temp, content_file);
	ns_save_program_name(&temp, content_file);
	ns_save_program_size(&temp, content_file);
	ns_save_comment(&temp, content_file);
	ns_save_execute_code(&temp, content_file);
	temp->next = (t_champion *)malloc(sizeof(t_champion));
	temp = temp->next;
	return (temp);
}

t_champion	*ns_read_champion(char *av, t_champion **champ)
{
	int 			fd;
	off_t 			size_file;
	unsigned char	*content_file;
	t_champion		*temp;

	temp = *champ;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_printf("ERROR wrong file name\n");
	size_file = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	content_file = (unsigned char *)ft_strnew((size_t)size_file);
	read(fd, content_file, (size_t)size_file);
	temp->real_program_size = (size_t)size_file;
	return (ns_save_champs(&temp, content_file));
}
