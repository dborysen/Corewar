/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:41:05 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 14:30:26 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*beg_recursio(char *s, char c)
{
	if (*s == 0)
		return (0);
	if (*s == c)
		s = beg_recursio(s + 1, c);
	return (s);
}

static char		*change_char(char *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup(s);
	while (*(copy + i))
	{
		if (*(copy + i) == c)
			*(copy + i) = '\0';
		i++;
	}
	return (copy);
}

static int		nmb_wrd(char *copy, char c)
{
	int		count;

	count = 0;
	while (copy)
	{
		copy = beg_recursio(copy, c);
		if (copy)
		{
			count++;
			copy = ft_strchr(copy, c);
		}
	}
	return (count);
}

char			**ft_strsplit(char *s, char c)
{
	char	**fresh;
	char	*copy;
	int		count;

	if (s == NULL)
		return (0);
	copy = (char*)s;
	count = nmb_wrd(copy, c);
	fresh = (char**)malloc(sizeof((char*)s) * (count + 1));
	if (fresh == NULL)
		return (0);
	copy = (char*)s;
	while (copy)
	{
		copy = beg_recursio(copy, c);
		if (copy)
		{
			*fresh++ = change_char(copy, c);
			copy = ft_strchr(copy, c);
		}
	}
	*fresh = 0;
	return (fresh - count);
}
