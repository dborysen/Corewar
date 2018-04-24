/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:43:42 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:38:56 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*res;
	int		beg;
	int		end;
	int		count;

	count = 0;
	beg = 0;
	res = (char*)ft_memalloc(2);
	if (!s)
		return (res);
	while (((char)s[beg] < 33 || (char)s[beg] > 126) && s[beg])
		beg++;
	end = ft_strlen((char*)s);
	if (end == beg || end == 0)
		return (res);
	while (((char)s[end] < 33 || (char)s[end] > 126) && end >= 0)
		end--;
	free(res);
	res = (char*)ft_memalloc(end - beg + 2);
	if (res == NULL)
		return (res);
	while (beg <= end && (res[count++] = s[beg++]))
		;
	res[count] = '\0';
	return (res);
}
