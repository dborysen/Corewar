/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:48:29 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/15 13:12:47 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_help	*create_node(t_help **new, int fd)
{
	*new = (t_help*)malloc(sizeof(t_help));
	(*new)->fd = fd;
	(*new)->entr_str = ft_strdup("");
	(*new)->next = NULL;
	return (*new);
}

t_help	*find_fd(t_help **txt, int fd)
{
	t_help *tmp;
	t_help *new;

	tmp = *txt;
	if (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		while (tmp->next != NULL)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	new = create_node(&new, fd);
	if (tmp != NULL)
	{
		tmp->next = new;
		return (new);
	}
	else
		*txt = new;
	return (new);
}

int		read_file(char **str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*del_me;
	int		ret;

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		del_me = *str;
		*str = ft_strjoin(*str, buf);
		free(del_me);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (ret);
}

int		find_pos_and_tail(char *str, char **tail)
{
	if (ft_strchr(str, '\n') == 0)
		*tail = 0;
	else
		*tail = ft_strdup(ft_strchr(str, '\n') + 1);
	if (ft_strchr(str, '\n'))
		return (ft_strchr(str, '\n') - str);
	else
		return (ft_strlen(str));
}

int		get_next_line(const int fd, char **line)
{
	static t_help	*txt;
	t_help			*tmp;
	int				ret;
	char			*hlp;
	int				pos;

	pos = 0;
	if (read(fd, "", 0) < 0 || line == NULL)
		return (-1);
	tmp = find_fd(&txt, fd);
	hlp = tmp->entr_str;
	if (ft_strlen(hlp) < BUFF_SIZE)
	{
		ret = read_file(&hlp, fd);
		if (ret < BUFF_SIZE && !ft_strlen(hlp))
		{
			free(tmp);
			return (0);
		}
	}
	pos = find_pos_and_tail(hlp, &tmp->entr_str);
	*line = ft_strsub(hlp, 0, pos);
	free(hlp);
	return (1);
}
