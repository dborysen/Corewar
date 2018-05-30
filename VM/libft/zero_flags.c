/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:12:35 by myprosku          #+#    #+#             */
/*   Updated: 2018/01/11 15:55:36 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	zero_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->alignment = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->h = 0;
	flags->l = 0;
	flags->j = 0;
	flags->z = 0;
	flags->n_chr = 0;
}
