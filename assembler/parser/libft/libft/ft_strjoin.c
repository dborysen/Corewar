/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:14:52 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:37:34 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fresh;
	int		l1;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	fresh = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	if (fresh == 0)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (s1[l1] && (fresh[l1] = s1[l1]))
		l1++;
	while (s2[l2] && (fresh[l1++] = s2[l2++]))
		;
	fresh[l1] = '\0';
	return (fresh);
}
