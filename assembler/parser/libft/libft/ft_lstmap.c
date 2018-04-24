/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:45:00 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 13:31:48 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tlst;
	t_list	*new;
	t_list	*start;

	if (!lst)
		return (0);
	tlst = f(lst);
	if (!(new = ft_lstnew(tlst->content, tlst->content_size)))
		return (0);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tlst = f(lst);
		if (!(new->next = ft_lstnew(tlst->content, tlst->content_size)))
			return (0);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
