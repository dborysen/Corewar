/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:32:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/25 16:09:08 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ns_copy_reg(int *src, int *dest)
{
	int		i;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		dest[i] = src[i];
		i++;
	}
}

void		ns_fork_pos(t_cursor **head, t_cursor *tmp, int index, int n)
{
	t_cursor	*head_t;

	head_t = *head;
	if (n == 1)
	{
		head_t->index_pos = tmp->index_pos + index % IDX_MOD;
		head_t->index_pos = head_t->index_pos < 0 ? head_t->index_pos + MEM_SIZE
												: head_t->index_pos % MEM_SIZE;
	}
	else
	{
		head_t->index_pos = index + tmp->index_pos;
		head_t->index_pos = head_t->index_pos < 0 ? head_t->index_pos + MEM_SIZE
												: head_t->index_pos % MEM_SIZE;
	}
}

t_cursor	*ns_copy_cursor(t_cursor *tmp, short index, int n)
{
	t_cursor	*head;

	head = (t_cursor *)malloc(sizeof(t_cursor));
	head->nbr_player = tmp->nbr_player;
	head->step = tmp->step;
	head->wait_cycle = 0;
	head->commad = 0;
	head->live_or_die = tmp->live_or_die;
	ns_copy_reg(tmp->registr, head->registr);
	head->carry = tmp->carry;
	head->champ = tmp->champ;
	head->color = tmp->color;
	head->before_pos = tmp->before_pos;
	ns_fork_pos(&head, tmp, index, n);
	return (head);
}

t_cursor	**ns_add_head_cursor(t_cursor **cur, t_cursor *head)
{
	head->next = *cur;
	*cur = head;
	return (cur);
}

t_cursor	*ns_fork(t_cursor **cur, t_cursor **tmp, t_map *m_map, int n)
{
	t_cursor	*temp;
	t_cursor	*fork;
	short		index;

	temp = *cur;
	fork = NULL;
	index = ns_two_bytes(m_map, (*tmp)->index_pos + 1, (*tmp)->index_pos + 2);
	fork = ns_copy_cursor(*tmp, index, n);
	cur = ns_add_head_cursor(&temp, fork);
	(*tmp)->index_pos += 3;
	return (*cur);
}
