/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:10:48 by klee              #+#    #+#             */
/*   Updated: 2018/05/01 15:10:50 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*dop_funct(int i, size_t o, char *s1, char *s2)
{
	int		d;

	if (*s1 && *s2)
		while (i >= 0)
		{
			d = i;
			o = 0;
			while (s2[o])
			{
				if (s1[d] == s2[o])
					o++;
				else
					break ;
				d++;
			}
			if (o == ft_strlen(s2))
				return (s1 + i);
			i--;
		}
	return (0);
}

char			*ft_strrstr(const char *big, const char *little)
{
	int		i;
	size_t	o;
	char	*s1;
	char	*s2;

	o = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	i = ft_strlen(s1);
	if (ft_strlen(s2) == 0)
		return (s1);
	return (dop_funct(i - 1, o, s1, s2));
}
