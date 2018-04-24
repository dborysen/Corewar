/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:19:12 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 11:14:30 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*dop_funct(int i, int len, char *s1, char *s2)
{
	int		d;
	size_t	o;

	while (i < len && s1[i])
	{
		d = i;
		o = 0;
		while (d < len && s1[d])
		{
			if (s1[d] == s2[o])
				o++;
			else
				break ;
			d++;
		}
		if (o == ft_strlen(s2))
			return (s1 + i);
		i++;
	}
	return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	if (ft_strlen(s2) == 0)
		return (s1);
	return (dop_funct(i, len, s1, s2));
}
