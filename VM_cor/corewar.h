/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:22:27 by myprosku          #+#    #+#             */
/*   Updated: 2018/05/25 14:56:31 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
#define COREWAR_H

#include "libft/libft.h"
#include "op.h"
#include <ncurses.h>

# define T_RRR 0b010101
# define T_RIR 0b011101
# define T_RDR 0b011001
# define T_IRR 0b110101
# define T_IIR 0b111101
# define T_IDR 0b111001
# define T_DRR 0b100101
# define t_DIR 0b101101
# define T_DDR 0b101001
# define T_RDD 0b011010
# define T_RID 0b011110
# define T_IR 0b1101
# define T_DR 0b1001
# define T_RI 0b0111
# define T_RR 0b0101

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

typedef struct			s_vizor
{
	WINDOW				*ful;
	WINDOW				*map;
	WINDOW				*stat;
	int					height;
	int					width;
	int					pause;
}						t_vizor;

typedef struct			s_fl
{
	int					dump;
	int					d;
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
	int 				color;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_map
{
	unsigned char 		map[MEM_SIZE];
	int			 		color[MEM_SIZE];
	int					d;
	int					v;
}						t_map;

typedef struct			s_cursor
{
	int					index_pos;
	int					before_pos;
	int					nbr_player;
	int 				step;
	int					wait_cycle;
	int					commad;
	int 				live_or_die;
	int 				registr[REG_NUMBER + 1];
	int 				carry;
	int 				color;
	int 				champ_nbr;
	t_champion			*champ;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_info
{
	int 				total_cycles;
	int					cycles_limit;
	int					count_cursor;
	int 				cycles;
	int 				winner_nbr;
	char 				*winner_name;
	int					winner_col;
	int 				checks;
	int 				die;
	int 				end_game;
	t_champion			*champion;
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
t_cursor				*game_start_dump(t_cursor **cursor, t_map *m_map, t_info *info, t_fl fl);
t_cursor				*game_start(t_cursor **cursor, t_map *m_map, t_info *info);
int 					ns_check_register(int r1, int r2, int r3);
void					usage();
int						ns_check_id(t_champion *champ);
void					ns_check_flags(int ac, char **av, t_fl *flags, t_champion **champ);
void					ns_save_execute_code(t_champion **champ, unsigned char *file_info, int fd);
void 					ns_save_program_name(t_champion **champ, unsigned char *file_info);
void					ns_save_comment(t_champion **champ, unsigned char *file_info);
void					ns_save_magic(t_champion **champ, unsigned char *file_info);
void					ns_save_program_size(t_champion **champ, unsigned char *file_info);
//void					ns_check_lives(t_cursor **cur, t_info **info);
void					ns_check_lives(t_cursor **cur, t_info **info, t_map **map);
void					ns_reverse_cursor(t_cursor **cursor);
short					ns_two_bytes(t_map *map, int pos1, int pos2);
int 					ns_step_wrong_codage(int num);
int						ns_count_cursor(t_cursor *temp);
void					ns_reverse_champ(t_champion **champ);
char					*find_name_id(int id, t_info *info);
int						check_id_player(int id, t_info *info);

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
t_cursor				*ns_fork(t_cursor **cur, t_cursor **tmp, t_map *m_map, int n);

//*************

typedef void 			(*ns_array_of_functions)(t_cursor **cur, t_map *m_map);
unsigned char			*int_to_char(int nbr);
unsigned char			*find_fbytes_tind(t_map *map, int index);

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


void					ns_create_cycle(t_cursor **cursor, t_map *m_map);
t_cursor				*ns_move_cursor(t_cursor **cursor, t_map *map, t_info **info);

void					ns_ncurses(t_map *map, t_info *info, t_cursor **cursor, t_fl fl);
void					nc_right_print(t_vizor *viz, t_info *info);
void					nc_wait(t_vizor *viz, t_info *info, t_map *map, t_cursor **cursor, t_fl fl);
void					nc_set_color(void);
void					nc_get_color(t_map map, int i, t_vizor viz);
void					nc_check_window();
void					nc_qwer(int key, t_info *info, t_vizor *viz);
void					nc_print_all(t_map map, t_vizor *viz, t_info *info);
void					nc_print_map(t_map map, t_vizor viz, WINDOW *winmap);
void					nc_next_step(t_vizor *viz, t_info *info, t_map *map, t_cursor **cursor, t_fl fl);
t_cursor				**nc_game_start(t_cursor **cursor, t_map **m_map, t_info *info, t_fl fl);
void					nc_winner(t_vizor *viz, t_info *info);
void					clear_map(t_cursor *cur, t_map **map);

#endif
