/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:41:21 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 15:41:23 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	char	*str1;
	char	*str2;
	int		i;
	int		len;

	i = 0;
	if (s1 && s2)
	{
		str1 = (char *)s1;
		str2 = (char *)s2;
		len = (ft_strlen(str1) + ft_strlen(str2));
		fresh = (char *)malloc(sizeof(char) * len + 1);
		if (fresh)
		{
			while (*str1)
				fresh[i++] = *str1++;
			while (*str2)
				fresh[i++] = *str2++;
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (0);
}
