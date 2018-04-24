/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_jz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:38:58 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:30 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_x_j(va_list arg, t_flags flags, char format)
{
	uintmax_t	tmp;
	char		*str;

	tmp = va_arg(arg, uintmax_t);
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

int		format_x_z(va_list arg, t_flags flags, char format)
{
	size_t	tmp;
	char	*str;

	tmp = va_arg(arg, size_t);
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
