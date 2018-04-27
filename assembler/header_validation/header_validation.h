/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:15:34 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/26 13:15:35 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_VALIDATION_H
# define HEADER_VALIDATION_H

#include "../lexer/lexer.h"

/*
** ALL FUNCTIONS BELOW RETURNS (TRUE OR FALSE)
*/

int     header_validation(t_data *data_from_file);
int     is_only_one_name_and_one_comment(t_data *data_from_file);
int		is_only_one_name(t_data *data_from_file);
int		is_only_one_comment(t_data *data_from_file);

int		brackets_are_ok(t_data *data_from_file);
int		open_brackets_are_ok(t_data *data_from_file);
int		close_brackets_are_ok(t_data *data_from_file);
int		line_is_ok(char *str, int line_num);
void	show_no_open_brecket_error(char *str, int line_num);
char	*bracket_place_in_str(char *head_line, int bracket_place, char c);
int		name_and_comment_are_present(t_data *data_from_file);
int		name_is_here(t_data *data_from_file);
int		comment_is_here(t_data *data_from_file);

#endif