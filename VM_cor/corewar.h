/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:22:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/03 16:59:00 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
#define COREWAR_H

#include "libft/libft.h"
#include "op.h"

static const	t_op    g_op_tab[17] =
{
				{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
				{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
				{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
				{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
				{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
				{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
						"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
				{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
						"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
				{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
						"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
				{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
				{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
						"load index", 1, 1},
				{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
						"store index", 1, 1},
				{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
				{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
				{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
						"long load index", 1, 1},
				{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
				{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
				{0, 0, {0}, 0, 0, 0, 0, 0}
};

typedef struct			s_fl
{
	int					dump;
	int					n;
	short				v;

}						t_fl;

typedef struct			s_champion
{
	char				champ_name[PROG_NAME_LENGTH + 1];
	char				champ_comment[COMMENT_LENGTH + 1];
	size_t				file_size;
	unsigned int		size_bytes;
	unsigned int		magic;
	unsigned char		*exec_code;
	int					id;
	int					position_to_start;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_map
{
	unsigned char 		map[MEM_SIZE];
}						t_map;

typedef struct			s_cursor
{
	int					index_pos;
	int					nbr_player;
	int 				step;
	int					wait_cycle;
	int					commad;
	int 				live_or_die;
	int 				registr[16];
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_info
{
	int 				total_cycles;
}						t_info;

t_champion				*ns_read_champion(char *av, t_champion **champ);
int						unsigned_char_to_int(unsigned char *str);
void					ns_zero_flags(t_fl *flags);
void					ns_zero_champ(t_champion **champ);
void					ns_zero_info(t_info *info);
void					ns_create_map(t_map *map);
void					ns_print_map(t_map memory_map);
void					ns_dump_flag(t_champion *champ, t_map memory_map);
void					ns_position_start(t_champion **champ);
void					ns_fill_map(t_champion *champ, t_map *map);
void 					ns_error(char *err_message);
void					ns_zero_cursor(t_cursor **cursor);
void					ns_create_cursor(t_cursor **cursor, t_champion *champ);
void					ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info);

#endif
