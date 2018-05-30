/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u_jz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:51:30 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:35 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_u_j(va_list arg, t_flags flags)
{
	uintmax_t u_tmp;

	u_tmp = va_arg(arg, uintmax_t);
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

int		format_u_z(va_list arg, t_flags flags)
{
	size_t u_tmp;

	u_tmp = va_arg(arg, size_t);
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
