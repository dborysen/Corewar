/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:43:47 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:42 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_int(char const *s)
{
	int		i;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	if (s)
	{
		str = (char *)s;
		while (str[i])
		{
			count += ft_putchar_int(str[i]);
			i++;
		}
	}
	return (count);
}
