/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di_jz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:38:47 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:22 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_di_j(va_list arg, t_flags flags)
{
	intmax_t	tmp;
	char		*str;

	tmp = va_arg(arg, intmax_t);
	str = ft_itoa_intmax(tmp);
	flags.n_chr = if_pl_sp(&flags, tmp);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += dot_di(str, flags);
	else if (flags.dot > 0 && flags.zero > 0)
		flags.n_chr += ft_aligment_diz(str, flags);
	else if (flags.dot < 0 && tmp == 0)
		return (flags.n_chr);
	else
	{
		if (flags.plus)
			flags.n_chr += ft_putchar_int('+');
		flags.n_chr += ft_putstr_int(str);
	}
	free(str);
	return (flags.n_chr);
}

int		format_di_z(va_list arg, t_flags flags)
{
	size_t	tmp;
	char	*str;

	tmp = va_arg(arg, size_t);
	str = ft_itoa(tmp);
	if (flags.space > 0 && tmp > 0 && !flags.plus)
		flags.n_chr += ft_putchar_int(' ');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += dot_di(str, flags);
	else if (flags.dot > 0 && flags.zero > 0)
		flags.n_chr += ft_aligment_diz(str, flags);
	else if (flags.dot < 0 && tmp == 0)
		return (flags.n_chr);
	else
	{
		if (flags.plus)
			flags.n_chr += ft_putchar_int('+');
		flags.n_chr += ft_putstr_int(str);
	}
	free(str);
	return (flags.n_chr);
}

int		if_pl_sp(t_flags *flags, long long tmp)
{
	if (tmp < 0 && flags->plus)
		flags->plus = 0;
	if (flags->space > 0 && tmp > 0 && !flags->plus)
		flags->n_chr += ft_putchar_int(' ');
	return (flags->n_chr);
}
