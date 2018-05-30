/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:47:34 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:36 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_flags(const char **format, t_flags *flags, va_list arg)
{
	int		tmp;

	tmp = 0;
	if (**format == '+' || **format == ' ' ||
		(**format == '*' && ft_isdigit(*(*format + 1))) ||
		**format == '#' || **format == '-' || **format == '0')
		ft_format_pssmz(&format, &flags, arg, tmp);
	if (ft_isdigit(**format) || **format == '*')
		ft_format_digit(&format, &flags, arg, tmp);
	if (**format == '.')
		ft_format_dot(&format, &flags, arg, tmp);
	if (**format == 'h' || **format == 'l' ||
		**format == 'j' || **format == 'z')
		flag_hljz(&format, &flags);
}

int		parse_con(const char *format, va_list arg, t_flags flags)
{
	if (*format == 'd' || *format == 'i' || *format == 'D')
		flags.n_chr = af_per_d(arg, flags, format);
	else if (*format == 'o' || *format == 'O')
		flags.n_chr = af_per_o(arg, flags, format);
	else if (*format == 'b' || *format == 'B')
		flags.n_chr = af_per_b(arg, flags, format);
	else if (*format == 'x' || *format == 'X')
		flags.n_chr = af_per_x(arg, flags, format);
	else if (*format == 'u' || *format == 'U')
		flags.n_chr = af_per_u(arg, flags, format);
	else if (*format == 's' || *format == 'S')
		flags.n_chr = af_per_s(arg, flags, format);
	else if (*format == 'c' || *format == 'C')
		flags.n_chr = af_per_c(arg, flags, format);
	else if (*format == 'p')
		flags.n_chr = format_p(arg, flags);
	else if (*format == '%')
		flags.n_chr = format_per(flags);
	return (flags.n_chr);
}
