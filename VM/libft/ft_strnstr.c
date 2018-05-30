/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:22:07 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/16 17:37:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		size;
	char	*b;
	char	*l;
	int		i;
	int		j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	size = ft_strlen(l);
	if (!size)
		return (b);
	while (b[i] && i < (int)len)
	{
		j = 0;
		while (l[j] == b[i + j] && (i + j) < (int)len)
		{
			if (j == size - 1)
				return (b + i);
			j++;
		}
		i++;
	}
	return (0);
}
