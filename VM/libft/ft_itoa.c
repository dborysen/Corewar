/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:42:48 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:59:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen_l(long long n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	is_negative(long long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char		*ft_itoa(long long n)
{
	int		len;
	int		negative;
	char	*fresh;

	negative = is_negative(&n);
	len = ft_intlen_l(n);
	len += negative;
	if (n == INTMAX_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh)
	{
		fresh[len] = '\0';
		while (len--)
		{
			fresh[len] = n % 10 + '0';
			n = n / 10;
		}
		if (negative)
			fresh[0] = '-';
		return (fresh);
	}
	return (NULL);
}
