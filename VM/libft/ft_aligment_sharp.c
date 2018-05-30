/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligment_sharp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:46:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:24 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_zero_sharp_x(char *str, t_flags flags)
{
	if (flags.sharp)
		flags.sharp = 2;
	while ((flags.zero - (int)ft_strlen(str) - flags.sharp) > 0)
	{
		flags.n_chr += ft_putchar_int('0');
		flags.zero -= 1;
	}
	flags.n_chr += ft_putstr_int(str);
	return (flags.n_chr);
}

int		if_aligment_sharp_x(char *str, t_flags flags, int len, char format)
{
	if (flags.alignment != 0 && flags.dot >= 0)
	{
		if (flags.alignment > 0)
			flags.n_chr += print_space(&flags.alignment, len, flags);
		if (flags.sharp && format == 'X' && str[0] != '0')
			flags.n_chr += ft_putstr_int("0X");
		else if (flags.sharp && format == 'x' && str[0] != '0')
			flags.n_chr += ft_putstr_int("0x");
		if (flags.dot)
			flags.n_chr = ft_dot_str(str, flags);
		else
			flags.n_chr += ft_putstr_int(str);
		if (flags.alignment < 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	else
		flags.n_chr = print_space(&flags.alignment, 0, flags);
	return (flags.n_chr);
}

int		ft_aligment_sharp_x(char *str, t_flags flags, char format)
{
	int len;

	len = 0;
	if (flags.sharp)
		flags.sharp = 2;
	if (str[0] == '0' && str[1] == '\0')
		len -= 2;
	if ((flags.dot - (int)ft_strlen(str)) < 0)
		len += (int)ft_strlen(str) + flags.sharp;
	else
		len += ((int)ft_strlen(str) +
			(flags.dot - (int)ft_strlen(str)) + flags.sharp);
	if (flags.alignment != 0)
		flags.n_chr = if_aligment_sharp_x(str, flags, len, format);
	return (flags.n_chr);
}

int		ft_aligment_str_sharp(char *str, t_flags flags)
{
	int len;

	if ((flags.dot - (int)ft_strlen(str)) < 0)
		len = (int)ft_strlen(str) + flags.sharp;
	else
		len = ((int)ft_strlen(str) +
				(flags.dot - (int)ft_strlen(str)));
	if (flags.alignment != 0 && flags.dot >= 0)
	{
		if (flags.alignment > 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
		if (flags.sharp && (flags.dot - (int)ft_strlen(str)) <= 0)
			flags.n_chr += ft_putchar_int('0');
		if (flags.dot)
			flags.n_chr = ft_dot_str(str, flags);
		else
			flags.n_chr += ft_putstr_int(str);
		if (flags.alignment < 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	else
		flags.n_chr = print_space(&flags.alignment, 0, flags);
	return (flags.n_chr);
}
