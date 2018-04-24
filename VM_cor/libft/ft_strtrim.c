/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:42:17 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 16:42:17 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_space(char *str, int *len, int *i)
{
	while (str[*len - 1] == ' ' ||
			str[*len - 1] == '\t' || str[*len - 1] == '\n')
		*len -= 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
	{
		*len -= 1;
		*i += 1;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (s)
	{
		str = (char *)s;
		len = ft_strlen(str);
		is_space(str, &len, &i);
		if (len < 0)
			len = 0;
		fresh = (char *)malloc(sizeof(char) * len + 1);
		if (fresh)
		{
			str += i;
			i = 0;
			while (i < len)
				fresh[i++] = *str++;
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
