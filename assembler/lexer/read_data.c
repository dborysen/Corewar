/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:54 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/24 14:46:55 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <fcntl.h>

int		read_data(t_data **champ_data, char *name_of_file)
{
	char	*line;
	int		fd;

	fd = open(name_of_file, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		new_node(&(*champ_data), line);
		ft_strdel(&line);
	}
	return (OK);
}

void	new_node(t_data **head, char *line)
{
	t_data *tmp;
	t_data *new;

	tmp = *head;
	new = (t_data*)malloc(sizeof(t_data));
	new->data = ft_strdup(line);
	new->next = NULL;
	if (*head != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}
