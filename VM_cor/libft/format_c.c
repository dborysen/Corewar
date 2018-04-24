/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:52:50 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:24 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_alignment_c_wchar(wchar_t tmp, t_flags flags)
{
	if (flags.alignment > 0)
	{
		while ((flags.alignment - 1) > 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			flags.alignment -= 1;
		}
		flags.n_chr += ft_print_wchar(tmp, flags);
	}
	else if (flags.alignment < 0)
	{
		flags.n_chr += ft_print_wchar(tmp, flags);
		while ((flags.alignment + 1) < 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			flags.alignment += 1;
		}
	}
	return (flags.n_chr);
}

int		ft_zero_c(t_flags flags, char tmp)
{
	while ((flags.zero - 1) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	flags.n_chr += ft_putchar_int(tmp);
	return (flags.n_chr);
}

int		format_c(va_list arg, t_flags flags)
{
	int tmp;

	tmp = va_arg(arg, int);
	if (flags.alignment != 0)
		flags.n_chr = ft_alignment_c(tmp, flags);
	else if (flags.zero > 0)
		flags.n_chr += ft_zero_c(flags, tmp);
	else
		flags.n_chr = ft_putchar_int(tmp);
	return (flags.n_chr);
}

int		format_c_l(va_list arg, t_flags flags)
{
	wchar_t tmp;

	tmp = va_arg(arg, wchar_t);
	if (flags.alignment != 0)
		flags.n_chr = ft_alignment_c_wchar(tmp, flags);
	else if (flags.zero > 0)
		flags.n_chr += ft_zero_c(flags, tmp);
	else
		flags.n_chr = ft_print_wchar(tmp, flags);
	return (flags.n_chr);
}
