/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_support.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:51:03 by klee              #+#    #+#             */
/*   Updated: 2018/01/23 11:51:05 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	f_join_free(char **str, char *src)
{
	char	*s;

	s = *str;
	*str = ft_strjoin(*str, src);
	free(s);
}

void	f_join_free_b(char **str, char *src)
{
	char	*s;

	s = *str;
	*str = ft_strjoin(src, *str);
	free(s);
}

void	f_wchar_t_2048(char **res, intmax_t n)
{
	char	c[2];

	c[1] = '\0';
	if (n >= 2048 && n < 65536)
	{
		c[0] = (n >> 12) | 224;
		f_join_free(res, c);
		c[0] = (n >> 6 ^ ((n >> 12) << 6)) | 128;
		f_join_free(res, c);
		c[0] = (n ^ ((n >> 6) << 6)) | 128;
		f_join_free(res, c);
	}
	else if (n > 65536)
	{
		c[0] = (n >> 18) | 240;
		f_join_free(res, c);
		c[0] = (n >> 12 ^ ((n >> 18) << 12)) | 128;
		f_join_free(res, c);
		c[0] = (n >> 6 ^ ((n >> 12) << 6)) | 128;
		f_join_free(res, c);
		c[0] = (n ^ ((n >> 6) << 6)) | 128;
		f_join_free(res, c);
	}
}

void	f_wchar_t(char **res, intmax_t n)
{
	char	c[2];

	c[1] = '\0';
	if (n < 128)
	{
		c[0] = n;
		f_join_free(res, c);
	}
	else if (n >= 128 && n < 2048)
	{
		c[0] = (n >> 6) | 192;
		f_join_free(res, c);
		c[0] = (n ^ ((n >> 6) << 6)) | 128;
		f_join_free(res, c);
	}
	else if (n >= 2048)
	{
		f_wchar_t_2048(res, n);
	}
}

void	recursio_i_a(char **str, unsigned long long i, int base)
{
	char			*f_base;
	char			c[2];

	c[1] = 0;
	c[0] = 0;
	f_base = "0123456789abcdef";
	if (i / base > 0)
		recursio_i_a(str, i / base, base);
	c[0] = f_base[(i - (i / base * base))];
	f_join_free(str, c);
}
