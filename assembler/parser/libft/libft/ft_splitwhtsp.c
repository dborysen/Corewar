/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhtsp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:38:51 by klee              #+#    #+#             */
/*   Updated: 2018/04/19 14:38:53 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*beg_recursio(char *s)
{
	if (*s == 0)
		return (0);
	if (*s < 33 || *s > 126)
		s = beg_recursio(s + 1);
	return (s);
}

static char		*change_char(char *s)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup(s);
	while (*(copy + i))
	{
		if (*(copy + i) < 33 || *(copy + i) > 126)
			*(copy + i) = '\0';
		i++;
	}
	return (copy);
}

static int		nmb_wrd(char *copy)
{
	int		count;

	count = 0;
	while (copy)
	{
		copy = beg_recursio(copy);
		if (copy)
		{
			count++;
			while (*copy >= 33 && *copy <= 126)
				copy++;
		}
	}
	return (count);
}

char			**ft_splitwhtsp(char *s)
{
	char	**fresh;
	char	*copy;
	int		count;

	if (s == NULL)
		return (0);
	copy = (char*)s;
	count = nmb_wrd(copy);
	fresh = (char**)malloc(sizeof((char*)s) * (count + 1));
	if (fresh == NULL)
		return (0);
	copy = (char*)s;
	while (copy)
	{
		copy = beg_recursio(copy);
		if (copy)
		{
			*fresh++ = change_char(copy);
			while (*copy >= 33 && *copy <= 126)
				copy++;
		}
	}
	*fresh = 0;
	return (fresh - count);
}
