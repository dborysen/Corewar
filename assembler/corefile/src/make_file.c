/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:57:00 by klee              #+#    #+#             */
/*   Updated: 2018/04/26 14:57:01 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../corewar.h"

byte_tab_t		g_b_tab[17] =
{
	{"live", 4, 0x01},
	{"ld", 4, 0x02},
	{"st", 0, 0x03},
	{"add", 0, 0x04},
	{"sub", 0, 0x05},
	{"and", 4, 0x06},
	{"or", 4, 0x07},
	{"xor", 4, 0x08},
	{"zjmp", 2, 0x09},
	{"ldi", 2, 0x0a},
	{"sti", 2, 0x0b},
	{"fork", 2, 0x0c},
	{"lld", 4, 0x0d},
	{"lldi", 2, 0x0e},
	{"lfork", 2, 0x0f},
	{"aff", 0, 0x10},
	{0, 0, 0}
};

int				g_position;

int				corefile(t_str_tokens *input,
	header_data_t header, int position)
{
	int			fd;
	char		*prog_name;

	g_position = position;
	prog_name = correct_name(header);
	fd = open(prog_name, O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	construct_data(input);
	write_in_file(input, header, fd);
	ft_printf("\n\e[1;37mWriting output program to \e[0m");
	ft_printf("\e[1;36m%s\e[0m\n\n", prog_name);
	free(prog_name);
	return (0);
}

void			write_in_file(t_str_tokens *input, header_data_t header, int fd)
{
	t_str_tokens		*start_of_list;
	t_str_tokens		*copy_input;

	copy_input = input;
	start_of_list = input;
	magic_number(fd);
	write(fd, header.bot_name, PROG_NAME_LENGTH);
	prog_length(input, fd);
	write(fd, header.bot_comment, COMMENT_LENGTH + 4);
	while (copy_input)
	{
		copy_input->code = build_code(copy_input, start_of_list);
		lseek(fd, 0, SEEK_CUR);
		write(fd, copy_input->code, copy_input->size);
		copy_input = copy_input->next;
	}
}

int				position_of_label(
	char *label, t_str_tokens *input, t_str_tokens *start_of_list)
{
	int		result;
	char	*copy_label;

	copy_label = ft_strjoin(label, ":");
	result = 0;
	while (start_of_list)
	{
		if (ft_strcmp(start_of_list->valid->current_str_piece, copy_label) == 0)
			break ;
		start_of_list = start_of_list->next;
	}
	result = start_of_list->position - input->position;
	free(copy_label);
	return (result);
}

void			write_dir_in_code(
	unsigned char **code, unsigned int result, int size)
{
	if (size == 2)
		when_size_dir_two(code, result);
	if (size == 4)
		when_size_dir_four(code, result);
}

int				code_ind(t_tokens *tokens, t_str_tokens *input,
	t_str_tokens *start_of_list, unsigned char **code)
{
	int res;

	if (tokens->current_str_piece[0] == ':')
		res = position_of_label(
			tokens->current_str_piece + 1, input, start_of_list);
	else
		res = ft_atoi(tokens->current_str_piece);
	when_size_dir_two(code, res);
	return (OK);
}
