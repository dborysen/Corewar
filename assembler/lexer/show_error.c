/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:12:28 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 15:12:28 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	catch_error(int state, int column, int row, char *str)
{
	char *error_arrow_str;
	char *trimed_str;

	trimed_str = ft_strtrim(str);
	if (state == T_ERROR)
	{
		error_arrow_str = create_error_arrow_str(str, column - 1);
		ft_printf("\n\e[1;31mLEXICAL ERROR: \e[0m");
		ft_printf("\e[1;37mat [%d:%d]\e[0m\n", row, column);
		ft_printf("\t\e[1;37m%s\e[0m\n", trimed_str);
		ft_printf("\t\e[1;36m%s\e[0m\n", error_arrow_str);
		ft_strdel(&error_arrow_str);
	}
	ft_strdel(&trimed_str);
}

char	*create_error_arrow_str(char *str, int column)
{
	int		i;
	char	*arrow_str;
	char	*trimed_str;

	i = 0;
	trimed_str = ft_strtrim(str);
	arrow_str = ft_strdup(trimed_str);
	while (arrow_str[i] != '\0')
	{
		if (arrow_str[i] != '\t')
			arrow_str[i] = ' ';
		i++;
	}
	arrow_str[column] = '^';
	ft_strdel(&trimed_str);
	return (arrow_str);
}
