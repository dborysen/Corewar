/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:43:15 by klee              #+#    #+#             */
/*   Updated: 2017/11/17 17:54:31 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*dop_funct(int i, size_t o, char *s1, char *s2)
{
	int		d;

	while (s1[i])
	{
		d = i;
		o = 0;
		while (s1[d])
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

char			*ft_strstr(const char *big, const char *little)
{
	int		i;
	size_t	o;
	char	*s1;
	char	*s2;

	i = 0;
	o = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	if (ft_strlen(s2) == 0)
		return (s1);
	return (dop_funct(i, o, s1, s2));
}
