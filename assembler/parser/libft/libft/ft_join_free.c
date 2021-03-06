/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:03:56 by klee              #+#    #+#             */
/*   Updated: 2018/02/07 15:03:57 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_join_free(char **str, char *src)
{
	char	*s;

	s = *str;
	*str = ft_strjoin(*str, src);
	free(s);
}
