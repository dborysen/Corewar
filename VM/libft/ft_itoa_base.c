/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:27:37 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:59:43 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rev(char *s, int len)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

char	*f_hex(char sixteen)
{
	if (sixteen == 'x')
		return ("0123456789absdef");
	else
		return ("0123456789ABCDEF");
}

char	*ft_itoa_base(int value, int base, char sixteen)
{
	char	*s;
	char	*hex;
	int		i;
	int		n;

	hex = f_hex(sixteen);
	n = value;
	i = 1;
	while (n /= base)
		i++;
	if (value < 0 && base == 10)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = 48;
	s[i] = '\0';
	while (value)
	{
		s[--i] = hex[value < 0 ? -(value % base) : value % base];
		value /= base;
	}
	return (s);
}
