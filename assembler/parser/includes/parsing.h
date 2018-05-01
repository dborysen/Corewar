/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:41:35 by klee              #+#    #+#             */
/*   Updated: 2018/04/17 17:41:43 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define ERROR -1
# define OK 0

#include "../../lexer/lexer.h"

typedef struct	s_op
{
	char *name;
	int numb;
	int arg[3];
	int i;
	int i1;
	char *str;
	int i2;
	int i3;
}				t_op;

int			parsing(t_str_tokens *input, int count);
int			after_label(t_str_tokens *input, int index);
t_op		f_arguments(char *operation);
int			check_the_args(t_op args, t_str_tokens *input, int index);
int			error_messege(t_str_tokens *input, t_tokens *input_tokens, int index);
int			error_messege_for_arguments(t_str_tokens *input, t_tokens *input_tokens, t_op args, int index);
int			number_of_arguments(t_op args, t_str_tokens *input, int index);
int			error_messege_if_not_enough(t_str_tokens *input, t_op args, int index);
int			error_messege_for_operation(t_str_tokens *input,
			t_tokens *input_tokens,int index);
char		*arrow_in_str(char *head_line, int arrow_place);

#endif