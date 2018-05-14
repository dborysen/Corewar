/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:32:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/14 14:00:44 by ssavchen         ###   ########.fr       */
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

t_cursor	*ns_copy_cursor(t_cursor *tmp, int index, int n)
{
	t_cursor	*head;

	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->nbr_player = tmp->nbr_player;
	head->step = tmp->step;
	head->wait_cycle = tmp->wait_cycle;
	head->commad = tmp->commad;
	head->live_or_die = tmp->live_or_die;
	ns_copy_reg(tmp->registr, head->registr);
	head->carry = tmp->carry;
	head->champ = tmp->champ;
	if (n == 1)
		head->index_pos = ((index % IDX_MOD) + tmp->index_pos);
	else
		head->index_pos = (index + tmp->index_pos);
	return (head);
}

void	ns_add_head_cursor(t_cursor **cur, t_cursor *head)
{
//	t_cursor	*tmp;

//	tmp = head;
	head->next = *cur;
	*cur = head;
}

void	ns_fork(t_cursor **cur, t_cursor **tmp, t_map *m_map, int n)
{
	t_cursor	*temp;
	t_cursor	*fork;
	int			index;
	char		*str;

	temp = *cur;
	fork = NULL;
	index = (short)(m_map->map[(*tmp)->index_pos + 1] << 8) | (m_map->map[(*tmp)->index_pos + 2]);
	fork = ns_copy_cursor(*tmp, index, n);
	ns_add_head_cursor(&temp, fork);
	(*tmp)->index_pos += 3;
}
