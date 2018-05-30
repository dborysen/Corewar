/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   af_per_sc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:43:53 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/15 14:45:41 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		af_per_s(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'S')
		flags.n_chr = format_s_l(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_s_l(arg, flags);
	else
		flags.n_chr = format_s(arg, flags);
	return (flags.n_chr);
}

int		af_per_c(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'C')
		flags.n_chr = format_c_l(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_c_l(arg, flags);
	else
		flags.n_chr = format_c(arg, flags);
	return (flags.n_chr);
}

int		af_per_b(va_list arg, t_flags flags, const char *format)
{
	if (*format == 'B')
		flags.n_chr = format_b_l(arg, flags);
	else if (flags.h == 1)
		flags.n_chr = format_b_h(arg, flags);
	else if (flags.h == 2)
		flags.n_chr = format_b_hh(arg, flags);
	else if (flags.l == 1)
		flags.n_chr = format_b_l(arg, flags);
	else if (flags.l == 2)
		flags.n_chr = format_b_ll(arg, flags);
	else if (flags.j)
		flags.n_chr = format_b_j(arg, flags);
	else if (flags.z)
		flags.n_chr = format_b_z(arg, flags);
	else
		flags.n_chr = format_b(arg, flags);
	return (flags.n_chr);
}
