/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_srch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 09:51:23 by klee              #+#    #+#             */
/*   Updated: 2018/01/03 09:51:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		f_len_nbr(int nbr)
{
	intmax_t i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	c_jf(char **str, char in)
{
	char	c[2];

	c[1] = '\0';
	c[0] = in;
	f_join_free(str, c);
}

int		f_a_l_s(char *tmp, t_flgs **fnt)
{
	int		i;

	i = 0;
	if (ft_strchr("-+ #", tmp[i]))
		c_jf(&(*fnt)->flags, tmp[i++]);
	else if (tmp[i] == '0')
		c_jf(&(*fnt)->flags, tmp[i++]);
	else if (tmp[i] == '.')
	{
		c_jf(&(*fnt)->flags, '.');
		(tmp[i + 1] == '0') ? i++ : 1 - 1;
		(*fnt)->accuracy = ft_atoi(tmp + i + 1);
		i = i + f_len_nbr((*fnt)->accuracy) + 1;
	}
	else if (ft_strchr("123456789", tmp[i]))
	{
		(*fnt)->length = ft_atoi(tmp + i);
		i = i + f_len_nbr((*fnt)->length);
	}
	else if (ft_strchr("zjlh", tmp[i]))
		c_jf(&(*fnt)->size, tmp[i++]);
	return (i);
}

t_flgs	*analys_str(char **str, char **res)
{
	t_flgs	*fnt;
	char	*tmp;

	fnt = flag_list();
	tmp = *str;
	while (*tmp)
	{
		if (ft_strchr("-+ #0.123456789zjlh", tmp[0]))
			tmp += f_a_l_s(tmp, &fnt);
		if (ft_strchr("sSpdDioOuUxXcCb%", tmp[0]))
		{
			c_jf(&(fnt)->type, tmp[0]);
			tmp++;
			break ;
		}
		if (!ft_strchr("+- #.0123456789zjlhSspDdiOoUuXxCc", tmp[0]))
		{
			c_jf(res, tmp[0]);
			c_jf(&(fnt)->type, 'r');
			tmp++;
			break ;
		}
	}
	*str = tmp;
	return (fnt);
}

char	*f_srch(char *str, va_list ap)
{
	char	*res;
	char	*just_words;
	t_flgs	*input;

	just_words = ft_strdup("");
	while (*str)
	{
		res = ft_strdup("");
		if (*str == '%')
		{
			str++;
			input = analys_str(&str, &res);
			find_func(input, &res, ap);
			del_flag_list(&input);
			f_join_free(&just_words, res);
		}
		while (str[0] != '%' && *str)
		{
			c_jf(&just_words, str[0]);
			str++;
		}
		free(res);
	}
	return (just_words);
}
