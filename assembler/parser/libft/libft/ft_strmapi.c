/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:06:40 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:11:35 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	if (!s)
		return (0);
	fresh = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (fresh == NULL)
		return (0);
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
