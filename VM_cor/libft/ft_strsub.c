/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:41:08 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/16 17:37:17 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*str;
	int		i;

	i = 0;
	fresh = (char *)malloc(sizeof(char) * (int)len + 1);
	if (fresh && s)
	{
		str = (char *)s;
		while (i < (int)len)
		{
			fresh[i] = str[start];
			start++;
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (0);
}
