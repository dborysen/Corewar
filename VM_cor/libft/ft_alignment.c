/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:36:11 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:16 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_space(int *alignment, int len, t_flags flags)
{
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

int		ft_aligment_str(char *str, t_flags flags)
{
	int len;

	if ((flags.dot - (int)ft_strlen(str)) < 0)
		len = (int)ft_strlen(str);
	else
		len = ((int)ft_strlen(str) + (flags.dot - (int)ft_strlen(str)));
	if (flags.alignment != 0)
	{
		if (flags.alignment > 0)
			flags.n_chr += print_space(&flags.alignment, len, flags);
		if (flags.dot)
			flags.n_chr += ft_dot_str(str, flags);
		else
			flags.n_chr += ft_putstr_int(str);
		if (flags.alignment < 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	return (flags.n_chr);
}

int		ft_aligment_u(unsigned long long u_tmp, t_flags flags)
{
	int len;

	if ((flags.dot - ft_intlen_u(u_tmp)) < 0)
		len = ft_intlen_u(u_tmp);
	else
		len = ft_intlen_u(u_tmp) + (flags.dot - ft_intlen_u(u_tmp));
	if (flags.alignment != 0)
	{
		if (flags.alignment > 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
		if (flags.dot)
			flags.n_chr = ft_dot_u(u_tmp, flags);
		else
		{
			ft_putnbr_u(u_tmp);
			flags.n_chr += ft_intlen_u(u_tmp);
		}
		if (flags.alignment < 0)
			flags.n_chr = print_space(&flags.alignment, len, flags);
	}
	return (flags.n_chr);
}

int		ft_alignment_c(char tmp, t_flags flags)
{
	if (flags.alignment > 0)
	{
		while ((flags.alignment - 1) > 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			flags.alignment -= 1;
		}
		flags.n_chr += ft_putchar_int(tmp);
	}
	else if (flags.alignment < 0)
	{
		flags.n_chr += ft_putchar_int(tmp);
		while ((flags.alignment + 1) < 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			flags.alignment += 1;
		}
	}
	return (flags.n_chr);
}
