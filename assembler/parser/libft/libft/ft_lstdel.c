/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:04:11 by klee              #+#    #+#             */
/*   Updated: 2017/11/10 15:09:26 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **av, void (*del)(void*, size_t))
{
	t_list	*buff;

	if (*av != NULL)
	{
		while (*av != NULL)
		{
			buff = (*av);
			*av = (*av)->next;
			del((buff)->content, (buff)->content_size);
			free(buff);
		}
	}
}
