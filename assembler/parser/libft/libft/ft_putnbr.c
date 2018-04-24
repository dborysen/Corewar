/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:09:12 by klee              #+#    #+#             */
/*   Updated: 2017/11/16 15:32:23 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursio_nbr(unsigned int i)
{
	if (i / 10 != 0)
		recursio_nbr(i / 10);
	ft_putchar((i % 10) + '0');
}

void		ft_putnbr(int i)
{
	unsigned int r;

	if (i < 0)
	{
		ft_putchar('-');
		r = -i;
	}
	else
		r = i;
	recursio_nbr(r);
}
