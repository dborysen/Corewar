/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:50:19 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:19 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_di(va_list arg, t_flags flags)
{
	int		tmp;
	char	*str;

	tmp = va_arg(arg, int);
	str = ft_itoa(tmp);
	flags.n_chr = if_pl_sp(&flags, tmp);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0 && flags.zero == 0)
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

int		format_di_h(va_list arg, t_flags flags)
{
	short int		tmp;
	char			*str;

	tmp = va_arg(arg, int);
	str = ft_itoa(tmp);
	flags.n_chr = if_pl_sp(&flags, tmp);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0 && flags.zero == 0)
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

int		format_di_hh(va_list arg, t_flags flags)
{
	char	tmp;
	char	*str;

	tmp = va_arg(arg, int);
	str = ft_itoa(tmp);
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

int		format_di_l(va_list arg, t_flags flags)
{
	long		tmp;
	char		*str;

	tmp = va_arg(arg, long);
	str = ft_itoa(tmp);
	flags.n_chr = if_pl_sp(&flags, tmp);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0 && flags.zero == 0)
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

int		format_di_ll(va_list arg, t_flags flags)
{
	long long	tmp;
	char		*str;

	tmp = va_arg(arg, long long);
	str = ft_itoa(tmp);
	flags.n_chr = if_pl_sp(&flags, tmp);
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_dip(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += zero_di(str, flags);
	else if (flags.dot > 0 && flags.zero == 0)
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
