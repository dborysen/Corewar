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

int				corefile(t_str_tokens *input,
	t_header_data header, int position)
{
	int			fd;
	char		*prog_name;

	g_position = position;
	prog_name = correct_name(header);
	if (prog_name == NULL)
	{
		ft_printf("\n\e[1;31mERROR: \e[1;37mexpecting\e[1;36m ");
		ft_printf(".s\e[0m \e[1;37mfile\e[0m\e[0m\n\n");
		return (ERROR);
	}
	construct_data(input);
	if (plus_validation(input) == ERROR || all_headers_filled(header) == ERROR)
	{
		ft_strdel(&prog_name);
		return (ERROR);
	}
	fd = open(prog_name, O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write_in_file(input, header, fd);
	ft_printf("\n\e[1;37mWriting output program to \e[0m");
	ft_printf("\e[1;36m%s\e[0m\n\n", prog_name);
	ft_strdel(&prog_name);
	return (0);
}

void			write_in_file(t_str_tokens *input, t_header_data header, int fd)
{
	t_str_tokens		*start_of_list;
	t_str_tokens		*copy_input;
	unsigned char		*code;

	copy_input = input;
	start_of_list = input;
	magic_number(fd);
	write(fd, header.bot_name, PROG_NAME_LENGTH);
	prog_length(input, fd);
	write(fd, header.bot_comment, COMMENT_LENGTH + 4);
	copy_input = input;
	while (copy_input)
	{
		build_code(copy_input, start_of_list, &code);
		lseek(fd, 0, SEEK_CUR);
		write(fd, code, copy_input->size);
		free(code);
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

int				code_reg(
	t_tokens *tokens, t_str_tokens *input, unsigned char **code)
{
	char	*str;
	int		result;

	str = tokens->current_str_piece;
	str++;
	result = ft_atoi(str);
	if (result >= 100)
		return (error_messege(input, tokens, g_position));
	else
	{
		(*code)[0] = result;
		(*code)++;
		return (OK);
	}
	return (result);
}
