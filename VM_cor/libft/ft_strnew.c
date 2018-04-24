/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:45:20 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 14:45:20 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char *)malloc(sizeof(char) * size + 1);
	if (fresh)
	{
		while (i < size)
		{
			fresh[i] = 0;
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (0);
}
