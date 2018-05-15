/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:22:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/15 13:22:04 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
#define COREWAR_H

#include "libft/libft.h"
#include "op.h"
# define T_RRR 0b01010100
# define T_RIR 0b01110100
# define T_RDR 0b01100100
# define T_IRR 0b11010100
# define T_IIR 0b11110100
# define T_IDR 0b11100100
# define T_DRR 0b10010100
# define t_DIR 0b10110100
# define T_DDR 0b10100100
# define T_RDD 0b01101000
# define T_RID 0b01111000
# define T_IR 0b11010000
# define T_DR 0b10010000
# define T_RI 0b01110000
# define T_RR 0b01010000

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
	int 				life;
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
	int 				registr[REG_NUMBER + 1];
	int 				carry;
	t_champion			*champ;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_info
{
	int 				total_cycles;
	int 				cycles;
	int 				winner;
	int 				checks;
	int 				die;
}						t_info;

typedef struct 			s_reg
{
	int 				r1;
	int 				r2;
	int 				r3;
	int 				index;
	short				dir;
	short				dir2;
}						t_reg;

t_champion				*ns_read_champion(char *av, t_champion **champ);
int						unsigned_char_to_int(unsigned char *str);
void					ns_zero_flags(t_fl *flags);
void					ns_zero_champ(t_champion **champ);
void					ns_zero_info(t_info *info);
void					ns_create_map(t_map *map);
void					ns_print_map(t_map memory_map);
void					ns_dump_flag(t_champion *champ);
void					ns_position_start(t_champion **champ);
void					ns_fill_map(t_champion *champ, t_map *map);
void 					ns_error(char *err_message);
void					ns_zero_cursor(t_cursor **cursor);
void					ns_zero_reg(t_reg *reg);
void					ns_create_cursor(t_cursor **cursor, t_champion *champ);
//void					ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info, t_fl flags);
t_cursor	*ns_game_start(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl);
int 					ns_check_register(int r1, int r2, int r3);
void					usage();
int						ns_check_id(t_champion *champ);
void					ns_check_flags(int ac, char **av, t_fl *flags, t_champion **champ);
void					ns_save_execute_code(t_champion **champ, unsigned char *file_info, int fd);
void 					ns_save_program_name(t_champion **champ, unsigned char *file_info);
void					ns_save_comment(t_champion **champ, unsigned char *file_info);
void					ns_save_magic(t_champion **champ, unsigned char *file_info);
void					ns_save_program_size(t_champion **champ, unsigned char *file_info);
void					ns_check_lives(t_cursor **cur, t_info **info);
void					ns_reverse_cursor(t_cursor **cursor);
void					ns_delete_nth(t_cursor **head, t_cursor *temp);

//Champ functions
void					ns_add(t_cursor **cur, t_map *m_map);
void					ns_sub(t_cursor **cur, t_map *m_map);
void					ns_st(t_cursor **cur, t_map *m_map);
void					ns_sti(t_cursor **cur, t_map *m_map);
void					ns_ld(t_cursor **cur, t_map *m_map);
void					ns_lld(t_cursor **cur, t_map *m_map);
void					ns_ldi(t_cursor **cur, t_map *m_map);
void					ns_lldi(t_cursor **cur, t_map *m_map);
void					ns_zjmp(t_cursor **cur, t_map *m_map);
void					ns_aff(t_cursor **cur, t_map *m_map);
void					ns_live(t_cursor **cur, t_map *m_map);

//*************

typedef void 			(*ns_array_of_functions)(t_cursor **cur, t_map *m_map);
char					*int_to_char(int nbr);
int						char_to_int(char *str);
char					*find_fbytes_tind(t_map *map, int index);

// AND
void					ns_and(t_cursor **cur, t_map *m_map);
void					ns_iir_and(t_cursor **cur, t_map *m_map);
void					ns_idr_and(t_cursor **cur, t_map *m_map);
void					ns_irr_and(t_cursor **cur, t_map *m_map);
void					ns_dir_and(t_cursor **cur, t_map *m_map);
void					ns_ddr_and(t_cursor **cur, t_map *m_map);
void					ns_drr_and(t_cursor **cur, t_map *m_map);
void					ns_rir_and(t_cursor **cur, t_map *m_map);
void					ns_rdr_and(t_cursor **cur, t_map *m_map);
void					ns_rrr_and(t_cursor **cur, t_map *m_map);

//OR
void					ns_or(t_cursor **cur, t_map *m_map);
void					ns_iir_or(t_cursor **cur, t_map *m_map);
void					ns_idr_or(t_cursor **cur, t_map *m_map);
void					ns_irr_or(t_cursor **cur, t_map *m_map);
void					ns_dir_or(t_cursor **cur, t_map *m_map);
void					ns_ddr_or(t_cursor **cur, t_map *m_map);
void					ns_drr_or(t_cursor **cur, t_map *m_map);
void					ns_rir_or(t_cursor **cur, t_map *m_map);
void					ns_rdr_or(t_cursor **cur, t_map *m_map);
void					ns_rrr_or(t_cursor **cur, t_map *m_map);

//XOR
void					ns_xor(t_cursor **cur, t_map *m_map);
void					ns_iir_xor(t_cursor **cur, t_map *m_map);
void					ns_idr_xor(t_cursor **cur, t_map *m_map);
void					ns_irr_xor(t_cursor **cur, t_map *m_map);
void					ns_dir_xor(t_cursor **cur, t_map *m_map);
void					ns_ddr_xor(t_cursor **cur, t_map *m_map);
void					ns_drr_xor(t_cursor **cur, t_map *m_map);
void					ns_rir_xor(t_cursor **cur, t_map *m_map);
void					ns_rdr_xor(t_cursor **cur, t_map *m_map);
void					ns_rrr_xor(t_cursor **cur, t_map *m_map);

//void	ns_fork(t_cursor ***cur, t_cursor **tmp, t_map *m_map, int n);
t_cursor	*ns_fork(t_cursor **cur, t_cursor **tmp, t_map *m_map, int n);
#endif
