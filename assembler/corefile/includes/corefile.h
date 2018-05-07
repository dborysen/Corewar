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

typedef struct list_s
{
	char		*data;
	int			size;
}				list_t;

typedef struct	byte_tab_s
{
	char	*name;
	int		size;
	int		code;
}				byte_tab_t;

void			construct_data(t_str_tokens *input);
int				corefile(t_str_tokens *input, header_data_t header, int	position);
int				count_bytes(t_str_tokens *input);
int				op_with_codage(t_tokens *tokens);
int				size_of_arg(t_tokens *tokens, int t_dir);
int				search_size_of_label(t_tokens *tokens);
unsigned char 	*build_code(t_str_tokens *input, t_str_tokens *start_of_list);
int				convert_token(t_tokens *tokens, t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);
int				code_op(t_tokens *tokens, t_str_tokens *input, unsigned char **code);
int				code_reg(t_tokens *tokens, t_str_tokens *input, unsigned char **code);
int				codage(t_str_tokens *input);
int				code_dir(t_tokens *tokens, t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);
int				position_of_label(char *label, t_str_tokens *input, t_str_tokens *start_of_list);
void			write_dir_in_code(unsigned char **code, unsigned int result, int size);
void			write_in_file(t_str_tokens *input, header_data_t header, int fd);
void			when_size_dir_two(unsigned char **code, unsigned int result);
void			when_size_dir_four(unsigned char **code, unsigned int result);
void			when_size_dir_eight(unsigned char **code, unsigned int result);
int				code_ind(t_tokens *tokens, t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code);;
int				codage_args(int size, t_tokens *tokens);
char			*correct_name(header_data_t header);
void			magic_number(int fd);
void			prog_length(t_str_tokens *input, int fd);

#endif
