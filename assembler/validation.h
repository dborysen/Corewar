/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:10:53 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/03 16:10:53 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
#include "lexer/lexer.h"
#include "parser/includes/parsing.h"
#include "header_validation/header_validation.h"



typedef struct	header_data_s
{
	char *program_name;
	char *bot_name;
	char *bot_comment;
}				header_data_t;

int				validation(t_data *data_from_file, char *name_of_program);
header_data_t	fill_header_data(t_data *data_from_file, char *name_of_program);
char			*find_bot_header(t_data *data_from_file, int header_type);
char			*save_header(char *str, int max_length, int header_type);
void			show_not_valid_header_length_error(int header_type, int max_length);
char			*fill_header(char *str, int start_of_header, int max_length);

#endif