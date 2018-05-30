/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:20:51 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/26 16:20:51 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	n;
	char			*d;
	char			*s;

	n = size;
	d = dest;
	s = src;
	while (*d && n-- > 0)
		d++;
	dest_size = d - dest;
	n = size - dest_size;
	if (n == 0)
		return (dest_size + ft_strlen(s));
	while (*s)
	{
		if (n > 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dest_size + (s - src));
}
