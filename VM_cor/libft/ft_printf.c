/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:50:02 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/16 17:38:22 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_flags	flags;
	int		ret;

	ret = 0;
	va_start(arg, format);
	zero_flags(&flags);
	if (!format)
		return (0);
	return (format_prints(format, arg, flags, ret));
}

int	check_format(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	else if (c == 'o' || c == 'O')
		return (1);
	else if (c == 'b' || c == 'B')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else if (c == 'u' || c == 'U')
		return (1);
	else if (c == 's' || c == 'S')
		return (1);
	else if (c == 'c' || c == 'C')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}

int	invalid_spec(char format, t_flags flags)
{
	if (flags.alignment != 0)
		flags.n_chr = ft_alignment_c(format, flags);
	if (flags.zero != 0)
	{
		while ((flags.zero - 1) > 0)
		{
			flags.n_chr += ft_putchar_int('0');
			flags.zero -= 1;
		}
		flags.n_chr += ft_putchar_int(format);
	}
	return (flags.n_chr);
}

int	format_prints(const char *format, va_list arg, t_flags flags, int ret)
{
	while (*format)
	{
		zero_flags(&flags);
		if (*format == '%')
		{
			format++;
			find_flags(&format, &flags, arg);
			if (check_format(*format))
			{
				ret += parse_con(format, arg, flags);
				format++;
			}
			else if (flags.alignment != 0 || flags.zero != 0)
			{
				ret += invalid_spec(*format, flags);
				format++;
			}
		}
		else
		{
			ret += ft_putchar_int(*format);
			format++;
		}
	}
	return (ret);
}
