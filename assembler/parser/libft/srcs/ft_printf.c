/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:29:40 by klee              #+#    #+#             */
/*   Updated: 2018/01/02 14:29:43 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	change_char(char **s)
{
	char *str;

	str = *s;
	while (*str)
	{
		if (*str == '\1')
			*str = '\0';
		str++;
	}
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		d;
	char	*s;

	if (!ft_strlen(format) || format == NULL)
		return (0);
	va_start(ap, format);
	s = f_srch(format, ap);
	va_end(ap);
	d = ft_strlen(s);
	change_char(&s);
	write(1, s, d);
	free(s);
	return (d);
}
