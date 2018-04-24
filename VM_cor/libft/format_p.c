/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:25:02 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:41 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_p(va_list arg, t_flags flags)
{
	void *v_tmp;

	v_tmp = va_arg(arg, void *);
	if (flags.alignment != 0)
		flags.n_chr = ft_aligment_p(v_tmp, flags);
	else if (flags.dot < 0 && (0 == (unsigned long)v_tmp))
	{
		flags.n_chr = ft_putstr_int("0x");
		return (flags.n_chr);
	}
	else
		flags.n_chr = ft_print_address(v_tmp, flags);
	return (flags.n_chr);
}

int		format_per(t_flags flags)
{
	if (flags.alignment != 0)
		flags.n_chr = ft_alignment_c('%', flags);
	else if (flags.zero > 0)
		flags.n_chr = ft_zero_per(flags);
	else
		flags.n_chr = ft_putchar_int('%');
	return (flags.n_chr);
}
