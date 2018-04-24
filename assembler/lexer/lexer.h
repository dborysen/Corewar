/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:56:59 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/19 15:57:00 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
#include "../op.h"
#include "ft_printf/ft_printf.h"

# define ERROR -1
# define OK 0
# define TRUE 0
# define FALSE -1

/*
** FINAL STATE TABLE STRUCTS
*/

typedef struct  s_func_list
{
    int                 (*f)(char);
    struct s_func_list  *next;
}               t_func_list;

typedef struct  s_tokens
{
    int             token;
    char            *current_str_piece;
    struct s_tokens *next;
}               t_tokens;

typedef struct  s_str_tokens
{
    t_tokens                *valid;
    char                    *current_str;
    struct  s_str_tokens    *next;
}               t_str_tokens;

/*
************************************
*/

typedef struct  s_data
{
    char            *data;
    struct s_data   *next;
}               t_data;

typedef struct  s_counters
{
    int state;
    int state_column;
    int i;
    int j;
}               t_counters;

void            find_tokens(char *str, t_tokens **tokens_list, t_func_list *state_funcs);
void            lexer(t_data *data_from_file, t_str_tokens **str_tokens);
int				read_data(t_data **champ_data);
void			new_node(t_data **head, char *line);
int				validation(t_data *champ_data);
void			free_list(t_data **head);
void			save_name_and_comment(t_data *data_from_file, int row_num);
void			free_twvo_dem_array(char **array);
int             rows_before_operation(t_data *data_from_file);
int             is_white_space(char c);
int             is_r_letter(char c);
int             is_letter(char c);
int             is_digit(char c);
int             is_proc(char c);
int             is_double_dot(char c);
int             is_comma(char c);
int             is_eol(char c);
int             is_hash(char c);
int             is_minus(char c);
void            fill_func_list(t_func_list **state_funcs);
void            add_func_in_list(t_func_list **state_funcs, int (*f)(char));
int             find_correct_state_column(char c, t_func_list *state_funcs);
void            free_func_list(t_func_list *state_funcs);
int             is_a_token(int num);
void            add_node_in_tokens_strings(t_str_tokens **str_tokens, char *str);
void            add_new_token_node(t_tokens **token_list, int token, char *token_str);
void            free_str_tokens(t_str_tokens **str_tokens);
void            free_tokens(t_tokens **tokens);

#endif