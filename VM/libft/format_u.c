/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:49:54 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:32 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_u(va_list arg, t_flags flags)
{
	unsigned int u_tmp;

	u_tmp = va_arg(arg, unsigned int);
	if (flags.alignment != 0)
		flags.n_chr = ft_aligment_u(u_tmp, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_u(u_tmp, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_u(u_tmp, flags);
	else if (flags.dot < 0 && u_tmp == 0)
		return (flags.n_chr);
	else
	{
		ft_putnbr_u(u_tmp);
		flags.n_chr = ft_intlen_u(u_tmp);
	}
	return (flags.n_chr);
}

int		format_u_h(va_list arg, t_flags flags)
{
	unsigned short u_tmp;

	u_tmp = va_arg(arg, unsigned int);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_u(u_tmp, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_u(u_tmp, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_u(u_tmp, flags);
	else
	{
		ft_putnbr_u(u_tmp);
		flags.n_chr += ft_intlen_u(u_tmp);
	}
	return (flags.n_chr);
}

int		format_u_hh(va_list arg, t_flags flags)
{
	unsigned char u_tmp;

	u_tmp = va_arg(arg, unsigned int);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_u(u_tmp, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_u(u_tmp, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_u(u_tmp, flags);
	else
	{
		ft_putnbr_u(u_tmp);
		flags.n_chr += ft_intlen_u(u_tmp);
	}
	return (flags.n_chr);
}

int		format_u_l(va_list arg, t_flags flags)
{
	unsigned long u_tmp;

	u_tmp = va_arg(arg, unsigned long);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_u(u_tmp, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_u(u_tmp, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_u(u_tmp, flags);
	else
	{
		ft_putnbr_u(u_tmp);
		flags.n_chr += ft_intlen_u(u_tmp);
	}
	return (flags.n_chr);
}

int		format_u_ll(va_list arg, t_flags flags)
{
	unsigned long long u_tmp;

	u_tmp = va_arg(arg, unsigned long long);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_u(u_tmp, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_u(u_tmp, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_u(u_tmp, flags);
	else
	{
		ft_putnbr_u(u_tmp);
		flags.n_chr += ft_intlen_u(u_tmp);
	}
	return (flags.n_chr);
}
