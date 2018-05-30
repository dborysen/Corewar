/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:28:09 by myprosku          #+#    #+#             */
/*   Updated: 2017/10/30 14:28:10 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_list;
	t_list *curr_list;

	if (alst && del)
	{
		curr_list = *alst;
		while (curr_list)
		{
			next_list = curr_list->next;
			(*del)(curr_list->content, curr_list->content_size);
			free(curr_list);
			curr_list = next_list;
		}
		*alst = NULL;
	}
}
