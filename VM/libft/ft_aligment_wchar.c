/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligment_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:45:45 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:21 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *ws, int max)
{
	int	i;
	int	len;

	if (!ws)
		return (-1);
	i = 0;
	len = 0;
	if (max == -1)
		max = 2147483647;
	while (ws[i])
	{
		if (len + 1 <= max && ws[i] <= 0x7F)
			len += 1;
		else if (len + 2 <= max && ws[i] <= 0x7FF)
			len += 2;
		else if (len + 3 <= max && ws[i] <= 0xFFFF)
			len += 3;
		else if (len + 4 <= max)
			len += 4;
		i++;
	}
	return (len);
}

int		ft_zero_strwchar(wchar_t *str, t_flags flags)
{
	while (((flags.zero - ft_wstrlen(str, 65535)) > 0) && flags.dot >= 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	if (flags.dot >= 0)
		flags.n_chr = ft_str_printw(str, flags);
	else
	{
		while (flags.zero)
		{
			flags.n_chr += ft_putchar_int('0');
			flags.zero -= 1;
		}
	}
	return (flags.n_chr);
}

int		ft_wcharlen(wchar_t ws, int max)
{
	int	len;

	len = 0;
	if (max == -1)
		max = 2147483647;
	if (len + 1 <= max && ws <= 0x7F)
		len += 1;
	else if (len + 2 <= max && ws <= 0x7FF)
		len += 2;
	else if (len + 3 <= max && ws <= 0xFFFF)
		len += 3;
	else if (len + 4 <= max)
		len += 4;
	return (len);
}

int		ft_dot_wchar(wchar_t *str, t_flags flags)
{
	while ((flags.dot - (int)ft_wstrlen(str, 65535)) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.dot -= 1;
	}
	flags.n_chr += ft_str_printw(str, flags);
	return (flags.n_chr);
}

int		ft_aligment_wchar(wchar_t *str, t_flags flags)
{
	int len;

	if ((flags.dot - (int)ft_wstrlen(str, 65535)) < 0)
		len = (int)ft_wstrlen(str, 65535);
	else
		len = ((int)ft_wstrlen(str, 65535) +
				(flags.dot - (int)ft_wstrlen(str, 65535)));
	if (flags.alignment > 0)
	{
		flags.n_chr = print_space(&flags.alignment, len, flags);
		if (flags.dot)
			flags.n_chr += ft_dot_wchar(str, flags);
		else
			flags.n_chr = ft_str_printw(str, flags);
	}
	else if (flags.alignment < 0)
	{
		if (flags.dot)
			flags.n_chr += ft_dot_wchar(str, flags);
		else
			flags.n_chr += ft_str_printw(str, flags);
		flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	return (flags.n_chr);
}
