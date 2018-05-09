/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_magic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:26:50 by klee              #+#    #+#             */
/*   Updated: 2018/05/08 14:26:53 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

char			*correct_name(header_data_t header)
{
	int		position;
	char	*res;

	if (ft_strchr(header.program_name, '.'))
	{
		position = ft_strchr(header.program_name, '.') - header.program_name;
		res = ft_strdup(header.program_name);
		res[position] = '\0';
		ft_join_free(&res, ".cor");
	}
	else
	{
		res = ft_strdup(header.program_name);
		ft_join_free(&res, ".cor");
	}
	return (res);
}

void			magic_number(int fd)
{
	unsigned char		magic[4];

	magic[0] = 0x00;
	magic[1] = 0xea;
	magic[2] = 0x83;
	magic[3] = 0xf3;
	write(fd, magic, 4);
}

void			prog_length(t_str_tokens *input, int fd)
{
	unsigned char	*length;
	int				size;
	t_str_tokens	*start;
	unsigned char	*copy;

	size = 0;
	start = input;
	length = (unsigned char*)malloc(sizeof(unsigned char) * 8);
	copy = length;
	while (start)
	{
		size += start->size;
		start = start->next;
	}
	when_size_dir_eight(&length, size);
	write(fd, copy, 8);
	free(copy);
}
