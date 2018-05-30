/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:11:22 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 15:11:24 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*str;
	int		index;

	index = 0;
	if (s && f)
	{
		str = (char *)s;
		fresh = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		if (fresh)
		{
			while (str[index])
			{
				fresh[index] = (*f)(str[index]);
				index++;
			}
			fresh[index] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
