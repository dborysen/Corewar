/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-4_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:00:51 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/20 14:00:52 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (TRUE);
	return (FALSE);
}

int	is_r_letter(char c)
{
	if (c == 'r')
		return (TRUE);
	return (FALSE);
}

int	is_letter(char c)
{
	if (ft_isalpha(c) == 1 || c == '_')
		return (TRUE);
	return (FALSE);
}

int	is_digit(char c)
{
	if (ft_isdigit(c) == 1)
		return (TRUE);
	return (FALSE);
}

int is_proc(char c)
{
	if (c == '%')
		return (TRUE);
	return (FALSE);
}