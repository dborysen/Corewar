/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:58:33 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/26 17:58:33 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(char c, int *z)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*z = -1;
		return (1);
	}
	return (0);
}

int			ft_atoi(char *str)
{
	int					i;
	int					z;
	unsigned long int	n;

	z = 1;
	n = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (is_negative(str[i], &z) && ft_isdigit(str[i + 1]))
	{
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((n > 922337203685477580 || (n == 922337203685477580
			&& (str[i] - '0') > 7)) && z == 1)
			return (-1);
		else if ((n > 922337203685477580 || (n == 922337203685477580
				&& (str[i] - '0') > 8)) && z == -1)
			return (0);
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return ((int)n * z);
}
