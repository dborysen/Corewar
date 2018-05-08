/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:10:03 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/03 16:10:04 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		validation(t_data *data_from_file, char *name_of_program)
{
	int				skipped_rows;
	t_str_tokens	*str_tokens;
	header_data_t	header_data;

	str_tokens = NULL;
	skipped_rows = 0;
	if (header_validation(data_from_file) == OK)
	{
		header_data = fill_header_data(data_from_file, name_of_program);
		skipped_rows = rows_before_operation(data_from_file);
		lexer(data_from_file, &str_tokens);
		parsing(str_tokens, skipped_rows);
		corefile(str_tokens, header_data, skipped_rows);
		free_str_tokens(&str_tokens);
		ft_strdel(&header_data.bot_comment);
		ft_strdel(&header_data.bot_name);
		ft_strdel(&header_data.program_name);
	}
	return (OK);
}

header_data_t	fill_header_data(t_data *data_from_file, char *name_of_program)
{
	header_data_t header_data;

	header_data.program_name = ft_strdup(name_of_program);
	header_data.bot_name = find_bot_header(data_from_file, HEADER_NAME);
	header_data.bot_comment = find_bot_header(data_from_file, HEADER_COMMENT);
	return (header_data);
}

char			*find_bot_header(t_data *data_from_file, int header_type)
{
	char	*needed_header;
	char	what_to_search_in_str[9];
	int		max_header_length;

	max_header_length = 0;
	if (header_type == HEADER_NAME)
	{	
		ft_strcpy(what_to_search_in_str, ".name");
		max_header_length = PROG_NAME_LENGTH;
	}
	else if (header_type == HEADER_COMMENT)
	{
		ft_strcpy(what_to_search_in_str, ".comment");
		max_header_length = COMMENT_LENGTH + 4;
	}
	while (data_from_file != NULL)
	{
		if (ft_strstr(data_from_file->data, what_to_search_in_str) != 0)
			needed_header = save_header(data_from_file->data, max_header_length,
																	header_type);
		data_from_file = data_from_file->next;
	}	
	return (needed_header);
}

char			*save_header(char *str, int max_length, int header_type)
{
	char	*header;
	int		start_of_header;
	int		length_of_header;
	int		i;

	header = NULL;
	start_of_header = 0;
	length_of_header = 0;
	while (str[start_of_header] != '"')
		start_of_header++;
	start_of_header++;
	i = start_of_header;
	while (str[i] != '"')
	{
		length_of_header++;
		i++;
	}
	if (length_of_header > max_length)
		show_not_valid_header_length_error(header_type, max_length);
	else
		header = fill_header(str, start_of_header, max_length);
	return (header);
}

char			*fill_header(char *str, int start_of_header, int max_length)
{
	char	*header;
	int		i;

	i = 0;
	header = (char*)malloc(sizeof(char) * max_length);
	while (str[start_of_header] != '"')
	{
		header[i] = str[start_of_header];
		start_of_header++;
		i++;
	}
	while (i < max_length)
	{
		header[i] = 0;
		i++;
	}
	return (header);
}

void			show_not_valid_header_length_error(int header_type, 
													int max_length)
{
	char	current_header[9];

	if (header_type == HEADER_NAME)
		ft_strcpy(current_header, "name");
	else if (header_type == HEADER_COMMENT)
		ft_strcpy(current_header, "comment");
	ft_printf("\n\e[1;31mERROR:\e[0m\e[1;37m Champion %s\e[0m", current_header);
	ft_printf("\e[0m\e[1;37m is to long (max length %d)\n\n\e[0m", max_length);
}