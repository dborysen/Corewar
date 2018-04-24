/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:14:15 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 10:50:17 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	while (dst[i])
		i++;
	while (o < n && src[o])
		dst[i++] = src[o++];
	dst[i] = '\0';
	return (dst);
}
