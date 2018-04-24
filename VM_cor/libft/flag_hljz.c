/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hljz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:28:09 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:34 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_hljz(const char ***format, t_flags **flags)
{
	t_flags *temp;

	temp = *flags;
	while (***format == 'h' || ***format == 'l' ||
			***format == 'j' || ***format == 'z')
	{
		if (***format == 'h')
			temp->h += 1;
		else if (***format == 'l')
			temp->l += 1;
		else if (***format == 'j')
			temp->j += 1;
		else if (***format == 'z')
			temp->z += 1;
		**format += 1;
	}
}
