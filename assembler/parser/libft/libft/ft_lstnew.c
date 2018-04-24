/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:38:29 by klee              #+#    #+#             */
/*   Updated: 2017/11/17 11:21:11 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t size)
{
	t_list	*list_new;

	list_new = (t_list*)ft_memalloc(sizeof(t_list));
	if (!list_new)
		return (0);
	list_new->content = ft_memalloc(size);
	if (!list_new->content)
		return (0);
	else if (!content)
	{
		list_new->content = 0;
		list_new->content_size = 0;
	}
	else
	{
		list_new->content = ft_memcpy(list_new->content,\
			(void*)content, size + 1);
		list_new->content_size = size;
	}
	list_new->next = NULL;
	return (list_new);
}
