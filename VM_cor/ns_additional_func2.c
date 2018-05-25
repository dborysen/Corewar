/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:49:08 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 14:49:21 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ns_count_cursor(t_cursor *temp)
{
	int len;

	len = 0;
	if (temp == NULL)
		return (0);
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	delete_node(t_cursor **head, t_cursor *del, t_map **map)
{
	t_cursor	*temp;
	t_cursor	*prev;

	temp = *head;
	prev = NULL;
	if (temp != NULL && temp == del)
	{
		*head = temp->next;
		clear_map(temp, map);
		free(temp);
		return ;
	}
	while (temp != NULL && temp != del)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	clear_map(temp, map);
	free(temp);
}

void	ns_delete_cur(t_cursor **cur, int *count, t_map **map)
{
	t_cursor	*temp;

	temp = *cur;
	*count = 0;
	while (temp)
	{
		if (temp->live_or_die)
		{
			temp->live_or_die = 0;
			*count += 1;
		}
		else
			delete_node(cur, temp, map);
		temp = temp->next;
	}
}

void	ns_check_lives(t_cursor **cur, t_info **info, t_map **map)
{
	int			count;

	count = 0;
	ns_delete_cur(cur, &count, map);
	if (count < NBR_LIVE)
		(*info)->checks -= 1;
	else
	{
		(*info)->die -= CYCLE_DELTA;
		(*info)->checks = MAX_CHECKS;
	}
	if ((*info)->checks <= 0)
	{
		(*info)->die -= CYCLE_DELTA;
		(*info)->checks = MAX_CHECKS;
	}
	if (ns_count_cursor(*cur) == 0 || (*info)->die <= 0)
		(*info)->end_game = 1;
}

int 	ns_step_wrong_codage(int num)
{
	int ret;

	ret = 1;
	num = num >> 2;
	if ((num >> 4) == REG_CODE)
		ret += 1;
	else if ((num >> 4) == DIR_CODE)
		ret += g_op_tab->label_size == 0 ? 4 : 2;
	else if ((num >> 4) == IND_CODE)
		ret += 2;
	if (((num >> 2) & 3) == REG_CODE)
		ret += 1;
	else if (((num >> 2) & 3) == DIR_CODE)
		ret += g_op_tab->label_size == 0 ? 4 : 2;
	else if (((num >> 2) & 3)== IND_CODE)
		ret += 2;
	if ((num & 3) == REG_CODE)
		ret += 1;
	else if ((num & 3) == DIR_CODE)
		ret += g_op_tab->label_size == 0 ? 4 : 2;
	else if ((num & 3) == IND_CODE)
		ret += 2;
	return (ret);
}
