/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:22:53 by klee              #+#    #+#             */
/*   Updated: 2018/01/19 17:22:55 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_flgs	*flag_list(void)
{
	t_flgs	*new;

	new = malloc(sizeof(t_flgs));
	new->type = ft_strdup("");
	new->flags = ft_strdup("");
	new->size = ft_strdup("");
	new->length = 0;
	new->accuracy = 0;
	return (new);
}

void	del_flag_list(t_flgs **fnt)
{
	free((*fnt)->type);
	free((*fnt)->flags);
	free((*fnt)->size);
	free((*fnt));
}

t_prf	*f_listnew(char *type, char *flags, char *size, void (*f)())
{
	t_prf	*new;

	new = malloc(sizeof(t_prf));
	new->type = ft_strdup(type);
	new->flags = ft_strdup(flags);
	new->size = ft_strdup(size);
	new->f = f;
	new->next = NULL;
	return (new);
}

void	del_prf(t_prf **in)
{
	t_prf *tmp;

	while (*in)
	{
		tmp = (*in);
		free((*in)->type);
		free((*in)->flags);
		free((*in)->size);
		(*in) = (*in)->next;
		free(tmp);
	}
}
