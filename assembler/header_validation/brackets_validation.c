/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:01:57 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 16:01:58 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_validation.h"

int		brackets_are_ok(t_data *data_from_file)
{
	int status;

	status = TRUE;
	if (current_brackets_is_ok(data_from_file, OPEN_BRACKET) == FALSE)
		status = FALSE;
	if (current_brackets_is_ok(data_from_file, CLOSE_BRACKET) == FALSE)
		status = FALSE;
	return (status == FALSE) ? FALSE : TRUE;
}

int		current_brackets_is_ok(t_data *data_from_file, int type_of_bracket)
{
	int		status;
	int		line_num;
	int		headers_count;
	int		(*f)(char*, int);

	status = TRUE;
	headers_count = 0;
	line_num = 1;
	if (type_of_bracket == OPEN_BRACKET)
		f = open_brackets_on_place;
	else
		f = close_brackets_on_place;
	while (headers_count < 2)
	{
		if (ft_strchr(data_from_file->data, '.') != 0 &&
		only_hesh_coomment_line(data_from_file->data) == FALSE)
		{
			if (f(data_from_file->data, line_num) == FALSE)
				status = FALSE;
			headers_count++;
		}
		data_from_file = data_from_file->next;
		line_num++;
	}
	return (status == FALSE) ? FALSE : TRUE;
}

int		close_brackets_on_place(char *header_str, int line_num)
{
	char	**split_line;
	char	*line_without_hesh;
	int		words_num;
	int		last_word_length;

	words_num = 0;
	line_without_hesh = cut_hash(header_str);
	split_line = ft_strsplit(line_without_hesh, ' ');
	words_num = count_words(line_without_hesh, ' ');
	last_word_length = ft_strlen(split_line[words_num - 1]);
	if (split_line[words_num - 1][last_word_length - 1] == '\"')
	{
		free_two_dem_array(split_line);
		ft_strdel(&line_without_hesh);
		return (TRUE);
	}
	else
		show_no_close_bracket_error(header_str, line_num);
	free_two_dem_array(split_line);
	ft_strdel(&line_without_hesh);
	return (FALSE);
}

int		open_brackets_on_place(char *header_str, int line_num)
{
	char **split_line;

	split_line = ft_splitwhtsp(header_str);
	if (ft_countw(header_str, ' ') != 1 && split_line[1][0] == '"')
	{
		free_two_dem_array(split_line);
		return (TRUE);
	}
	else
		show_no_open_brecket_error(header_str, line_num);
	free_two_dem_array(split_line);
	return (FALSE);
}

char	*bracket_place_in_str(char *head_line, int bracket_place, char c)
{
	int		i;
	char	*arrow_line;

	i = 0;
	arrow_line = ft_strdup(head_line);
	while (arrow_line[i] != '\0')
	{
		if (arrow_line[i] != '\t')
			arrow_line[i] = ' ';
		i++;
	}
	arrow_line[bracket_place] = c;
	return (arrow_line);
}
