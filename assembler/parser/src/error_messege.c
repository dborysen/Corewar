/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messege.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:22:27 by klee              #+#    #+#             */
/*   Updated: 2018/04/26 14:22:32 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../libft/includes/libft.h"

/*
**	error messege
*/

int			error_messege(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	char	*str;
	int		place_in_str;
	char	*copy_str;

	str = " ";
	place_in_str = ft_strstr(input->current_str, input_tokens->current_str_piece) - input->current_str;
	copy_str = arrow_in_str(input->current_str, place_in_str, '^');
	if (input_tokens->token == T_DIR)
		str = " DIRECT ";
	if (input_tokens->token == T_IND)
		str = " INDIRECT ";
	if (input_tokens->token == T_REG)
		str = " REGISTER ";
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[0m");
	ft_printf("\e[1;37mat [%d:%03d]\e[0m\n", index, place_in_str);
	ft_printf("\t%s\e[0m\n", input->current_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", copy_str);
	return (ERROR);
}

int			error_messege_for_arguments(t_tokens *input_tokens,
t_op args, int i)
{
	char	*str;

	str = NULL;
	if (input_tokens->token == T_DIR)
		str = "register";
	if (input_tokens->token == T_IND)
		str = "indirect";
	if (input_tokens->token == T_REG)
		str = "direct";
	if (input_tokens->token == EOL)
		str = "end of line";
	ft_printf("\n\e[1;31mINVALIDE PARAMETR: \e[0m");
	ft_printf("%d type \"%s\" for instruction %s\n\n",
	i, str, args.name);
	return (ERROR);
}

int			error_messege_if_not_enough(t_op args)
{
	ft_printf("\n\e[1;31mINVALID PARAMETR: \e[0m");
	ft_printf("\e[1;37mcount for instruction %s\e[0m\n\n", args.name);
	return (ERROR);
}

int			error_messege_for_operation(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	int		place_in_str;
	char	*copy_str;

	place_in_str = ft_strstr(input->current_str, input_tokens->current_str_piece) - input->current_str;
	copy_str = arrow_in_str(input->current_str, place_in_str, '^');
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	ft_printf("\n\e[1;31mINVALID INSTRUCTION: \e[0m");
	ft_printf("\e[1;37mat [%d:%d]\n", index, place_in_str);
	ft_printf("\t%s\e[0m\n", input->current_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", copy_str);
	free (copy_str);
	return (ERROR);
}

char	*arrow_in_str(char *head_line, int arrow_place, char c)
{
	int		i;
	char	*arrow_line;
	
	i = 0;
	arrow_line = ft_strdup(head_line);
	while (arrow_line[i] != '\0')
	{
		if (arrow_line[i] == '\t')
			arrow_line[i] = '\t';
		else
			arrow_line[i] = ' ';
		i++;
	}
	arrow_line[arrow_place] = c;
	return (arrow_line);
}