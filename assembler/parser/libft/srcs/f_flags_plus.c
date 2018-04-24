/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flags_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:37:20 by klee              #+#    #+#             */
/*   Updated: 2018/01/29 14:37:22 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	f_flag_plus(t_flgs *input, t_prf *new, char **res)
{
	if (ft_strchr(input->flags, '+') && ft_strchr(new->flags, '+'))
		if (*res[0] != '-')
			f_join_free_b(res, "+");
}

void	f_flag_sps(t_flgs *input, t_prf *new, char **res)
{
	if (ft_strchr(input->flags, ' ') && ft_strchr(new->flags, ' '))
		if (!ft_strchr("-+ ", *res[0]))
		{
			if (ft_strchr(input->flags, '0') && ft_strchr(input->type, 'd'))
			{
				if (ft_strlen(*res) > 1 && *res[0] == '0')
					*res[0] = ' ';
			}
			else
				f_join_free_b(res, " ");
		}
}

void	f_accurancy_dop(t_flgs *input, intmax_t *n, char **res)
{
	char			*tmp;

	tmp = *res;
	if ((*res[0] == '+' || *res[0] == '-') && input->accuracy)
	{
		n[1] = (*res[0] == '-') ? 1 : 3;
		n[0] = ft_strlen(*res) - input->accuracy - 1;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 1), *res + 1);
		free(tmp);
	}
	if (*res[0] == '0' && input->accuracy && ft_strlen(*res) > 1)
	{
		n[1] = 2;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 2), *res + 2);
		free(tmp);
	}
	if (n[0] < 0)
	{
		tmp = f_strnew_null(-n[0]);
		f_join_free_b(res, tmp);
		free(tmp);
	}
	(n[1] == 1) ? f_join_free_b(res, "-") : 1 - 1;
	(n[1] == 2) ? f_join_free_b(res, "0x") : 1 - 1;
	(n[1] == 3) ? f_join_free_b(res, "+") : 1 - 1;
}

void	f_accurancy(t_flgs *input, t_prf *new, char **res)
{
	intmax_t		n[2];

	n[0] = ft_strlen(*res) - input->accuracy;
	n[1] = 0;
	if (ft_strchr(input->flags, '.') && ft_strlen(*res) == 1 && *res[0] == '0'
		&& input->accuracy == 0 && ft_strchr(new->flags, '.'))
	{
		if ((ft_one_equ(input->type, "oO") && ft_strchr(input->flags, '#')))
			*res[0] = '0';
		else
			*res[0] = '\0';
		return ;
	}
	if_type_z(input, new, res, n);
}

void	f_type_sc(t_flgs *input, t_prf *new, char **res, va_list ap)
{
	if (ft_strchr(new->type, 'c'))
	{
		if (ft_strchr(input->size, 'l'))
			f_type_bc(res, ap);
		else
			f_type_c(res, ap);
	}
	else if (ft_strchr(new->type, 's'))
	{
		if (ft_strchr(input->size, 'l'))
			f_type_bs(res, ap);
		else
			f_type_s(res, ap);
	}
	else
		new->f(res, ap);
}
