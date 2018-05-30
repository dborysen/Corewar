/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:42:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/17 16:52:45 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && i != 0 &&
			s[i + 1] != '\n' && s[i + 1] != '\0')
			word++;
		i++;
	}
	if (s[0] != '\0')
		word++;
	return (word);
}

char	*ft_words_split(const char *s, char c, int *i)
{
	char	*str;
	int		k;

	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen((char *)s)) + 1)))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char	**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		count_wrd;
	char	**str;

	i = 0;
	j = 0;
	if (s)
	{
		count_wrd = ft_count_words(s, c);
		if (!(str = (char **)malloc(sizeof(str) * (count_wrd + 1))))
			return (NULL);
		while (s[i] == c && s[i])
			i++;
		while (j < count_wrd && s[i])
		{
			str[j] = ft_words_split(s, c, &i);
			j++;
		}
		str[j] = NULL;
		return (str);
	}
	return (NULL);
}
