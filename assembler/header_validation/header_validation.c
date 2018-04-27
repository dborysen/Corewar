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

// 	NO OPEN BRACKET 1 & 2 LINE ✅
//	NO CLOSE BRACKET 1 $ 2 LINE 
//	NO NAME OR NO COMMENT ✅
//	MORE THEN NEEDED CHAR IN NAME OR IN COMMENT
//	LESS THEN NEEDED CHAR IN NAME OR COMMENT

int     header_validation(t_data *data_from_file)
{
	if (is_only_one_name_and_one_comment(data_from_file) == TRUE 
	&& name_and_comment_are_present(data_from_file) == TRUE)
	{
		if (brackets_are_ok(data_from_file) == TRUE)
		{

		}
	}
    return (ERROR);
}

int		name_and_comment_are_present(t_data *data_from_file)
{
	if (name_is_here(data_from_file) == TRUE
	&& comment_is_here(data_from_file) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		name_is_here(t_data *data_from_file)
{
	char	**str_split;
	int		name_count;

	name_count = 0;
	while (ft_strchr(data_from_file->data, '.') != 0 || ft_strcmp(data_from_file->data, "") == 0)
	{
		str_split = ft_strsplit(data_from_file->data, ' ');
		if (ft_strcmp(str_split[0], NAME_CMD_STRING) == 0)
			name_count++;
		free_two_dem_array(str_split);
		data_from_file = data_from_file->next;
	}
	if (name_count < 1)
	{
		ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected program name \e[0m\e[0m\n");
		return (FALSE);
	}
	return (TRUE);
}

int		comment_is_here(t_data *data_from_file)
{
	char	**str_split;
	int		comment_count;

	comment_count = 0;
	while (ft_strchr(data_from_file->data, '.') != 0 || ft_strcmp(data_from_file->data, "") == 0)
	{
		str_split = ft_strsplit(data_from_file->data, ' ');
		if (ft_strcmp(str_split[0], COMMENT_CMD_STRING) == 0)
			comment_count++;
		free_two_dem_array(str_split);
		data_from_file = data_from_file->next;
	}
	if (comment_count < 1)
	{
		ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected program comment \e[0m\e[0m\n");
		return (FALSE);
	}
	return (TRUE);
}

int		brackets_are_ok(t_data *data_from_file)
{
	if (open_brackets_are_ok(data_from_file) == TRUE 
	&& close_brackets_are_ok(data_from_file) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		open_brackets_are_ok(t_data *data_from_file)
{
	int		status;
	int		line_num;

	status = TRUE;
	line_num = 1;
	while (ft_strchr(data_from_file->data, '.') != 0)
	{
		if (line_is_ok(data_from_file->data, line_num) == FALSE)
			status = FALSE;
		data_from_file = data_from_file->next;
		line_num++;
	}
	if (status == FALSE)
		return (FALSE);
	return (TRUE);
}

int		close_brackets_are_ok(t_data *data_from_file)
{
	(void)data_from_file;
	return (FALSE);
}

int		line_is_ok(char *header_str, int line_num)
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
	arrow_str = bracket_place_in_str(str, i, '^');
	bracket_str = bracket_place_in_str(str, i, '\"');
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected open bracket at [%d:%d]\e[0m\e[0m\n", line_num ,i + 1);
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
	if (is_only_one_name(data_from_file) == TRUE &&
		is_only_one_comment(data_from_file) == TRUE)
		return (TRUE);
    return (FALSE);
}

int		is_only_one_name(t_data *data_from_file)
{
	char	**split_line;
	int		name_line_count;

	name_line_count = 0;
	while (ft_strchr(data_from_file->data, '.') != 0)
	{
	    split_line = ft_strsplit(data_from_file->data, ' ');
		if (ft_strcmp(split_line[0], NAME_CMD_STRING) == 0)
		{
			if (name_line_count == 1)
			{
				ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mmore then one program name \e[0m\e[0m\n");
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

int		is_only_one_comment(t_data *data_from_file)
{
	char	**split_line;
	int		name_line_count;

	name_line_count = 0;
	while (ft_strchr(data_from_file->data, '.') != 0)
	{
	    split_line = ft_strsplit(data_from_file->data, ' ');
		if (ft_strcmp(split_line[0], COMMENT_CMD_STRING) == 0)
		{
			if (name_line_count == 1)
			{
				ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mmore then one program comment \e[0m\e[0m\n");
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

