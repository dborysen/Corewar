/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:43:32 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:44 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_str_printw(wchar_t *str, t_flags flags)
{
	int i;

	i = 0;
	while (str[i])
	{
		flags.n_chr += ft_print_wchar(str[i], flags);
		i++;
	}
	return (flags.n_chr);
}

int		ft_print_wchar_con(int w_c, t_flags flags)
{
	if (w_c < (1 << 21))
	{
		flags.n_chr = ft_putchar_int((w_c >> 18) | 0xF0);
		flags.n_chr += ft_putchar_int(((w_c >> 12) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 6) & 63) | 0x80);
		flags.n_chr += ft_putchar_int((w_c & 63) | 0x80);
	}
	else if (w_c < (1 << 26))
	{
		flags.n_chr = ft_putchar_int((w_c >> 24) | 0xF8);
		flags.n_chr += ft_putchar_int(((w_c >> 18) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 12) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 6) & 63) | 0x80);
		flags.n_chr += ft_putchar_int((w_c & 63) | 0x80);
	}
	else
	{
		flags.n_chr = ft_putchar_int((w_c >> 30) | 0xFC);
		flags.n_chr += ft_putchar_int(((w_c >> 24) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 18) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 12) & 63) | 0x80);
		flags.n_chr += ft_putchar_int(((w_c >> 6) & 63) | 0x80);
		flags.n_chr += ft_putchar_int((w_c & 63) | 0x80);
	}
	return (flags.n_chr);
}

int		ft_print_wchar(wchar_t c, t_flags flags)
{
	int w_c;

	w_c = (int)c;
	if (w_c < 128)
		flags.n_chr = ft_putchar_int(w_c);
	else if (w_c < 2048)
	{
		flags.n_chr = ft_putchar_int((w_c >> 6) | 0xC0);
		flags.n_chr += ft_putchar_int((w_c & 63) | 0x80);
	}
	else if (w_c < (1 << 16))
	{
		flags.n_chr = ft_putchar_int((w_c >> 12) | 0xE0);
		flags.n_chr += ft_putchar_int(((w_c >> 6) & 63) | 0x80);
		flags.n_chr += ft_putchar_int((w_c & 63) | 0x80);
	}
	else
		flags.n_chr = ft_print_wchar_con(w_c, flags);
	return (flags.n_chr);
}
