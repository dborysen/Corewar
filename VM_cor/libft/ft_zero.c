/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:34:07 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:54 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_zero_str(char *str, t_flags flags)
{
	while ((flags.zero - (int)ft_strlen(str)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}

int		zero_di(char *str, t_flags flags)
{
	if (*str == '-')
	{
		flags.n_chr += ft_putchar_int(*str);
		flags.zero -= 1;
		str++;
	}
	if (flags.plus > 0)
	{
		flags.n_chr += ft_putchar_int('+');
		flags.zero -= 1;
	}
	if (flags.space > 0)
	{
		flags.n_chr += ft_putchar_int(' ');
		flags.zero -= 1;
	}
	while ((flags.zero - (int)ft_strlen(str)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}

int		ft_zero_u(unsigned int u_tmp, t_flags flags)
{
	while ((flags.zero - ft_intlen_u(u_tmp)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	ft_putnbr_u(u_tmp);
	flags.n_chr += ft_intlen_u(u_tmp);
	return (flags.n_chr);
}

int		ft_zero_per(t_flags flags)
{
	while ((flags.zero - 1) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	flags.zero = 0;
	flags.n_chr += ft_putchar_int('%');
	return (flags.n_chr);
}
