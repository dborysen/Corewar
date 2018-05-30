/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:49:51 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:27 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_x(va_list arg, t_flags flags, char format)
{
	unsigned int	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 16, format);
	if (flags.sharp && format == 'x' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0x");
	else if (flags.sharp && format == 'X' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0X");
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_sharp_x(str, flags, format);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_sharp_x(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else if (flags.dot < 0 && tmp == 0)
		return (flags.n_chr);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int	format_x_h(va_list arg, t_flags flags, char format)
{
	unsigned short int	tmp;
	char				*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 16, format);
	if (flags.sharp && format == 'x' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0x");
	else if (flags.sharp && format == 'X' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0X");
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_sharp_x(str, flags, format);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_sharp_x(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int	format_x_hh(va_list arg, t_flags flags, char format)
{
	unsigned char	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 16, format);
	if (flags.sharp && format == 'x' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0x");
	else if (flags.sharp && format == 'X' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0X");
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_sharp_x(str, flags, format);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_sharp_x(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int	format_x_l(va_list arg, t_flags flags, char format)
{
	unsigned long	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned long);
	str = unsigned_itoa(tmp, 16, format);
	if (flags.sharp && format == 'x' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0x");
	else if (flags.sharp && format == 'X' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0X");
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_sharp_x(str, flags, format);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_sharp_x(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int	format_x_ll(va_list arg, t_flags flags, char format)
{
	unsigned long long	tmp;
	char				*str;

	tmp = va_arg(arg, unsigned long long);
	str = unsigned_itoa(tmp, 16, format);
	if (flags.sharp && format == 'x' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0x");
	else if (flags.sharp && format == 'X' && !flags.alignment && tmp != 0)
		flags.n_chr += ft_putstr_int("0X");
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_sharp_x(str, flags, format);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr = ft_zero_sharp_x(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}
