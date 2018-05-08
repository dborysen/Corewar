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
** 
*/

int state_table[19][11] = 
{
	{100, 105, 101, 106, 102, 108, 104, EOL, 112, 115, T_ERROR},
	{OPERATION, 101, 101, 110, T_ERROR, 103, OPERATION, OPERATION, OPERATION, T_ERROR, T_ERROR},
	{T_ERROR, T_ERROR, T_ERROR, 107, T_ERROR, 109, T_ERROR, T_ERROR, T_ERROR, 117, T_ERROR},
	{T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_ERROR},
	{SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, T_ERROR, SEP_CHAR, SEP_CHAR, SEP_CHAR, T_ERROR},
	{OPERATION, 101, 101, 111, T_ERROR, 103, T_ERROR, T_ERROR, OPERATION, T_ERROR, T_ERROR},
	{T_IND, 106, 110, 106, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
	{T_DIR, T_ERROR, T_ERROR, 107, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
	{T_ERROR, 114, 114, 114, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
	{T_ERROR, 113, 113, 113, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
	{T_ERROR, 110, 110, 110, T_ERROR, 103, T_ERROR, T_LAB, T_LAB, T_ERROR, T_ERROR},
	{T_REG, 110, 110, 111, T_ERROR, 103, T_REG, T_REG, T_REG, T_ERROR, T_ERROR},
	{112, 112, 112, 112, 112, 112, 112, COMMENT, 112, 112, 112},
	{T_DIR, 113, 113, 113, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
	{T_IND, 114, 114, 114, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
	{T_ERROR, T_ERROR, T_ERROR, 116, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
	{T_IND, T_ERROR, T_ERROR, 116, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
	{T_ERROR, T_ERROR, T_ERROR, 118, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
	{T_DIR, T_ERROR, T_ERROR, 118, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
};

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
	while (str[i] != '\0' && str[i] != '#')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

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
			find_tokens(data_from_file->data, &(tmp->valid), state_funcs, row_num);
			data_from_file = data_from_file->next;
			row_num++;
		}
	}
	free_func_list(state_funcs);
}

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

void	find_tokens(char *str, t_tokens **tokens_list,
					t_func_list *state_funcs, int row_num)
{
	t_counters	*c;
	char		*trimed_str;
	
	c = NULL;
	create_counter_struct(&c);
	trimed_str = ft_strtrim(str);
	while (1)
	{	
		set_state(c, trimed_str, state_funcs);
		catch_error(c->state, c->i + 1, row_num, str);
		if (is_a_token(c->state) == TRUE)
		{
			add_new_token_node(&(*tokens_list), c->state, ft_strsub(trimed_str, c->j, c->i - c->j));
			if (c->state_column == 7 || c->state == T_ERROR)
			{
				add_new_token_node(&(*tokens_list), EOL, NULL);
				ft_strdel(&trimed_str);
				free(c);
				return ;
			}
			update_counters(c);
		}
		else
			change_state(c);
	}
}

void	set_state(t_counters *counter, char *trimed_str, t_func_list *state_funcs)
{
	counter->state_column = find_correct_state_column(trimed_str[counter->i], state_funcs);
	counter->state = state_table[counter->state][counter->state_column];
}

void	update_counters(t_counters *counter)
{
	counter->j = counter->i;
	counter->state = 0;
	counter->state_column = 0;
}

void	change_state(t_counters *counter)
{
	counter->state = counter->state - 100;
	counter->i++;
}

void	create_counter_struct(t_counters **head)
{
	t_counters *counter;
	counter = (t_counters*)malloc(sizeof(t_counters));
	counter->i = 0;
	counter->j = 0;
	counter->state = 0;
	counter->state_column = 0;
	*head = counter;
}

void		catch_error(int state, int column, int row, char *str)
{
	char *error_arrow_str;
	char *trimed_str;

	trimed_str = ft_strtrim(str);
	if (state == T_ERROR)
	{
		error_arrow_str = create_error_arrow_str(str, column - 1);		
		ft_printf("\n\e[1;31mLEXICAL ERROR: \e[1;37mat [%d:%d]\e[0m\e[0m\n", row, column);
		ft_printf("\t\e[1;37m%s\e[0m\n", trimed_str);
		ft_printf("\t\e[1;36m%s\e[0m\n", error_arrow_str);
		ft_strdel(&error_arrow_str);
	}
	ft_strdel(&trimed_str);
}

char	*create_error_arrow_str(char *str, int column)
{
	int		i;
	char	*arrow_str;
	char	*trimed_str;

	i = 0;
	trimed_str = ft_strtrim(str);
	arrow_str = ft_strdup(trimed_str);
	while (arrow_str[i] != '\0')
	{
		if (arrow_str[i] != '\t')
			arrow_str[i] = ' ';
		i++;
	}
	arrow_str[column] = '^';
	ft_strdel(&trimed_str);
	return (arrow_str);
}

void	add_new_token_node(t_tokens **token_list, int token, char *token_str)
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