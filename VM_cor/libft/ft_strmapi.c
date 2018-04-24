/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:11:37 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 15:11:38 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*str;
	unsigned int	index;

	index = 0;
	if (s && f)
	{
		str = (char *)s;
		fresh = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		if (fresh)
		{
			while (str[index])
			{
				fresh[index] = (*f)(index, str[index]);
				index++;
			}
			fresh[index] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
