/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:50:25 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:59:41 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_intmax(intmax_t n)
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

int		is_negative_intmax(intmax_t *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char	*ft_itoa_intmax(intmax_t n)
{
	int		len;
	int		negative;
	char	*fresh;

	negative = is_negative_intmax(&n);
	len = ft_intlen_intmax(n);
	len += negative;
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (n == INTMAX_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
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
