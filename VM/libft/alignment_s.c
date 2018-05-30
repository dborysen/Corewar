/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:52:37 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:39 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_space_w(int *alignment, int len, t_flags flags, wchar_t *str)
{
	int d;

	d = flags.dot;
	while ((d - ft_wcharlen(*str, 65553)) >= 0)
	{
		d -= ft_wcharlen(*str, 65553);
		len += ft_wcharlen(*str, 65553);
	}
	if (*alignment > 0)
	{
		while ((*alignment - len) > 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			*alignment -= 1;
		}
	}
	else if (*alignment < 0)
	{
		while ((*alignment + len) < 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			*alignment += 1;
		}
	}
	return (flags.n_chr);
}

int		ft_aligment_s(char *str, t_flags flags)
{
	int len;
	int i;

	i = 0;
	if ((flags.dot - (int)ft_strlen(str)) <= 0)
		len = flags.dot;
	else
		len = (int)ft_strlen(str);
	if (flags.alignment != 0 && flags.dot >= 0)
	{
		if (flags.alignment > 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
		if (flags.dot)
			while (*str && i < flags.dot)
			{
				flags.n_chr += ft_putchar_int(*str);
				i++;
				str++;
			}
		if (flags.alignment < 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	else
		flags.n_chr = print_space(&flags.alignment, 0, flags);
	return (flags.n_chr);
}

int		ft_aligment_s_wchar(wchar_t *str, t_flags flags)
{
	int len;

	len = 0;
	if (flags.alignment != 0 && flags.dot >= 0)
	{
		if (flags.alignment > 0)
			flags.n_chr = print_space_w(&flags.alignment, len, flags, str);
		if (flags.dot)
			while (*str && (flags.dot - ft_wcharlen(*str, 65553)) >= 0)
			{
				flags.n_chr += ft_print_wchar(*str, flags);
				flags.dot -= ft_wcharlen(*str, 65553);
				str++;
			}
		if (flags.alignment < 0)
			flags.n_chr = print_space_w(&flags.alignment, len, flags, str);
	}
	else
		flags.n_chr = print_space_w(&flags.alignment, len, flags, str);
	return (flags.n_chr);
}
