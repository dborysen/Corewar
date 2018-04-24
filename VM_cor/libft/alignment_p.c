/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:12:25 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:42 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_aligment_pm(void *v_tmp, t_flags flags, int len)
{
	flags.n_chr += ft_print_address(v_tmp, flags);
	while ((flags.alignment + len) < 0)
	{
		flags.n_chr += ft_putchar_int(' ');
		flags.alignment += 1;
	}
	return (flags.n_chr);
}

int		ft_aligment_p(void *v_tmp, t_flags flags)
{
	int len;

	if (flags.dot - ft_intlen_u((unsigned long)v_tmp) < 0)
		len = ft_intlen_u((unsigned long)v_tmp) + 2;
	else
		len = ft_intlen_u((unsigned long)v_tmp) +
			(flags.dot - ft_intlen_u((unsigned long)v_tmp)) + 2;
	if (flags.alignment > 0)
	{
		while ((flags.alignment - len) > 0)
		{
			flags.n_chr += ft_putchar_int(' ');
			flags.alignment -= 1;
		}
		flags.n_chr += ft_print_address(v_tmp, flags);
	}
	else if (flags.alignment < 0)
		flags.n_chr = ft_aligment_pm(v_tmp, flags, len);
	return (flags.n_chr);
}
