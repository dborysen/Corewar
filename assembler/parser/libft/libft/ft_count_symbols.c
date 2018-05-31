/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:40:14 by dborysen          #+#    #+#             */
/*   Updated: 2018/05/31 11:40:15 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_symbols(char *str, char c)
{
	int i;
	int symb_count;

	i = 0;
	symb_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			symb_count++;
		i++;
	}
	return (symb_count);
}
