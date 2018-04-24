/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:31:14 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/27 14:31:15 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *fresh;

	fresh = (char *)malloc(sizeof(char) * size);
	if (fresh)
	{
		ft_bzero(fresh, size);
		return (fresh);
	}
	return (0);
}
