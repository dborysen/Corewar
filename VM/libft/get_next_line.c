/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:04:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/02/14 14:37:23 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_from_file(int const fd, char **buffer)
{
	char	*b_temp;
	char	*tmp;
	int		nb_read;

	tmp = NULL;
	b_temp = ft_strnew(BUFF_SIZE);
	nb_read = read(fd, b_temp, BUFF_SIZE);
	if (!*buffer)
		*buffer = ft_strnew(1);
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, b_temp);
	if (tmp)
		free(tmp);
	free(b_temp);
	return (nb_read);
}

int		find_endl(int const fd, char **line, char **buffer, char *endl)
{
	int		nb_read;
	char	*tmp;

	nb_read = read_from_file(fd, &buffer[fd]);
	endl = ft_strchr(buffer[fd], '\n');
	while (nb_read > 0 && !endl)
	{
		nb_read = read_from_file(fd, &buffer[fd]);
		endl = ft_strchr(buffer[fd], '\n');
	}
	if (endl)
	{
		*line = ft_strndup(buffer[fd], endl - buffer[fd]);
		tmp = buffer[fd];
		buffer[fd] = ft_strdup(endl + 1);
		free(tmp);
	}
	else if (nb_read == 0 && !endl)
	{
		if (ft_strlen(buffer[fd]) == 0)
			return (0);
		*line = ft_strdup(buffer[fd]);
		buffer[fd] = ft_bzero(buffer[fd], ft_strlen(buffer[fd]));
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buffer[4096];
	char		*endl;

	endl = NULL;
	if (fd < 0 || !line || read(fd, *line, 0) < 0)
		return (-1);
	return (find_endl(fd, line, &buffer[fd], endl));
}
