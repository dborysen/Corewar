/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:59:40 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 11:51:58 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		m_str(char stri, int *d, int *c)
{
	if (stri == '-')
	{
		*c = (*c) + 1;
		*d = -1;
	}
	if (stri == '+')
		*c = (*c) + 1;
}

int				ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						i;
	int						c;
	int						d;

	res = 0;
	d = 1;
	i = 0;
	c = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\t' || str[i] == '\r' || str[i] == '\f') && c == 0 && res == 0)
			;
		else if ((str[i] == '-' || str[i] == '+') && res == 0)
			m_str(str[i], &d, &c);
		else if (str[i] >= '0' && str[i] <= '9' && c <= 1)
			res = (res * 10) + str[i] - '0';
		else
			break ;
		i++;
	}
	if (res > 9223372036854775807)
		res = (d < 0) ? 0 : -1;
	return (c <= 1) ? ((int)res * d) : 0;
}
