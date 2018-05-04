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

int				corefile(t_str_tokens *input, header_t header, char *name_of_file, int	position)
{
	int	fd;

	g_position = position;
	if (header.magic && name_of_file)
	;
	fd = open("file.cor", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	construct_data(input);
	write_in_file(input, fd);
	return(0);
}

void			construct_data(t_str_tokens *input)
{
	int				position;
	t_str_tokens	*track;

	position = 0;
	track = input;
	while (track)
	{
		track->position = position;
		track->size =  count_bytes(track);
		position = position + track->size;
		track = track->next;
	}
}

int				count_bytes(t_str_tokens *input)
{
	t_tokens	*tokens;
	int			t_dir;
	int			size;

	size = 0;
	tokens = input->valid;
	if (tokens->token == T_LAB)
		tokens = tokens->next;
	if (tokens->token == OPERATION)
	{
		size++;
		t_dir = search_size_of_label(tokens);
		if (op_with_codage(tokens) == OK)
			size++;
		tokens = tokens->next;
		size = size + size_of_arg(tokens, t_dir);
	}
	return (size);
}

int				op_with_codage(t_tokens *tokens)
{
	if (!ft_strcmp(tokens->current_str_piece, "live"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "zjmp"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "fork"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "lfork"))
		return (ERROR);
	if (!ft_strcmp(tokens->current_str_piece, "aff"))
		return (ERROR);
	return (OK);
}

int				size_of_arg(t_tokens *tokens, int t_dir)
{
	int			size;

	size = 0;
	while (tokens)
	{
		if (tokens->token == T_REG)
			size = size + 1;
		if (tokens->token == T_DIR)
			size = size + t_dir;
		if (tokens->token == T_IND)
			size = size + 2;
		tokens = tokens->next;
	}
	return (size);
}

int				search_size_of_label(t_tokens *tokens)
{
	int		i;

	i = 0;
	if (tokens->token == T_LAB)
		tokens = tokens->next;
	while (g_b_tab[i].name)
	{
		if (ft_strcmp(g_b_tab[i].name, tokens->current_str_piece) == 0)
			return (g_b_tab[i].size);
		i++;
	}
	return (ERROR);
}

void			write_in_file(t_str_tokens *input, int fd)
{
	t_str_tokens		*start_of_list;
	t_str_tokens		*copy_input;

	copy_input = input;
	start_of_list = input;
	while (copy_input)
	{
		copy_input->code =  build_code(copy_input, start_of_list);
		lseek(fd, 0, SEEK_CUR);
		write(fd, copy_input->code, copy_input->size);
		copy_input = copy_input->next;
	}
}

unsigned char 			*build_code(t_str_tokens *input, t_str_tokens *start_of_list)
{
	unsigned char			*code;
	unsigned char			*start_of_code;
	t_tokens		*tokens;


	code = NULL;
	tokens = input->valid;
	if (input->size > 0)
	{
		code = malloc(sizeof(char) * input->size);
		start_of_code = code;
		while (tokens)
		{
			if (tokens->token != T_LAB && tokens->token != EOL)
				convert_token(tokens, input, start_of_list, &code);
			tokens = tokens->next;
		}
	}
	int	i = 0;
	ft_printf("pos = [%d] ", input->position);
	while (i < input->size)
		ft_printf("[%.2x] ", start_of_code[i++]);
	ft_printf("\n");
	return (start_of_code);
}

int				convert_token(t_tokens *tokens, t_str_tokens *input, t_str_tokens *start_of_list, unsigned char **code)
{
	if (start_of_list)
	;
	if (tokens->token == OPERATION)
		return (code_op(tokens, input, code));
	if (tokens->token == T_REG)
		return (code_reg(tokens, input, code));
	if (tokens->token == T_DIR)
		return (code_dir(tokens, input, start_of_list, code));
	if (tokens->token == T_IND)
		return (code_ind(tokens, input, start_of_list, code));
	else
		return (1);
	return (ERROR);
}

int				code_op(t_tokens *tokens, t_str_tokens *input, unsigned char **code)
{
	int		i;

	i = 0;
	while (g_b_tab[i].name)
	{
		if (ft_strcmp(g_b_tab[i].name,tokens->current_str_piece) == 0)
		{
			(*code)[0] = g_b_tab[i].code;
			(*code)++;
			break ;
		}
		i++;
	}
	if (op_with_codage(tokens) == OK)
	{
		(*code)[0] = codage(input);
		(*code)++;
	}
	return (OK);
}

int				code_reg(t_tokens *tokens, t_str_tokens *input, unsigned char **code)
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

int				codage(t_str_tokens *input)
{
	int			size;
	t_tokens	*tokens;
	int			i;

	tokens = input->valid;
	size = 0;
	i = 3;
	while (i > 0 && tokens)
	{
		if (tokens->token == T_REG || tokens->token == T_DIR || tokens->token == T_IND)
		{
			size = codage_args(size, tokens);
			size = size << 2;
			i--;
		}
		tokens = tokens->next;
	}
	if (i > 0)
		size = size << 2;
	return (size);
}

int				codage_args(int size, t_tokens *tokens)
{
	if (tokens->token == T_DIR)
		return (size + 2);
	if (tokens->token == T_REG)
		return (size + 1);
	if (tokens->token == T_IND)
		return (size + 3);
	return (ERROR);
}

int				code_dir(t_tokens *tokens, t_str_tokens *input,
				t_str_tokens *start_of_list, unsigned char **code)
{
	int				t_dir;
	unsigned int	result;

	result = 0;
	t_dir = search_size_of_label(input->valid);
	if (tokens->current_str_piece[1] == ':')
		result = position_of_label(tokens->current_str_piece + 2, input, start_of_list);
	else
		result = ft_atoi(tokens->current_str_piece + 1);
	write_dir_in_code(code, result, t_dir);	
	return (OK);
}

int				position_of_label(char *label, t_str_tokens *input, t_str_tokens *start_of_list)
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
	free (copy_label);
	return (result);
}

void			write_dir_in_code(unsigned char **code, unsigned int result, int size)
{
	if (size == 2)
		when_size_dir_two(code, result);
	if (size == 4)
		when_size_dir_four(code, result);
}

void			when_size_dir_two(unsigned char **code, unsigned int result)
{
	result = (unsigned short int)result;
	(*code)[0] = result >> 8;
	(*code)++;
	(*code)[0] = result & 0xff;
	(*code)++;
}

void			when_size_dir_four(unsigned char **code, unsigned int result)
{
	(*code)[0] = result >> 24;
	(*code)++;
	(*code)[0] = (result & 0xff0000) >> 16;
	(*code)++;
	(*code)[0] = (result & 0xff00) >> 8;
	(*code)++;
	(*code)[0] = (result & 0xff);
	(*code)++;
}

int				code_ind(t_tokens *tokens, t_str_tokens *input,
				t_str_tokens *start_of_list, unsigned char **code)
{
	unsigned int res;

	if (tokens->current_str_piece[0] == ':')
		res = position_of_label(tokens->current_str_piece + 1, input, start_of_list);
	else
		res = (unsigned char)ft_atoi(tokens->current_str_piece);
	when_size_dir_two(code, res);
	return (OK);
}