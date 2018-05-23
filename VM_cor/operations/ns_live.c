/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:19:37 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/23 13:53:19 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ns_live(t_cursor **cur, t_map *m_map)
{
	t_cursor 		*temp;
	t_reg			reg;
	unsigned char 	*str;

	temp = *cur;
	temp->live_or_die = 1;
	str = find_fbytes_tind(m_map, temp->index_pos + 1);
	reg.index = unsigned_char_to_int(str);
	temp->champ->life = 1;
	if (temp->nbr_player == reg.index && !m_map->d)
		ft_printf("A process shows that player %d (%s) is alive\n", temp->champ->id, temp->champ->champ_name);
	temp->index_pos += 5;
}
