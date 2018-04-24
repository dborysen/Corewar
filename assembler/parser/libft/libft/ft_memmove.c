/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:39:37 by klee              #+#    #+#             */
/*   Updated: 2017/11/16 13:58:14 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d1;
	char *s1;

	d1 = (char*)dst;
	s1 = (char*)src;
	if (s1 < d1)
		while (len--)
			d1[len] = s1[len];
	else
		ft_memcpy(d1, s1, len);
	return (d1);
}
