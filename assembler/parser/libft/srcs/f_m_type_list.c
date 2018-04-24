/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_m_type_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:59:11 by klee              #+#    #+#             */
/*   Updated: 2018/04/20 13:38:11 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char			*f_itoa_base_a(unsigned long long int n, int base)
{
	char			*c;
	char			add[2];
	uintmax_t		i;

	add[1] = '\0';
	i = n;
	c = ft_strdup("");
	recursio_i_a(&c, i, base);
	return (c);
}

char			*str_to_upper(char *in)
{
	int i;

	i = 0;
	while (in[i])
	{
		in[i] = ft_toupper(in[i]);
		i++;
	}
	return (in);
}

void			f_listadd_t(t_prf **src, t_prf *new)
{
	new->next = *src;
	*src = new;
}

t_prf			*type_list(void)
{
	t_prf *test_new;

	test_new = NULL;
	f_listadd_t(&test_new, f_listnew("p", "-.", "z", &f_type_p));
	f_listadd_t(&test_new, f_listnew("X", "-0#.", "hlzj", &f_type_bx));
	f_listadd_t(&test_new, f_listnew("x", "-0#.", "hlzj", &f_type_x));
	f_listadd_t(&test_new, f_listnew("o", "-0#.", "hlzj", &f_type_o));
	f_listadd_t(&test_new, f_listnew("O", "-0#.", "hlzj", &f_type_o));
	f_listadd_t(&test_new, f_listnew("%", "0", "", &f_type_prcn));
	f_listadd_t(&test_new, f_listnew("d", "-+0 .", "hlzj", &f_type_d));
	f_listadd_t(&test_new, f_listnew("D", "-+0 ", "hlzj", &f_type_bd));
	f_listadd_t(&test_new, f_listnew("u", "-0.", "hlzj", &f_type_u));
	f_listadd_t(&test_new, f_listnew("U", "-0", "hlzj", &f_type_u));
	f_listadd_t(&test_new, f_listnew("i", "-+0. ", "hlzj", &f_type_d));
	f_listadd_t(&test_new, f_listnew("s", "-0", "l", &f_type_s));
	f_listadd_t(&test_new, f_listnew("S", "-0", "", &f_type_bs));
	f_listadd_t(&test_new, f_listnew("c", "-0", "l", &f_type_c));
	f_listadd_t(&test_new, f_listnew("C", "-0", "", &f_type_bc));
	f_listadd_t(&test_new, f_listnew("r", "", "z", &f_type_nope));
	f_listadd_t(&test_new, f_listnew("b", "", "hlzj", &f_type_bb));
	return (test_new);
}

intmax_t		f_size_nbr(t_flgs *input, va_list ap)
{
	if (ft_one_equ(input->type, "UpOb"))
		return (va_arg(ap, unsigned long int));
	if (ft_strstr(input->size, "z"))
		return (va_arg(ap, size_t));
	if (ft_strstr(input->size, "j"))
		return (va_arg(ap, intmax_t));
	if (ft_strstr(input->size, "ll"))
		return (va_arg(ap, long long));
	if (ft_strstr(input->size, "l"))
		return (va_arg(ap, long));
	if (ft_strstr(input->size, "h") && !ft_strstr(input->size, "hh"))
		return (ft_one_equ(input->type, "uoxXD")) ? \
		((unsigned short int)va_arg(ap, int)) : ((short int)va_arg(ap, int));
	if (ft_strstr(input->size, "hh") && ft_strstr(input->type, "D"))
		return ((unsigned short)va_arg(ap, int));
	if (ft_strstr(input->size, "hh"))
		return (ft_one_equ(input->type, "uoxXD")) ? \
		((unsigned char)va_arg(ap, int)) : ((signed char)va_arg(ap, int));
	if ((input->type[0] == 'd') || (input->type[0] == 'i'))
		return (va_arg(ap, int));
	if (input->type[0] == 'D')
		return (va_arg(ap, long int));
	else
		return (va_arg(ap, unsigned int));
}
