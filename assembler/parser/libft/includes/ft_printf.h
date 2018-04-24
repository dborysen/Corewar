/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:21:06 by klee              #+#    #+#             */
/*   Updated: 2018/04/20 13:42:57 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_prt
{
	char			*type;
	char			*flags;
	char			*size;
	void			(*f)();
	struct s_prt	*next;
}					t_prf;

typedef	struct		s_flg
{
	char			*flags;
	int				length;
	int				accuracy;
	char			*size;
	char			*type;
}					t_flgs;

int					get_next_line(const int fd, char **line);
char				*f_srch(char *str, va_list ap);
int					ft_printf(char *format, ...);
void				f_join_free(char **str, char *src);
void				f_join_free_b(char **str, char *src);
void				f_wchar_t_2048(char **res, intmax_t n);
void				f_wchar_t(char **res, intmax_t n);
void				f_type_s(char **res, va_list ap);
void				f_type_c(char **res, va_list ap);
void				f_type_bc(char **res, va_list ap);
void				f_type_prcn(char **res, va_list ap);
void				recursio_i_a(char **str, unsigned long long i, int base);
char				*f_itoa_base_a(unsigned long long int n, int base);
t_prf				*f_listnew(char *type, char \
					*flags, char *size, void (*f)());
void				del_prf(t_prf **in);
char				*str_to_upper(char *in);
void				f_type_p(char **res, unsigned long long input);
void				f_type_d(char **res, intmax_t input);
void				f_type_bx(char **res, intmax_t input);
void				f_type_o(char **res, intmax_t input);
void				f_type_x(char **res, intmax_t input);
void				f_type_u(char **res, unsigned long long input);
void				f_type_nope(char **res, va_list ap);
void				f_listadd_t(t_prf **src, t_prf *new);
t_prf				*type_list(void);
intmax_t			f_size_nbr(t_flgs *input, va_list ap);
int					ft_one_equ(char *str1, char *str2);
char				*f_strnew_null(int i);
char				*f_strnew_spc(int i);
void				f_accurancy_dop(t_flgs *input, intmax_t *n, char **res);
void				f_accurancy(t_flgs *input, t_prf *new, char **res);
void				f_length_dop(t_flgs *input, char **res);
void				f_length(t_flgs *input, t_prf *new, char **res);
void				f_flags(t_flgs *input, t_prf *new, char **res);
int					find_func(t_flgs *input, char **res, va_list ap);
t_flgs				*flag_list(void);
void				del_flag_list(t_flgs **fnt);
int					f_len_nbr(int nbr);
void				c_jf(char **str, char in);
int					f_a_l_s(char *str, t_flgs **fnt);
t_flgs				*analys_str(char **str, char **res);
void				f_type_bd(char **res, intmax_t input);
intmax_t			dop_size_nbr(t_flgs *input, va_list ap);
intmax_t			dop_size_nbr2(t_flgs *input, va_list ap);
void				f_flag_plus(t_flgs *input, t_prf *new, char **res);
void				f_flag_sps(t_flgs *input, t_prf *new, char **res);
void				f_accurancy_dop_length(t_flgs *input,\
					intmax_t *n, char **res);
void				f_accurancy_length(t_flgs *input,\
					t_prf *new, char **res);
void				f_type_bs(char **res, va_list ap);
void				f_type_sc(t_flgs *input, t_prf *new,\
					char **res, va_list ap);
void				if_type_z(t_flgs *input, t_prf *new, \
					char **res, intmax_t *n);
void				f_type_bb(char **res, unsigned long long input);
void				f_binar(char **res, unsigned long long input);

#endif
