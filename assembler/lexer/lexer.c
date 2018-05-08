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

void	lexer(t_data *data_from_file, t_str_tokens **str_tokens)
{
	t_func_list		*state_funcs;
	t_str_tokens	*tmp;
	int				row_num;

	row_num = 1;
	state_funcs = NULL;
	fill_func_list(&state_funcs);
	if (data_from_file != NULL)
	{
		row_num = row_num + skip_name_comment_rows(&data_from_file);
		while (data_from_file != NULL)
		{
			add_node_in_tokens_strings(&(*str_tokens), data_from_file->data);
			tmp = *str_tokens;
			while (tmp->next != NULL)
				tmp = tmp->next;
			find_tokens(data_from_file->data, &(tmp->valid), state_funcs,
																row_num);
			data_from_file = data_from_file->next;
			row_num++;
		}
	}
	free_func_list(state_funcs);
}

int		rows_before_operation(t_data *data_from_file)
{
	int headers_count;
	int	skipped_rows;

	skipped_rows = 0;
	headers_count = 0;
	while (headers_count != 2)
	{
		if (ft_strchr(data_from_file->data, '.') != 0)
		{
			headers_count++;
			skipped_rows++;
		}
		if (only_hesh_coomment_line(data_from_file->data) == TRUE)
			skipped_rows++;
		data_from_file = data_from_file->next;
	}
	return (skipped_rows);
}

int		only_hesh_coomment_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '#' && str[i] != ';')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	add_nw_tkn_nd(t_tokens **token_list, int token, char *token_str)
{
	t_tokens *new;
	t_tokens *tmp;

	tmp = *token_list;
	new = (t_tokens*)malloc(sizeof(t_tokens));
	new->token = token;
	new->current_str_piece = ft_strtrim(token_str);
	new->next = NULL;
	if (*token_list == NULL)
		*token_list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (token_str != NULL)
		ft_strdel(&token_str);
}

void	add_node_in_tokens_strings(t_str_tokens **str_tokens, char *str)
{
	t_str_tokens *tmp;
	t_str_tokens *new;

	tmp = *str_tokens;
	new = (t_str_tokens*)malloc(sizeof(t_str_tokens));
	new->current_str = ft_strdup(str);
	new->valid = NULL;
	new->next = NULL;
	tmp = *str_tokens;
	if (tmp == NULL)
		*str_tokens = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
