/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:32:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/14 13:19:48 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_copy_reg(int *src, int *dest)
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		dest[i] = src[i];
		i++;
	}
}

t_cursor	*ns_copy_cursor(t_cursor **cur, int index, int n)
{
	t_cursor	*head;
	t_cursor	*temp;

	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->nbr_player = (*cur)->nbr_player);
	head->step = (*cur)->step;
	head->wait_cycle = (*cur)->wait_cycle;
	head->commad = (*cur)->commad;
	head->live_or_die = (*cur)->live_or_die;
	ns_copy_reg((*cur)->registr, head->registr);
	head->carry = (*cur)->carry;
	head->champ = (*cur)->champ;
	if (n == 1)
		head->index_pos = ((index % IDX_MOD) + temp->index_pos);
	else
		head->index_pos = (index + temp->index_pos);
	temp = head;
	temp->next = (*cur);
	(*cur) = temp;
	return (*cur);
}

void	ns_fork(t_cursor **cur, t_map *m_map, int n)
{
	t_cursor	*temp;
	t_cursor	*fork;
	int			index;
	char		*str;

	temp = *cur;
	fork = NULL;
	index = (short)(m_map->map[temp->index_pos + 1] << 8) | (m_map->map[temp->index_pos + 2]);
	fork = ns_copy_cursor(&cur, index, n);
	temp->index_pos += 3;
}
