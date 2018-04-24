/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_precision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:31:24 by klee              #+#    #+#             */
/*   Updated: 2018/02/05 15:31:26 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	if_type_z(t_flgs *input, t_prf *new, char **res, intmax_t *n)
{
	char			*tmp;
	int				i;

	tmp = *res;
	i = input->accuracy;
	i = ((i / 3) && ft_strchr(input->type, 'S')) ? ((i / 3) * 3) : i;
	if (ft_strchr(new->size, 'z'))
		f_accurancy_dop(input, n, res);
	else
	{
		if (input->accuracy)
		{
			*res = ft_strncpy(ft_strnew(i),\
			*res, i);
			free(tmp);
		}
		else if (ft_one_equ(input->type, "sS") && ft_strchr(input->flags, '.'))
		{
			*res = ft_strdup("");
			free(tmp);
		}
	}
}

void	f_binar(char **res, unsigned long long input)
{
	if (input != 1)
		f_binar(res, input / 2);
	c_jf(res, (((input - (input / 2) * 2)) + '0'));
}
