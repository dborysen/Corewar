/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:11:20 by klee              #+#    #+#             */
/*   Updated: 2017/11/16 15:36:43 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursio_nbr(unsigned int i, int fd)
{
	if (i / 10 != 0)
		recursio_nbr(i / 10, fd);
	ft_putchar_fd(((i % 10) + '0'), fd);
}

void		ft_putnbr_fd(int i, int fd)
{
	unsigned int r;

	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		r = -i;
	}
	else
		r = i;
	recursio_nbr(r, fd);
}
