/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:27:06 by klee              #+#    #+#             */
/*   Updated: 2018/01/19 17:27:08 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	f_type_d(char **res, intmax_t input)
{
	char	*s;

	s = ft_itoa(input);
	f_join_free(res, s);
	free(s);
}

void	f_type_bx(char **res, intmax_t input)
{
	char			*str;

	str = str_to_upper(f_itoa_base_a(input, 16));
	f_join_free(res, str);
	free(str);
}

void	f_type_o(char **res, intmax_t input)
{
	char	*str;

	str = f_itoa_base_a(input, 8);
	f_join_free(res, str);
	free(str);
}

void	f_type_x(char **res, intmax_t input)
{
	char			*str;

	str = f_itoa_base_a(input, 16);
	f_join_free(res, str);
	free(str);
}

void	f_type_u(char **res, unsigned long long input)
{
	char *str;

	str = ft_itoa_u(input);
	f_join_free(res, str);
	free(str);
}
