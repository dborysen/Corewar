/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_state_attributes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:16:20 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 15:16:21 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		skip_name_comment_rows(t_data **data_from_file)
{
	int headers_count;
	int	skipped_rows;

	skipped_rows = 0;
	headers_count = 0;
	while (headers_count != 2)
	{
		if (ft_strchr((*data_from_file)->data, '.') != 0 &&
		only_hesh_coomment_line((*data_from_file)->data) == FALSE)
		{
			headers_count++;
			skipped_rows++;
		}
		if (only_hesh_coomment_line((*data_from_file)->data) == TRUE)
			skipped_rows++;
		*data_from_file = (*data_from_file)->next;
	}
	return (skipped_rows);
}

int		is_a_token(int num)
{
	int i;
	int token_array[9];

	token_array[0] = T_LAB;
	token_array[1] = SEP_CHAR;
	token_array[2] = T_ERROR;
	token_array[3] = OPERATION;
	token_array[4] = COMMENT;
	token_array[5] = EOL;
	token_array[6] = T_REG;
	token_array[7] = T_DIR;
	token_array[8] = T_IND;
	i = 0;
	while (i < 9)
	{
		if (num == token_array[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		find_correct_state_column(char c, t_func_list *state_funcs)
{
	int state_column;

	state_column = 0;
	while (state_funcs != NULL && state_column < 10)
	{
		if (state_funcs->f(c) == TRUE)
			return (state_column);
		state_funcs = state_funcs->next;
		state_column++;
	}
	return (state_column);
}

void	fill_func_list(t_func_list **state_funcs)
{
	add_func_in_list(&(*state_funcs), &is_white_space);
	add_func_in_list(&(*state_funcs), &is_r_letter);
	add_func_in_list(&(*state_funcs), &is_letter);
	add_func_in_list(&(*state_funcs), &is_digit);
	add_func_in_list(&(*state_funcs), &is_proc);
	add_func_in_list(&(*state_funcs), &is_double_dot);
	add_func_in_list(&(*state_funcs), &is_comma);
	add_func_in_list(&(*state_funcs), &is_eol);
	add_func_in_list(&(*state_funcs), &is_hash);
	add_func_in_list(&(*state_funcs), &is_minus);
}

void	add_func_in_list(t_func_list **state_funcs, int (*f)(char))
{
	t_func_list *new;
	t_func_list *tmp_state_funcs;

	tmp_state_funcs = *state_funcs;
	new = (t_func_list*)malloc(sizeof(t_func_list));
	new->f = *f;
	new->next = NULL;
	if (*state_funcs == NULL)
		*state_funcs = new;
	else
	{
		while (tmp_state_funcs->next != NULL)
			tmp_state_funcs = tmp_state_funcs->next;
		tmp_state_funcs->next = new;
	}
}
