/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:32:28 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:13 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dot_str(char *str, t_flags flags)
{
	while ((flags.dot - (int)ft_strlen(str)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.dot -= 1;
	}
	flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}

int		ft_dot_u(unsigned int u_tmp, t_flags flags)
{
	while ((flags.dot - ft_intlen_u(u_tmp)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.dot -= 1;
	}
	ft_putnbr_u(u_tmp);
	flags.n_chr += ft_intlen_u(u_tmp);
	return (flags.n_chr);
}

int		dot_di(char *str, t_flags flags)
{
	if (*str == '-')
	{
		flags.n_chr += ft_putchar_int(*str);
		str++;
	}
	if (flags.plus > 0)
		flags.n_chr += ft_putchar_int('+');
	while ((flags.dot - (int)ft_strlen(str)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.dot -= 1;
	}
	flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr - flags.space);
}
