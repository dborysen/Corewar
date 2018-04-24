/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:58:54 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/26 14:58:54 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*in;
	char	*out;

	in = (char *)dst;
	out = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n)
	{
		*in++ = *out++;
		n--;
	}
	in = out;
	return (dst);
}
