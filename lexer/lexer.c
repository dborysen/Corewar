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

/*
** COLUMS DEFINES IN FINAL STATE TABLE :
** 0 - [whitespace]
** 1 - [r]
** 2 - [letter]
** 3 - [digit]
** 4 - [%]
** 5 - [:]
** 6 - [,]
** 7 - [\0]
** 8 - [#]
** 9 - [-]
** 10 - [other]
*/

int state_table[19][11] = 
{
	{100, 105, 101, 106, 102, 108, 104, EOL, 112, 115, ERROR},
	{OPERATION, 101, 101, 110, ERROR, 103, OPERATION, OPERATION, OPERATION, ERROR, ERROR},
	{ERROR, ERROR, ERROR, 107, ERROR, 109, ERROR, ERROR, ERROR, 117, ERROR},
	{T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB},
	{SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR},
	{OPERATION, 101, 101, 111, ERROR, 103, ERROR, ERROR, OPERATION, ERROR, ERROR},
	{T_IND, 106, 110, 106, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
	{T_DIR, ERROR, ERROR, 107, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
	{ERROR, 114, 114, 114, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
	{ERROR, 113, 113, 113, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
	{ERROR, 110, 110, 110, ERROR, 103, ERROR, T_LAB, T_LAB, ERROR, ERROR},
	{T_REG, 110, 110, 111, ERROR, 103, T_REG, T_REG, T_REG, ERROR, ERROR},
	{112, 112, 112, 112, 112, 112, 112, COMMENT, 112, 112, 112},
	{T_DIR, 113, 113, 113, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
	{T_IND, 114, 114, 114, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
	{ERROR, ERROR, ERROR, 116, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
	{T_IND, ERROR, ERROR, 116, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
	{ERROR, ERROR, ERROR, 118, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
	{T_DIR, ERROR, ERROR, 118, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
};

int		rows_before_operation(t_data *data_from_file)
{
	int skipped_rows;

	skipped_rows = 0;
	if (data_from_file != NULL)
	{
		while (data_from_file->data[0] == '.')
		{
			data_from_file = data_from_file->next;
			skipped_rows++;
		}
		return (skipped_rows);
	}
	return (ERROR);
}

void	lexer(t_data *data_from_file, t_str_tokens *str_tokens)
{
	t_func_list *state_funcs;
	t_str_tokens *tmp;

	state_funcs = NULL;
	fill_func_list(&state_funcs);
	if (data_from_file != NULL)
	{
		while (data_from_file->data[0] == '.')
			data_from_file = data_from_file->next;
		while (data_from_file != NULL)
		{
			add_node_in_tokens_strings(&str_tokens, data_from_file->data);
			tmp = str_tokens;
			while (tmp->next != NULL)
				tmp = tmp->next;
			find_tokens(data_from_file->data, &(tmp->valid), state_funcs);
			data_from_file = data_from_file->next;
		}
	}
	free_func_list(state_funcs);
}

void	find_tokens(char *str, t_tokens **tokens_list, t_func_list *state_funcs)
{
	int state;
	int state_column;
	int i;
	int j;
	
	i = 0;
	j = 0;
	state = 0;
	state_column = 0;
	while (1)
	{	
		state_column = find_correct_state_column(str[i], state_funcs);
		state = state_table[state][state_column];
		if (is_a_token(state) == TRUE)
		{
			add_new_token_node(&(*tokens_list), state, ft_strsub(str, j, i - j));
			if (state_column == 7)
				return ;
			j = i + 1;
			state = 0;
			state_column = 0;
		}
		else
			state = state - 100;
		i++;
	}
}

// ⬇⬇⬇⬇⬇⬇ DON'T FORGET TO FREE THIS LIST ⬇⬇⬇⬇⬇⬇
void	add_new_token_node(t_tokens **token_list, int token, char *token_str)
{
	t_tokens *new;
	t_tokens *tmp;

	tmp = *token_list;
	new = (t_tokens*)malloc(sizeof(t_tokens));
	new->token = token;
	new->current_str_piece = token_str;
	new->next = NULL;
	if (*token_list == NULL)
		*token_list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// ⬇⬇⬇⬇⬇⬇ DON'T FORGET TO FREE THIS LIST ⬇⬇⬇⬇⬇⬇
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

int		is_a_token(int num)
{
	int i;
	int token_array[9] = {T_LAB, SEP_CHAR, T_ERROR, OPERATION, COMMENT, EOL, T_REG, T_DIR, T_IND};

	i = 0;
	while (i < 9)
	{
		if (num == token_array[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int find_correct_state_column(char c, t_func_list *state_funcs)
{
	int state_column;

	state_column = 0;
	while (state_funcs != NULL)
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