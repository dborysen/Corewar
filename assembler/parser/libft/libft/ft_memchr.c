/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:04:36 by klee              #+#    #+#             */
/*   Updated: 2017/11/14 17:03:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*fnl;
	size_t			i;

	fnl = (unsigned char*)s;
	i = 0;
	while (i < n)
		if (fnl[i++] == (unsigned char)c)
		{
			fnl = fnl + i - 1;
			return ((void*)fnl);
		}
	return (0);
}
