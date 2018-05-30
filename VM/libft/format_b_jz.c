/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_b_jz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:24:45 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:31 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_b_j(va_list arg, t_flags flags)
{
	uintmax_t	tmp;
	char		*str;

	tmp = va_arg(arg, uintmax_t);
	str = unsigned_itoa(tmp, 2, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}

int		format_b_z(va_list arg, t_flags flags)
{
	size_t	tmp;
	char	*str;

	tmp = va_arg(arg, size_t);
	str = unsigned_itoa(tmp, 2, 'o');
	if (flags.sharp > 0 && !flags.alignment && tmp != 0
		&& (flags.dot <= (int)ft_strlen(str)))
		flags.n_chr += ft_putchar_int('0');
	if (flags.alignment != 0)
		flags.n_chr += ft_aligment_str(str, flags);
	else if (flags.zero > 0 && flags.dot == 0)
		flags.n_chr += ft_zero_str(str, flags);
	else if (flags.dot > 0)
		flags.n_chr += ft_dot_str(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	free(str);
	return (flags.n_chr);
}
