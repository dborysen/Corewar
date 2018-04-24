/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:26:54 by klee              #+#    #+#             */
/*   Updated: 2018/04/20 13:36:45 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	f_type_s(char **res, va_list ap)
{
	char *s;

	s = va_arg(ap, char*);
	if (s != NULL)
		f_join_free(res, s);
	else
		f_join_free(res, "(null)");
}

void	f_type_c(char **res, va_list ap)
{
	char	c[2];

	c[1] = '\0';
	c[0] = (char)va_arg(ap, int);
	if (c[0] == 0)
		f_join_free(res, "\1");
	else
		f_join_free(res, c);
}

void	f_type_bc(char **res, va_list ap)
{
	char	c[2];
	int		i;

	c[1] = '\0';
	i = va_arg(ap, int);
	i = !i ? 1 : i;
	if (MB_CUR_MAX > 1)
		f_wchar_t(res, i);
	else
	{
		c[0] = (char)i;
		f_join_free(res, c);
	}
}

void	f_type_prcn(char **res, va_list ap)
{
	f_join_free(res, "%");
	if (ap && res)
		;
}

void	f_type_p(char **res, unsigned long long input)
{
	char			*str;

	str = f_itoa_base_a(input, 16);
	f_join_free(res, str);
	f_join_free_b(res, "0x");
	free(str);
}
