/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:05:42 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 15:05:43 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
** You can find final state table in color at
** 'https://github.com/dborysen/Corewar/blob/master/
** assembler/lexer/Final%20state%20table.xlsx'
*/

/*
** COLUMS DEFINES IN FINAL STATE TABLE :
** 100 - [whitespace]
** 101 - [r]
** 102 - [letter]
** 103 - [digit]
** 104 - [%]
** 105 - [:]
** 106 - [,]
** 107 - [\0]
** 108 - [#]
** 109 - [-]
** 110 - [other]
*/

// int	g_state_table[19][11] =
// {
// 	{100, 105, 101, 106, 102, 108, 104, EOL, 112, 115, T_ERROR},
// 	{OPERATION, 101, 101, 110, T_ERROR, 103, OPERATION, OPERATION, OPERATION, T_ERROR, T_ERROR},
// 	{T_ERROR, T_ERROR, T_ERROR, 107, T_ERROR, 109, T_ERROR, T_ERROR, T_ERROR, 117, T_ERROR},
// 	{T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_ERROR},
// 	{SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, T_ERROR, SEP_CHAR, SEP_CHAR, SEP_CHAR, T_ERROR},
// 	{OPERATION, 101, 101, 111, T_ERROR, 103, T_ERROR, T_ERROR, OPERATION, T_ERROR, T_ERROR},
// 	{T_IND, 106, 110, 106, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
// 	{T_DIR, T_ERROR, T_ERROR, 107, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
// 	{T_ERROR, 114, 114, 114, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
// 	{T_ERROR, 113, 113, 113, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
// 	{T_ERROR, 110, 110, 110, T_ERROR, 103, T_ERROR, T_LAB, T_LAB, T_ERROR, T_ERROR},
// 	{T_REG, 110, 110, 111, T_ERROR, 103, T_REG, T_REG, T_REG, T_ERROR, T_ERROR},
// 	{112, 112, 112, 112, 112, 112, 112, COMMENT, 112, 112, 112},
// 	{T_DIR, 113, 113, 113, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
// 	{T_IND, 114, 114, 114, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
// 	{T_ERROR, T_ERROR, T_ERROR, 116, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
// 	{T_IND, T_ERROR, T_ERROR, 116, T_ERROR, T_ERROR, T_IND, T_IND, T_IND, T_ERROR, T_ERROR},
// 	{T_ERROR, T_ERROR, T_ERROR, 118, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR, T_ERROR},
// 	{T_DIR, T_ERROR, T_ERROR, 118, T_ERROR, T_ERROR, T_DIR, T_DIR, T_DIR, T_ERROR, T_ERROR},
// };

int	g_state_table[19][11] =
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

void	find_tokens(char *str, t_tokens **tk_l,
					t_func_list *state_funcs, int row_num)
{
	t_counters	*c;
	char		*tr;

	c = NULL;
	create_counter_struct(&c);
	tr = ft_strtrim(str);
	while (1)
	{
		set_state(c, tr, state_funcs);
		catch_error(c->state, c->i + 1, row_num, str);
		if (is_a_token(c->state) == TRUE)
		{
			add_nw_tkn_nd(&(*tk_l), c->state, ft_strsub(tr, c->j, c->i - c->j));
			if (c->state_column == 7 || c->state == T_ERROR)
			{
				add_nw_tkn_nd(&(*tk_l), EOL, NULL);
				ft_strdel(&tr);
				free(c);
				return ;
			}
			update_counters(c);
		}
		else
			change_state(c);
	}
}

void	set_state(t_counters *c, char *trimed_str,
								t_func_list *state_funcs)
{
	c->state_column = find_correct_state_column(trimed_str[c->i], state_funcs);
	c->state = g_state_table[c->state][c->state_column];
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