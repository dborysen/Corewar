/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:45:43 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:14 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format_digit(const char ***format, t_flags **flags,
						va_list arg, int tmp)
{
	char	s[100];
	int		i;
	t_flags *temp;

	temp = *flags;
	i = 0;
	while (ft_isdigit(***format))
	{
		s[i] = ***format;
		**format += 1;
		i++;
	}
	s[i] = '\0';
	temp->alignment = ft_atoi(s);
	if (***format == '*')
	{
		tmp = va_arg(arg, int);
		temp->alignment = tmp;
		**format += 1;
	}
	if (temp->minus)
		temp->alignment = temp->alignment * -1;
}

void	find_dig(const char ***format, char *s)
{
	int i;

	i = 0;
	while (ft_isdigit(***format))
	{
		s[i++] = ***format;
		**format += 1;
	}
	s[i] = '\0';
}

void	ft_format_dot(const char ***format, t_flags **flags,
						va_list arg, int tmp)
{
	char	s[100];
	int		sign;
	t_flags *temp;

	temp = *flags;
	sign = 0;
	**format += 1;
	if (***format == '-')
	{
		sign = 1;
		**format += 1;
	}
	find_dig(format, s);
	temp->dot = ft_atoi(s);
	if (***format == '*')
	{
		tmp = va_arg(arg, int);
		temp->dot = tmp;
		**format += 1;
	}
	if (temp->dot == 0)
		temp->dot = -1;
	if (sign == 1 || tmp < 0)
		temp->dot = 0;
}

void	f_plus_zero(const char ***format, t_flags *temp,
					va_list arg, int tmp)
{
	char	s[100];
	int		i;

	i = 0;
	if (temp->plus)
		temp->space = 0;
	if (temp->zero && !temp->minus)
	{
		while (***format == '0')
			**format += 1;
		while (ft_isdigit(***format))
		{
			s[i++] = ***format;
			**format += 1;
		}
		s[i] = '\0';
		temp->zero = ft_atoi(s);
		if (***format == '*')
		{
			tmp = va_arg(arg, int);
			temp->zero = tmp;
			**format += 1;
		}
	}
}

void	ft_format_pssmz(const char ***format, t_flags **flags,
						va_list arg, int tmp)
{
	t_flags	*temp;

	temp = *flags;
	while (***format == '+' || ***format == ' ' || ***format == '*' ||
			***format == '#' || ***format == '-' || ***format == '0')
	{
		if (***format == '+')
			temp->plus += 1;
		else if (***format == ' ')
			temp->space += 1;
		else if (***format == '-')
			temp->minus += 1;
		else if (***format == '#')
			temp->sharp += 1;
		else if (***format == '0')
			temp->zero += 1;
		else if (***format == '*')
			tmp = va_arg(arg, int);
		**format += 1;
	}
	if (tmp && !temp->zero && temp->minus)
		temp->alignment = -tmp;
	else
		temp->alignment = tmp;
	f_plus_zero(format, temp, arg, tmp);
}
