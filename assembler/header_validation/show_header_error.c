/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_header_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:06:44 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/08 16:06:44 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_validation.h"

void	show_no_open_brecket_error(char *str, int line_num)
{
	int		i;
	char	*arrow_str;
	char	*bracket_str;

	i = 1;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	arrow_str = bracket_place_in_str(str, i - 1, '^');
	bracket_str = bracket_place_in_str(str, i - 1, '\"');
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[1;37mexpected \e[0m\e[0m");
	ft_printf("\e[1;37mopen bracket at [%d:%d]\e[0m\e[0m\n", line_num, i);
	ft_printf("\t\e[1;37m%s\e[0m\n", str);
	ft_printf("\t\e[1;36m%s\e[0m\n", arrow_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", bracket_str);
	ft_strdel(&arrow_str);
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
	ft_printf("\e[1;37mclose bracket at [%d:%d]\e[0m\e[0m\n", line_num, i);
	ft_printf("\t\e[1;37m%s\e[0m\n", header_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", arrow_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", bracket_str);
	ft_strdel(&arrow_str);
}
