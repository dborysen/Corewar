/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:32:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/05/13 13:32:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

int		char_to_int2(char *str)
{
	int num;

	num = str[0] << 8;
	num += str[1];
	return (num);
}

char	*find_fbytes_tind2(t_map *map, int index)
{
	char	*str;
	int		i;
	int		pos;

	i = 0;
	str = (char *)malloc(sizeof(char) + 3);
	index %= MEM_SIZE;
	while (i < 2)
	{
		pos = index + i;
		if (pos < 0)
			pos += MEM_SIZE;
		if (pos >= MEM_SIZE)
			pos %= MEM_SIZE;
		str[i] = map->map[pos];
		i++;
	}
	str[i] = '\0';
	return str;
}

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

t_cursor	*ns_copy_cursor(t_cursor **cur)
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
	head->index_pos = ((temp->index_pos % IDX_MOD) + temp->index_pos);
	temp = head;
	temp->next = (*cur);
	(*cur) = temp;
	return (*cur);
}

void	ns_fork(t_cursor **cur, t_map *m_map)
{
	t_cursor	*temp;
	t_cursor	*fork;
	int			index;
	char		*str;

	temp = *cur;
	fork = NULL;
	str = find_fbytes_tind2(m_map, temp->index_pos + 1);
	index = char_to_int2(str);
	fork = ns_copy_cursor(&cur);
	temp->index_pos += 3;
}
