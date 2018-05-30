/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   af_per_doxu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:39:56 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:47 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		af_per_d(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'D')
		flags.n_chr = format_di_l(arg, flags);
	else if (flags.h == 1)
		flags.n_chr = format_di_h(arg, flags);
	else if (flags.h == 2)
		flags.n_chr = format_di_hh(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_di_l(arg, flags);
	else if (flags.l == 2)
		flags.n_chr = format_di_ll(arg, flags);
	else if (flags.j)
		flags.n_chr = format_di_j(arg, flags);
	else if (flags.z)
		flags.n_chr = format_di_z(arg, flags);
	else
		flags.n_chr = format_di(arg, flags);
	return (flags.n_chr);
}

int		af_per_o(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'O')
		flags.n_chr = format_o_l(arg, flags);
	else if (flags.h == 1)
		flags.n_chr = format_o_h(arg, flags);
	else if (flags.h == 2)
		flags.n_chr = format_o_hh(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_o_l(arg, flags);
	else if (flags.l == 2)
		flags.n_chr = format_o_ll(arg, flags);
	else if (flags.j)
		flags.n_chr = format_o_j(arg, flags);
	else if (flags.z)
		flags.n_chr = format_o_z(arg, flags);
	else
		flags.n_chr = format_o(arg, flags);
	return (flags.n_chr);
}

int		af_per_x(va_list arg, t_flags flags, const char *format)
{
	if (flags.h == 1)
		flags.n_chr = format_x_h(arg, flags, *format);
	else if (flags.h == 2)
		flags.n_chr = format_x_hh(arg, flags, *format);
	else if (flags.l == 1)
		flags.n_chr = format_x_l(arg, flags, *format);
	else if (flags.l == 2)
		flags.n_chr = format_x_ll(arg, flags, *format);
	else if (flags.j)
		flags.n_chr = format_x_j(arg, flags, *format);
	else if (flags.z)
		flags.n_chr = format_x_z(arg, flags, *format);
	else
		flags.n_chr = format_x(arg, flags, *format);
	return (flags.n_chr);
}

int		af_per_u(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'U')
		flags.n_chr = format_u_l(arg, flags);
	else if (flags.h == 1)
		flags.n_chr = format_u_h(arg, flags);
	else if (flags.h == 2)
		flags.n_chr = format_u_hh(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_u_l(arg, flags);
	else if (flags.l == 2)
		flags.n_chr = format_u_ll(arg, flags);
	else if (flags.j)
		flags.n_chr = format_u_j(arg, flags);
	else if (flags.z)
		flags.n_chr = format_u_z(arg, flags);
	else
		flags.n_chr = format_u(arg, flags);
	return (flags.n_chr);
}
