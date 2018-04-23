/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:39:16 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/20 12:39:18 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/lexer.h"

void	free_list(t_data **head)
{
	t_data *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		ft_strdel(&tmp->data);
		free(tmp);
		tmp = NULL;
		*head = (*head)->next;
	}
}

void free_two_dem_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
	array = NULL;
}