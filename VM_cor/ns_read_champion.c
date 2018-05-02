/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_read_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:23:34 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/02 13:17:34 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	ns_save_program_size(t_champion **champ, unsigned char *file_info)
{
	unsigned char	str[4];
	int				i;
	t_champion		*temp;

	temp = *champ;
	i = 0;
	while (i < 4)
	{
		str[i] = file_info[PROG_NAME_LENGTH + 8 + i];
		i++;
	}
	str[i] = '\0';
	temp->size_bytes = (unsigned int)unsigned_char_to_int(str);
}

void	ns_save_magic(t_champion **champ, unsigned char *file_info)
{
	unsigned char	magic[4];
	int				i;
	t_champion		*temp;

	temp = *champ;
	i = 0;
	while (i < 4)
	{
		magic[i] = file_info[i];
		i++;
	}
	magic[i] = '\0';
	temp->magic = (unsigned int)unsigned_char_to_int(magic);
	if (temp->magic != COREWAR_EXEC_MAGIC)
		ns_error("wrong magic");
}

void	ns_save_comment(t_champion **champ, unsigned char *file_info)
{
	int			i;
	t_champion	*temp;

	temp = *champ;
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		temp->champ_comment[i] = file_info[i + PROG_NAME_LENGTH + 12];
		i++;
	}
	temp->champ_comment[i] = '\0';
}

void 	ns_save_program_name(t_champion **champ, unsigned char *file_info)
{
	int 		i;
	t_champion	*temp;

	i = 0;
	temp = *champ;
	while (i < PROG_NAME_LENGTH)
	{
		temp->champ_name[i] = file_info[i + 4];
		i++;
	}
	temp->champ_name[i] = '\0';
}

void	ns_save_execute_code(t_champion **champ, unsigned char *file_info, int fd)
{
	unsigned int	i;
	t_champion		*temp;
	off_t			size;

	temp = *champ;
	i = 0;
	size = lseek(fd, PROG_NAME_LENGTH + COMMENT_LENGTH + 16, SEEK_SET);
	if ((temp->file_size - size) != temp->size_bytes)
		ns_error("file has an invalid header");
	temp->exec_code = (unsigned char*)ft_strnew(temp->size_bytes);
	while (i < temp->size_bytes)
	{
		temp->exec_code[i] = file_info[i + PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
		i++;
	}
	temp->exec_code[i] = '\0';
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
