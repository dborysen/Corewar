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
# define OPEN_BRACKET 1
# define CLOSE_BRACKET 2
# define HEADER_NAME 1
# define HEADER_COMMENT 2

#include "../lexer/lexer.h"

int     header_validation(t_data *data_from_file);
int     is_only_one_name_and_one_comment(t_data *data_from_file);
int		is_only_one_current_header(t_data *data_from_file, int header);
int		brackets_are_ok(t_data *data_from_file);
int		current_brackets_is_ok(t_data *data_from_file, int type_of_bracket);
int		open_brackets_on_place(char *str, int line_num);
int		close_brackets_on_place(char *header_str, int line_num);
void	show_no_open_brecket_error(char *str, int line_num);
char	*bracket_place_in_str(char *head_line, int bracket_place, char c);
int		name_and_comment_are_present(t_data *data_from_file);
int		header_is_here(t_data *data_from_file, int type_of_header);
int		find_header(t_data *data_from_file, char *current_header);
int		count_header(t_data *data_from_file, char *what_to_find_in_str, char *current_header);
char	*cut_hash(char *header_str);
int		count_words(char const *s, char c);
void	show_no_close_bracket_error(char *header_str, int line_num);

#endif