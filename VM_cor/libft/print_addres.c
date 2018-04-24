/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:19:59 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:51 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_zero_p(unsigned long nbr, t_flags flags, int len)
{
	int i;

	i = 0;
	if (nbr == 0)
		flags.zero -= 1;
	while ((flags.zero - len - 2) > 0)
	{
		i += ft_putchar_int('0');
		flags.zero -= 1;
	}
	return (i);
}

int		ft_zero_dot_p(unsigned long nbr, t_flags flags, char *arr)
{
	int count;
	int len;

	count = 0;
	if (nbr == 0)
	{
		count = 3;
		len = 0;
	}
	else
		len = (int)ft_strlen(arr);
	if (flags.dot)
	{
		if (nbr == 0)
			flags.dot -= 1;
		while ((flags.dot - len) > 0)
		{
			count += ft_putchar_int('0');
			flags.dot -= 1;
		}
	}
	else if (flags.zero)
		count += ft_zero_p(nbr, flags, len);
	return (count);
}

int		do_address(unsigned long nbr, char *arr)
{
	unsigned long	divisor;
	int				result;
	int				count;
	int				i;
	char			*hex;

	i = 0;
	count = 2;
	divisor = 1;
	while ((nbr / divisor) >= 16)
		divisor = divisor * 16;
	hex = "0123456789abcdef";
	while (divisor > 0)
	{
		result = (nbr / divisor) % 16;
		arr[i++] = hex[result];
		count++;
		divisor = divisor / 16;
	}
	arr[i] = '\0';
	return (count);
}

int		ft_print_address(void *address, t_flags flags)
{
	unsigned long	nbr;
	int				count;
	char			arr[100];

	count = 3;
	nbr = (unsigned long)address;
	if (address)
	{
		count = do_address(nbr, arr);
		if (flags.alignment > 0 && ft_intlen_u(nbr) > (int)ft_strlen(arr)
			&& flags.dot < flags.alignment)
			count += ft_putchar_int(' ');
		ft_putstr_int("0x");
		if (flags.zero || flags.dot)
			count += ft_zero_dot_p(nbr, flags, arr);
		ft_putstr_int(arr);
		if (flags.alignment < 0 && ft_intlen_u(nbr) > (int)ft_strlen(arr) &&
			flags.dot > flags.alignment && flags.dot)
			count += ft_putchar_int(' ');
		return (count);
	}
	ft_putstr_int("0x0");
	if (flags.zero || flags.dot)
		count = ft_zero_dot_p(nbr, flags, arr);
	return (count);
}
