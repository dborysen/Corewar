/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_comment_present_and_only_one.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:57:20 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 15:57:21 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_validation.h"

int		is_only_one_name_and_one_comment(t_data *data_from_file)
{
	if (is_only_one_current_header(data_from_file, HEADER_NAME) == TRUE &&
		is_only_one_current_header(data_from_file, HEADER_COMMENT) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		is_only_one_current_header(t_data *data_from_file, int header)
{
	char	current_header[8];
	char	what_to_find_in_str[8];

	if (header == HEADER_NAME)
	{
		ft_strcpy(current_header, "name");
		ft_strcpy(what_to_find_in_str, ".name");
	}
	else if (header == HEADER_COMMENT)
	{
		ft_strcpy(current_header, "comment");
		ft_strcpy(what_to_find_in_str, ".comment");
	}
	return (count_header(data_from_file, what_to_find_in_str, current_header));
}

int		name_and_comment_are_present(t_data *data_from_file)
{
	if (header_is_here(data_from_file, HEADER_NAME) == TRUE
	&& header_is_here(data_from_file, HEADER_COMMENT) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		header_is_here(t_data *data_from_file, int type_of_header)
{
	int		header_count;
	char	current_header[8];
	char	what_to_find_in_str[9];

	header_count = 0;
	if (type_of_header == HEADER_NAME)
	{
		ft_strcpy(current_header, "name");
		ft_strcpy(what_to_find_in_str, ".name");
	}
	else if (type_of_header == HEADER_COMMENT)
	{
		ft_strcpy(current_header, "comment");
		ft_strcpy(what_to_find_in_str, ".comment");
	}
	header_count = find_header(data_from_file, what_to_find_in_str);
	if (header_count == 0)
	{
		ft_printf("\n\e[1;31mERROR: \e[1;37mexpected program %s \e[0m\e[0m\n\n",
		current_header);
		return (FALSE);
	}
	return (TRUE);
}

int		find_header(t_data *data_from_file, char *current_header)
{
	int		header_count;
	char	**str_split;

	header_count = 0;
	while (data_from_file != NULL)
	{
		if (ft_strchr(data_from_file->data, '.') != 0)
		{
			str_split = ft_splitwhtsp(data_from_file->data);
			if (ft_strcmp(str_split[0], current_header) == 0)
				header_count++;
			free_two_dem_array(str_split);
		}
		data_from_file = data_from_file->next;
	}
	return (header_count);
}
