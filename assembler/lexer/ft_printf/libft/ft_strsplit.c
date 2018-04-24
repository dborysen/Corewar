/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:11 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/20 16:04:04 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	save_array(char ***str, char const *s, char c)
{
	char	*tmp;
	char	*m;
	char	*t;
	int		b;

	b = 0;
	m = ft_strdup(s);
	tmp = m;
	while (b < ft_countw(s, c))
	{
		while (*m == c)
			m++;
		if (*m == '\0')
			break ;
		t = m;
		while (*m != c && *m++)
			;
		*m++ = '\0';
		*(*str + b++) = ft_strdup(t);
	}
	*(*str + b) = 0;
	free(tmp);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_countw(s, c) + 1))))
		return (NULL);
	save_array(&str, s, c);
	return (str);
}
