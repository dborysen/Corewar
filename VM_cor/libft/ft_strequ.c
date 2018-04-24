/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:40:50 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 15:40:51 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		str1 = (char *)s1;
		str2 = (char *)s2;
		if (ft_strlen(str1) != ft_strlen(str2))
			return (0);
		if (str1 && str2)
		{
			while (str1[i] && str2[i])
			{
				if (str1[i] != str2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}
