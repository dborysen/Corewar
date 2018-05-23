/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_additional_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:49:08 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/22 16:50:14 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 			ns_error(char *err_message)
{
	ft_printf("Error with problem: %s.\n", err_message);
	exit(0);
}

void		usage()
{
	ft_printf("Usage: ./corewar [-dump N | "
					  " -n N] [-v] <champion1.cor> <...>");
}

int 			ns_check_register(int r1, int r2, int r3)
{
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (0);
	if (r1 <= 0 || r2 <= 0 || r3 <= 0)
		return (0);
	return (1);
}

int			ns_check_id(t_champion *champ)
{
	while (champ->next)
	{
		if (champ->id == champ->next->id)
			return (0);
		champ = champ->next;
	}
	return (1);
}

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

void	delete_node(t_cursor **head, t_cursor *del)
{
	t_cursor *temp;
	t_cursor *prev;

	temp = *head;
	prev = NULL;
	if (temp != NULL && temp == del)
	{
		*head = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL && temp != del)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	prev->next = temp->next;
	free(temp);
}

void	ns_check_lives(t_cursor **cur, t_info **info)
{
	int			count;
	t_cursor	*temp;

	count = 0;
	temp = *cur;
	while (temp)
	{
		if (temp->live_or_die)
		{
			temp->live_or_die = 0;
			count++;
		}
		else
			delete_node(cur, temp);
		temp = temp->next;
	}
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
	{
		ft_printf("Player %d, (\"%s\") has won !!\n", (*info)->winner_nbr, (*info)->winner_name);
		(*info)->end_game = 1;
	}
}

short	ns_two_bytes(t_map *map, int pos1, int pos2)
{
	pos1 = pos1 < 0 ? pos1 + MEM_SIZE : pos1 % MEM_SIZE;
	pos2 = pos2 < 0 ? pos2 + MEM_SIZE : pos2 % MEM_SIZE;
	return ((map->map[pos1] << 8) | (map->map[pos2]));
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
