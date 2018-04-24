/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_zero_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:39 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/24 15:31:52 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ns_zero_flags(t_fl *flags)
{
	flags->a_is= 0;
	flags->d_is= 0;
	flags->s_is= 0;
	flags->v_is= 0;
	flags->n_is= 0;
}

void	ns_zero_champ(t_champion **champ)
{
	t_champion *temp;

	temp = *champ;
	temp->exec_code = NULL;
	temp->real_program_size = 0;
	temp->id = 0;
	temp->magic = 0;
	temp->prog_size = 0;
}
