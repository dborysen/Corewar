/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:17:02 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*unsigned_itoa(unsigned long long value, int base, char sixteen)
{
	char				*str;
	unsigned long long	n;
	int					i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_intlen_u(value) + 1);
	while (value > 0)
	{
		n = value % base;
		if (sixteen == 'X')
			str[i++] = (n >= 10) ? (n - 10) + 'A' : n + '0';
		else
			str[i++] = (n >= 10) ? (n - 10) + 'a' : n + '0';
		value /= base;
	}
	if (i == 0)
		str[i++] = '0';
	str[i] = '\0';
	rev(str, i);
	return (str);
}
