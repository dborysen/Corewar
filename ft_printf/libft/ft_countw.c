/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:30:17 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/17 15:59:43 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countw(char const *s, char c)
{
	int state;
	int words;
	int i;

	state = 0;
	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			state = 0;
		else if (state == 0)
		{
			state = 1;
			words++;
		}
		i++;
	}
	return (words);
}
