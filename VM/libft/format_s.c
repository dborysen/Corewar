/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:57:42 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:38 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pr_null(char *str, t_flags flags)
{
	int i;

	i = 0;
	str = "(null)";
	if (flags.alignment != 0 && !flags.dot)
		flags.n_chr = ft_aligment_str(str, flags);
	else if (flags.dot > 0 && !flags.alignment)
	{
		while (str[i] && i < flags.dot)
			flags.n_chr += ft_putchar_int(str[i++]);
	}
	else if (flags.alignment && flags.dot)
		flags.n_chr = ft_aligment_s(str, flags);
	else
		flags.n_chr = ft_putstr_int(str);
	return (flags.n_chr);
}

int		format_s(va_list arg, t_flags flags)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(arg, char*);
	if (str || flags.zero)
	{
		if (flags.alignment != 0 && !flags.dot)
			flags.n_chr = ft_aligment_str(str, flags);
		else if (flags.dot > 0 && !flags.alignment)
			while (str[i] && i < flags.dot)
				flags.n_chr += ft_putchar_int(str[i++]);
		else if (flags.alignment && flags.dot)
			flags.n_chr = ft_aligment_s(str, flags);
		else if (flags.zero > 0)
			flags.n_chr = ft_zero_str(str, flags);
		else if (flags.dot < 0)
			return (flags.n_chr);
		else
			flags.n_chr = ft_putstr_int(str);
	}
	else
		flags.n_chr = pr_null(str, flags);
	return (flags.n_chr);
}

int		format_s_l(va_list arg, t_flags flags)
{
	wchar_t	*str;

	str = va_arg(arg, wchar_t*);
	if (str || flags.zero)
		if (flags.alignment != 0 && !flags.dot)
			flags.n_chr = ft_aligment_wchar(str, flags);
		else if (flags.dot > 0 && !flags.alignment)
			while (*str && (flags.dot - ft_wcharlen(*str, 65553)) >= 0)
			{
				flags.dot -= ft_wcharlen(*str, 65553);
				flags.n_chr += ft_print_wchar(*str, flags);
				str++;
			}
		else if (flags.alignment && flags.dot)
			flags.n_chr = ft_aligment_s_wchar(str, flags);
		else if (flags.zero > 0)
			flags.n_chr = ft_zero_strwchar(str, flags);
		else if (flags.dot < 0)
			return (flags.n_chr);
		else
			flags.n_chr = ft_str_printw(str, flags);
	else
		flags.n_chr = pr_null((char *)str, flags);
	return (flags.n_chr);
}
