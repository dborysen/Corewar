/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:22:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/04/24 16:29:54 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
#define COREWAR_H

#include "libft/libft.h"
#include "op.h"

typedef struct		s_fl
{
	unsigned short		d_is;
	unsigned short		s_is;
	unsigned short		v_is;
	unsigned short		a_is;
	unsigned short		n_is;
	unsigned int		d_num;
	unsigned int		s_num;
	unsigned int		v_num;

}						t_fl;

typedef struct			s_champion
{
	char				prog_name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	size_t				real_program_size;
	unsigned int		prog_size;
	unsigned int		magic;
	char				*exec_code;
	int					id;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_map
{
	char 				**map;
}						t_map;


t_champion				*ns_read_champion(char *av, t_champion **champ);
int						unsigned_char_to_int(unsigned char *str);
void					ns_zero_flags(t_fl *flags);
void					ns_zero_champ(t_champion **champ);
void					ns_create_map(t_map *map);

#endif
