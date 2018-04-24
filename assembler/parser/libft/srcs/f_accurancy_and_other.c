/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_accurancy_and_other.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:36:22 by klee              #+#    #+#             */
/*   Updated: 2018/01/23 12:36:24 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_one_equ(char *str1, char *str2)
{
	int		i;

	i = 0;
	if (!ft_strlen(str1))
		return (1);
	while (str1[i])
	{
		if (ft_strchr(str2, str1[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*f_strnew_null(int i)
{
	char	*s;
	int		n;

	n = 1;
	s = ft_strdup("0");
	while (n < i)
	{
		f_join_free(&s, "0");
		n++;
	}
	return (s);
}

char	*f_strnew_spc(int i)
{
	char	*s;
	int		n;

	n = 1;
	s = ft_strdup(" ");
	while (n < i)
	{
		f_join_free(&s, " ");
		n++;
	}
	return (s);
}

void	f_accurancy_dop_length(t_flgs *input, intmax_t *n, char **res)
{
	char			*tmp;

	tmp = *res;
	if ((*res[0] == '+' || *res[0] == '-') && input->accuracy)
	{
		n[1] = (*res[0] == '-') ? 1 : 3;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 1), *res + 1);
		free(tmp);
	}
	if (ft_strstr(*res, "0x") && input->accuracy)
	{
		n[1] = 2;
		*res = ft_strcpy(ft_strnew(ft_strlen(*res) - 2), *res + 2);
		n[0] = ft_strlen(*res) - input->accuracy;
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

void	f_accurancy_length(t_flgs *input, t_prf *new, char **res)
{
	intmax_t		n[2];
	char			*tmp;

	tmp = *res;
	n[0] = ft_strlen(*res) - input->accuracy;
	n[1] = 0;
	if (ft_strchr(new->size, 'z'))
		f_accurancy_dop_length(input, n, res);
	else
	{
		if (n[0] < 0)
		{
			*res = ft_strncpy(ft_strnew(input->accuracy),\
				*res, input->accuracy);
			free(tmp);
		}
	}
}
