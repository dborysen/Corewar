/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corefile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:59:49 by klee              #+#    #+#             */
/*   Updated: 2018/04/26 14:59:50 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREFILE_H
# define COREFILE_H
# include "libft.h"
# include "../../../corewar.h"

typedef struct	s_byte_tab
{
	char	*name;
	int		size;
	int		code;
}				t_byte_tab;

int				g_position;

void			construct_data(t_str_tokens *input);
int				corefile(t_str_tokens *input,
	t_header_data header, int	position);
int				count_bytes(t_str_tokens *input);
int				op_with_codage(t_tokens *tokens);
int				size_of_arg(t_tokens *tokens, int t_dir);
int				search_size_of_label(t_tokens *tokens);
int				build_code(t_str_tokens *input,
t_str_tokens *start_of_list, unsigned char **code);
int				convert_token(t_tokens *tokens,
t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);
int				code_op(t_tokens *tokens,
t_str_tokens *input, unsigned char **code);
int				code_reg(t_tokens *tokens,
t_str_tokens *input, unsigned char **code);
int				codage(t_str_tokens *input);
int				code_dir(t_tokens *tokens,
t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);
int				position_of_label(char *label,
t_str_tokens *input, t_str_tokens *start_of_list);
void			write_dir_in_code(unsigned char **code,
unsigned int result, int size);
void			write_in_file(t_str_tokens *input,
t_header_data header, int fd);
void			when_size_dir_two(unsigned char **code,
unsigned int result);
void			when_size_dir_four(unsigned char **code,
unsigned int result);
void			when_size_dir_eight(unsigned char **code,
unsigned int result);
int				code_ind(t_tokens *tokens,
t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);
int				codage_args(int size, t_tokens *tokens);
char			*correct_name(t_header_data header);
void			magic_number(int fd);
void			prog_length(t_str_tokens *input, int fd);
int				valid_label(char *label, t_str_tokens *start_of_list);
int				plus_validation(t_str_tokens *input);

#endif
