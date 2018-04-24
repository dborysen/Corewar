/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:17:45 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/26 15:17:46 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*in;
	const char	*out;
	int			i;

	in = dst;
	out = src;
	i = 0;
	if (in <= out)
		while (n)
		{
			in[i] = out[i];
			i++;
			n--;
		}
	else
	{
		i = n;
		while (i > 0)
		{
			in[i - 1] = out[i - 1];
			i--;
		}
	}
	return (dst);
}
