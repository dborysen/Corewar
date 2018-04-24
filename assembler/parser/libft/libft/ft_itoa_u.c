/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:59:40 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 12:20:36 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				len_nbr_u(unsigned long long nbr)
{
	int		i;

	i = 0;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_u(unsigned long long nbr)
{
	char					*res;
	unsigned long long		r;
	int						i;

	r = nbr;
	i = len_nbr_u(r);
	res = (char*)malloc((sizeof(char) * i) + 2);
	if (!res)
		return (0);
	res[i + 1] = '\0';
	while (i >= 0)
	{
		res[i--] = r % 10 + '0';
		r = r / 10;
	}
	return (res);
}
