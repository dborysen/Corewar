/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:51:50 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/26 12:51:51 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_validation.h"

int		header_validation(t_data *data_from_file)
{
	if (is_only_one_name_and_one_comment(data_from_file) == TRUE
	&& name_and_comment_are_present(data_from_file) == TRUE)
	{
		if (brackets_are_ok(data_from_file) == TRUE)
			return (OK);
	}
	return (ERROR);
}

int		count_words(char const *s, char c)
{
	int state;
	int words;
	int i;

	state = 0;
	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			state = 0;
		else if (state == 0)
		{
			state = 1;
			words++;
		}
		i++;
	}
	return (words);
}

char	*cut_hash(char *header_str)
{
	int		i;
	int		bracket_count;
	char	*line_without_hash;

	i = 0;
	bracket_count = 0;
	while (header_str[i] != '\0')
	{
		if (header_str[i] == '\"')
			bracket_count++;
		if ((header_str[i] == '#' || header_str[i] == ';') &&
											bracket_count == 2)
			break ;
		i++;
	}
	line_without_hash = ft_strsub(header_str, 0, i);
	return (line_without_hash);
}

int		count_header(t_data *data_from_file, char *what_to_find_in_str,
												char *current_header)
{
	char	**split_line;
	int		name_line_count;

	name_line_count = 0;
	while (data_from_file != NULL)
	{
		split_line = ft_strsplit(data_from_file->data, ' ');
		if (ft_strcmp(split_line[0], what_to_find_in_str) == 0)
		{
			if (name_line_count == 1)
			{
				ft_printf("\n\e[1;31mERROR: \e[1;37mmore then one\e[0m\e[0m");
				ft_printf("\e[1;37m program %s\e[0m\e[0m\n\n", current_header);
				free_two_dem_array(split_line);
				return (FALSE);
			}
			name_line_count++;
		}
		free_two_dem_array(split_line);
		data_from_file = data_from_file->next;
	}
	return (TRUE);
}
