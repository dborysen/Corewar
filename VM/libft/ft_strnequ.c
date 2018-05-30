/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:41:00 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 15:41:01 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *str1;
	char *str2;

	if (s1 && s2)
	{
		str1 = (char *)s1;
		str2 = (char *)s2;
		if (ft_strncmp(str1, str2, n) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
