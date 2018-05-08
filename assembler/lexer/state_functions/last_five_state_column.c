/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-9_state_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:02:37 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/20 14:02:37 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	is_double_dot(char c)
{
	if (c == ':')
		return (TRUE);
	return (FALSE);
}

int	is_comma(char c)
{
	if (c == ',')
		return (TRUE);
	return (FALSE);
}

int	is_eol(char c)
{
	if (c == '\0')
		return (TRUE);
	return (FALSE);
}

int	is_hash(char c)
{
	if (c == '#' || c == ';')
		return (TRUE);
	return (FALSE);
}

int	is_minus(char c)
{
	if (c == '-')
		return (TRUE);
	return (FALSE);
}
