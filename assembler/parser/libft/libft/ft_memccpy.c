/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:37:07 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 13:39:46 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
		const void *restrict src, int c, size_t n)
{
	unsigned char	*ds1;
	unsigned char	*sr1;
	size_t			i;
	size_t			d;

	i = 0;
	d = 0;
	ds1 = (unsigned char*)(dst);
	sr1 = (unsigned char*)(src);
	while (i < n)
	{
		ds1[i] = sr1[i];
		if (sr1[i] == (unsigned char)c)
		{
			d = 1;
			break ;
		}
		i++;
	}
	if (d != 1)
		return (0);
	return (ds1 + i + 1);
}
