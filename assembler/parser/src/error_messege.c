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

static char		*dop_funct(int i, size_t o, char *s1, char *s2)
{
	int		d;

	if (*s1 && *s2)
		while (i >= 0)
		{
			d = i;
			o = 0;
			while (s2[o])
			{
				if (s1[d] == s2[o])
					o++;
				else
					break ;
				d++;
			}
			if (o == ft_strlen(s2))
				return (s1 + i);
			i--;
		}
	return (0);
}

char			*t_strrstr(const char *big, const char *little)
{
	int		i;
	size_t	o;
	char	*s1;
	char	*s2;

	o = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	i = ft_strlen(s1);
	if (ft_strlen(s2) == 0)
		return (s1);
	return (dop_funct(i - 1 , o, s1, s2));
}

int			error_messege(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	int		place_in_str;
	int		place_in_trimmed_str;
	char	*copy_str;
	char	*trimmed_str;

	trimmed_str = ft_strtrim(input->current_str);
	place_in_str = t_strrstr(input->current_str, input_tokens->current_str_piece) - input->current_str;
	place_in_trimmed_str = t_strrstr(trimmed_str, input_tokens->current_str_piece) - trimmed_str;
	copy_str = arrow_in_str(trimmed_str, place_in_trimmed_str);
	ft_printf("\n\e[1;31mSYNTAX ERROR: \e[0m");
	ft_printf("\e[1;37mat [%d:%d]\e[0m\n", index, place_in_str);
	ft_printf("\t\e[1;37m%s\e[0m\n", trimmed_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", copy_str);
	ft_strdel(&trimmed_str);
	return (ERROR);
}

int			error_messege_for_arguments(t_str_tokens *input,
t_tokens *input_tokens, t_op args, int index)
{
	int		place_in_str;
	
	place_in_str = t_strrstr(input->current_str, input_tokens->current_str_piece) - input->current_str;
	if (input_tokens->token != EOL)
	{
		ft_printf("\n\e[1;31mERROR:\e[0m\e[1;37m at [%d:%d]\n\e[0m", index, place_in_str);
		ft_printf("\t\e[1;37minvalid parametr \'%s\' for instruction\e[0m \e[1;36m%s\e[0m\n\n",
			input_tokens->current_str_piece, args.name);
	}
	return (ERROR);
}

int			error_messege_if_not_enough(t_str_tokens *input, t_op args, int index)
{
	ft_printf("\n\e[1;31mERROR:\e[0m\e[1;37m at [%d:%d]\n\e[0m", index, ft_strlen(input->current_str));
	ft_printf("\t\e[1;37minvalid parametr count for instruction\e[0m \e[1;36m%s\e[0m\n\n", args.name);
	return (ERROR);
}

int			error_messege_for_operation(t_str_tokens *input,
			t_tokens *input_tokens, int index)
{
	int		place_in_str;
	int		place_in_trimmed_str;
	char	*copy_str;
	char	*str_trim;

	str_trim = ft_strtrim(input->current_str);
	place_in_str = ft_strstr(input->current_str, input_tokens->current_str_piece) - input->current_str;
	place_in_trimmed_str = ft_strstr(str_trim, input_tokens->current_str_piece) - input->current_str;
	copy_str = arrow_in_str(str_trim, place_in_trimmed_str);
	if (ft_strlen(input_tokens->current_str_piece) == 0)
		input_tokens->current_str_piece = 0;
	ft_printf("\n\e[1;31mINVALID INSTRUCTION: \e[0m");
	ft_printf("\e[1;37mat [%d:%d]\n", index, place_in_str);
	ft_printf("\t%s\e[0m\n", input->current_str);
	ft_printf("\t\e[1;36m%s\e[0m\n", copy_str);
	ft_strdel(&copy_str);
	ft_strdel(&str_trim);
	return (ERROR);
}

char	*arrow_in_str(char *head_line, int arrow_place)
{
	int		i;
	char	*arrow_line;

	i = 0;
	arrow_line = ft_strdup(head_line);
	while (arrow_line[arrow_place] != '\0' && arrow_line[arrow_place] != ' '
										&& arrow_line[arrow_place] != '\t')
	{
		arrow_line[arrow_place] = '-';
		arrow_place++;
	}
	while (arrow_line[i] != '\0')
	{
		if (arrow_line[i] != '\t' && arrow_line[i] != '-')
			arrow_line[i] = ' ';
		i++;
	}
	return (arrow_line);
}