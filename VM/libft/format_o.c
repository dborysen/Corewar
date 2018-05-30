/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:49:49 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:44 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_o(va_list arg, t_flags flags)
{
	unsigned int	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 8, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr = ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str_sharp(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr = ft_dot_str(str, flags);
	else if (flags.dot < 0 && tmp == 0 && !flags.sharp)
		return (flags.n_chr);
	else if (flags.dot < 0 && tmp == 0 && flags.sharp)
		flags.n_chr += ft_putchar_int('0');
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int		format_o_h(va_list arg, t_flags flags)
{
	unsigned short int	tmp;
	char				*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 8, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str_sharp(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int		format_o_hh(va_list arg, t_flags flags)
{
	unsigned char	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned int);
	str = unsigned_itoa(tmp, 8, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str_sharp(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int		format_o_l(va_list arg, t_flags flags)
{
	unsigned long	tmp;
	char			*str;

	tmp = va_arg(arg, unsigned long);
	str = unsigned_itoa(tmp, 8, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str_sharp(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else if (flags.dot < 0 && tmp == 0 && !flags.sharp)
		return (flags.n_chr);
	else if (flags.dot < 0 && tmp == 0 && flags.sharp)
		flags.n_chr += ft_putchar_int('0');
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int		format_o_ll(va_list arg, t_flags flags)
{
	unsigned long long	tmp;
	char				*str;

	tmp = va_arg(arg, unsigned long long);
	str = unsigned_itoa(tmp, 8, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str_sharp(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}
