/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:47:16 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:19 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_aligment_dim(char *str, t_flags flags, int len)
{
	if (flags.plus && !flags.dot)
		flags.n_chr += ft_putchar_int('+');
	if (flags.dot)
		flags.n_chr += dot_di(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	while ((flags.alignment + len) < 0)
	{
		flags.n_chr += ft_putchar_int(' ');
		flags.alignment += 1;
	}
	return (flags.n_chr);
}

int		ft_aligment_diplus(char *str, t_flags flags, int len)
{
	while ((flags.alignment - len) > 0)
	{
		flags.n_chr += ft_putchar_int(' ');
		flags.alignment -= 1;
	}
	if (flags.plus && !flags.dot)
		flags.n_chr += ft_putchar_int('+');
	if (flags.dot)
		flags.n_chr = dot_di(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}

int		ft_aligment_dip(char *str, t_flags flags)
{
	int len;

	len = 0;
	if (str[0] == '-' && (flags.dot - (int)ft_strlen(str)) > 0)
		len += 1;
	if ((flags.dot - (int)ft_strlen(str)) < 0)
		len += (int)ft_strlen(str) + flags.plus + flags.space;
	else
		len += ((int)ft_strlen(str) + flags.plus +
				flags.space + (flags.dot - (int)ft_strlen(str)));
	if (flags.alignment > 0 && flags.dot >= 0)
		flags.n_chr = ft_aligment_diplus(str, flags, len);
	else if (flags.alignment < 0 && flags.dot >= 0)
		flags.n_chr = ft_aligment_dim(str, flags, len);
	else
		flags.n_chr = print_space(&flags.alignment, 0, flags);
	return (flags.n_chr);
}

int		ft_aligment_diz(char *str, t_flags flags)
{
	int len;

	len = 0;
	if (str[0] == '-')
		len--;
	if ((flags.dot - (int)ft_strlen(str)) < 0)
		len += (int)ft_strlen(str) - flags.plus -
				flags.space - (flags.zero + flags.dot);
	else
		len += flags.zero - ((int)ft_strlen(str) +
				(flags.dot - (int)ft_strlen(str))) - flags.plus - flags.space;
	while (len > 0)
	{
		flags.n_chr += ft_putchar_int(' ');
		len--;
	}
	if (flags.dot)
		flags.n_chr = dot_di(str, flags);
	else
		flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}
