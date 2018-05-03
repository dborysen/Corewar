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

int     header_validation(t_data *data_from_file)
{
	if (is_only_one_name_and_one_comment(data_from_file) == TRUE 
	&& name_and_comment_are_present(data_from_file) == TRUE)
	{
		if (brackets_are_ok(data_from_file) == TRUE)
			return (OK);
	}
    return (ERROR);
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
	char	what_to_find_in_str[8];	

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
			str_split = ft_strsplit(data_from_file->data, ' ');
			if (ft_strcmp(str_split[0], current_header) == 0)
				header_count++;
			free_two_dem_array(str_split);
		}
		data_from_file = data_from_file->next;
	}
	return (header_count);
}

int		brackets_are_ok(t_data *data_from_file)
{
	if (current_brackets_is_ok(data_from_file, OPEN_BRACKET) == TRUE 
	&& current_brackets_is_ok(data_from_file, CLOSE_BRACKET) == TRUE)
		return (TRUE);
	return (FALSE);
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
		if (ft_strchr(data_from_file->data, '.') != 0)
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

	(void)line_num;
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

void	show_no_close_bracket_error(char *header_str, int line_num)
{
	int		i;
	char	*arrow_str;
	char	*bracket_str;

	i = ft_strlen(header_str);
	arrow_str = bracket_place_in_str(header_str, i - 1, '^');
	bracket_str = bracket_place_in_str(header_str, i - 1, '\"');
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected \e[0m\e[0m");
	ft_printf("\e[1;37mclose bracket at [%d:%d]\e[0m\e[0m\n", line_num , i);
	ft_printf("\t\e[1;37m%s\e[0m\n", header_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", arrow_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", bracket_str);
	ft_strdel(&arrow_str);
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
		if (header_str[i] == '#' && bracket_count == 2)
			break;
		i++;
	}
	line_without_hash = ft_strsub(header_str, 0, i);
	return (line_without_hash);
}

int		open_brackets_on_place(char *header_str, int line_num)
{
	char **split_line;

	split_line = ft_strsplit(header_str, ' ');
	if (split_line[1][0] == '"')
	{
		free_two_dem_array(split_line);
		return (TRUE);
	}
	else
		show_no_open_brecket_error(header_str, line_num);
	free_two_dem_array(split_line);
	return (FALSE);
}

void	show_no_open_brecket_error(char *str, int line_num)
{
	int i;
	char *arrow_str;
	char *bracket_str;

	i = 1;
	while (str[i] != ' ' && str[i] != '\t' )
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	arrow_str = bracket_place_in_str(str, i - 1, '^');
	bracket_str = bracket_place_in_str(str, i - 1, '\"');
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected \e[0m\e[0m");
	ft_printf("\e[1;37mopen bracket at [%d:%d]\e[0m\e[0m\n", line_num , i);
	ft_printf("\t\e[1;37m%s\e[0m\n", str);
	ft_printf("\t\e[1;36m%s\e[0m\n", arrow_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", bracket_str);
	ft_strdel(&arrow_str);
}

char	*bracket_place_in_str(char *head_line, int bracket_place, char c)
{
	int		i;
	char	*arrow_line;
	
	i = 0;
	arrow_line = ft_strdup(head_line);
	while (arrow_line[i] != '\0')
	{
		arrow_line[i] = ' ';
		i++;
	}
	arrow_line[bracket_place] = c;
	return (arrow_line);
}

int     is_only_one_name_and_one_comment(t_data *data_from_file)
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

int		count_header(t_data *data_from_file, char *what_to_find_in_str, char *current_header)
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
