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

#include "lexer.h"

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

void	free_two_dem_array(char **array)
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

void	free_str_tokens(t_str_tokens **str_tokens)
{
	t_str_tokens *tmp;

	if (*str_tokens != NULL)
	{
		while (*str_tokens != NULL)
		{
			tmp = *str_tokens;
			ft_strdel(&tmp->current_str);
			free_tokens(&tmp->valid);
			free(tmp);
			tmp = NULL;
			*str_tokens = (*str_tokens)->next;
		}
	}
}

void	free_tokens(t_tokens **tokens)
{
	t_tokens *tmp;

	while (*tokens != NULL)
	{
		tmp = *tokens;
		ft_strdel(&tmp->current_str_piece);
		free(tmp);
		tmp = NULL;
		*tokens = (*tokens)->next;
	}
}

void	free_func_list(t_func_list *state_funcs)
{
	t_func_list *tmp;

	while (state_funcs != NULL)
	{
		tmp = state_funcs;
		free(tmp);
		tmp = NULL;
		state_funcs = state_funcs->next;
	}
}
