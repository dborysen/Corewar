/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:23:59 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/30 15:23:59 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	if (lst && f)
	{
		fresh = (*f)(lst);
		fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (NULL);
}
