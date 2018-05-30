/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:13:28 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/26 15:13:28 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*in;
	char	*out;

	in = (char *)dst;
	out = (char *)src;
	if (n)
	{
		while (n)
		{
			if ((*in++ = *out++) == c)
				return (in);
			n--;
		}
	}
	return (0);
}
