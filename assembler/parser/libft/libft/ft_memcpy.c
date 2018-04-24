/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:18:24 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 13:40:38 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*ds1;
	unsigned char	*sr1;
	size_t			i;

	i = 0;
	ds1 = (unsigned char*)(dst);
	sr1 = (unsigned char*)(src);
	while (i < n)
	{
		ds1[i] = sr1[i];
		i++;
	}
	return (ds1);
}
