/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myprosku <myprosku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:55:47 by myprosku          #+#    #+#             */
/*   Updated: 2018/02/14 14:37:02 by myprosku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int				plus;
	int				space;
	int				sharp;
	int				alignment;
	int				minus;
	int				dot;
	int				zero;
	int				n_chr;
	int				h;
	int				l;
	int				j;
	int				z;
}					t_flags;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strlcat(char *dest, char *src, unsigned int size);
size_t				ft_strlen(char *str);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memset(void *b, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_swap(int *s1, int *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
char				*ft_strdup(char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_words_split(const char *s, char c, int *i);
char				*ft_strndup(const char *s1, size_t n);
int					ft_atoi(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isspace(char c);
int					ft_intlen(int n);
int					ft_count_words(const char *s, char c);
int					format_prints(const char *format,
									va_list arg, t_flags flags, int ret);
int					ft_printf(const char *format, ...);
char				*ft_itoa_base(int value, int base, char sixteen);
void				ft_putnbr_u(unsigned long long n);
void				print_float(double n, char *res, int afterpoint);
int					ft_print_address(void *address, t_flags flags);
char				*unsigned_itoa(unsigned long long value,
									int base, char sixteen);
void				rev(char *s, int len);
int					ft_putstr_u(unsigned char *s);
int					ft_intlen_u(unsigned long long n);
char				*ft_itoa_intmax(intmax_t n);
int					print_space(int *alignment, int len, t_flags flags);
int					ft_atoi(char *str);
int					ft_intlen(int n);
int					ft_isdigit(int c);
char				*ft_itoa(long long n);
int					ft_putchar_int(int c);
int					ft_putstr_int(char const *s);
char				*ft_strdup(char *src);
size_t				ft_strlen(char *str);
int					ft_isspace(char c);
void				zero_flags(t_flags *flags);
int					ft_dot_str(char *str, t_flags flags);
int					ft_dot_u(unsigned int u_tmp, t_flags flags);
int					dot_di(char *str, t_flags flags);
int					ft_zero_str(char *str, t_flags flags);
int					zero_di(char *str, t_flags flags);
int					ft_zero_u(unsigned int u_tmp, t_flags flags);
int					ft_aligment_str(char *str, t_flags flags);
int					ft_aligment_dip(char *str, t_flags flags);
int					ft_aligment_diz(char *str, t_flags flags);
int					ft_aligment_u(unsigned long long u_tmp, t_flags flags);
int					ft_aligment_p(void *v_tmp, t_flags flags);
int					ft_alignment_c(char tmp, t_flags flags);
int					ft_aligment_wchar(wchar_t *str, t_flags flags);
int					ft_aligment_str_sharp(char *str, t_flags flags);
int					ft_aligment_sharp_x(char *str, t_flags flags, char format);
int					ft_aligment_s(char *str, t_flags flags);
int					ft_zero_per(t_flags flags);
int					ft_zero_sharp_x(char *str, t_flags flags);
int					format_di(va_list arg, t_flags flags);
int					format_di_h(va_list arg, t_flags flags);
int					format_di_hh(va_list arg, t_flags flags);
int					format_di_l(va_list arg, t_flags flags);
int					format_di_ll(va_list arg, t_flags flags);
int					format_di_j(va_list arg, t_flags flags);
int					format_di_z(va_list arg, t_flags flags);
int					format_o(va_list arg, t_flags flags);
int					format_o_h(va_list arg, t_flags flags);
int					format_o_hh(va_list arg, t_flags flags);
int					format_o_l(va_list arg, t_flags flags);
int					format_o_ll(va_list arg, t_flags flags);
int					format_o_j(va_list arg, t_flags flags);
int					format_o_z(va_list arg, t_flags flags);
int					format_x(va_list arg, t_flags flags, char format);
int					format_x_h(va_list arg, t_flags flags, char format);
int					format_x_hh(va_list arg, t_flags flags, char format);
int					format_x_l(va_list arg, t_flags flags, char format);
int					format_x_ll(va_list arg, t_flags flags, char format);
int					format_x_z(va_list arg, t_flags flags, char format);
int					format_x_j(va_list arg, t_flags flags, char format);
int					format_u(va_list arg, t_flags flags);
int					format_u_h(va_list arg, t_flags flags);
int					format_u_hh(va_list arg, t_flags flags);
int					format_u_l(va_list arg, t_flags flags);
int					format_u_ll(va_list arg, t_flags flags);
int					format_u_j(va_list arg, t_flags flags);
int					format_u_z(va_list arg, t_flags flags);
int					format_s(va_list arg, t_flags flags);
int					format_s_l(va_list arg, t_flags flags);
int					format_c(va_list arg, t_flags flags);
int					format_c_l(va_list arg, t_flags flags);
int					format_p(va_list arg, t_flags flags);
int					format_b(va_list arg, t_flags flags);
int					format_b_h(va_list arg, t_flags flags);
int					format_b_hh(va_list arg, t_flags flags);
int					format_b_l(va_list arg, t_flags flags);
int					format_b_ll(va_list arg, t_flags flags);
int					format_b_j(va_list arg, t_flags flags);
int					format_b_z(va_list arg, t_flags flags);
int					format_per(t_flags flags);
int					ft_count_words(const char *s, char c);
void				ft_format_digit(const char ***format,
									t_flags **flags, va_list arg, int tmp);
void				ft_format_dot(const char ***format,
									t_flags **flags, va_list arg, int tmp);
void				ft_format_pssmz(const char ***format,
									t_flags **flags, va_list arg, int tmp);
void				flag_hljz(const char ***format, t_flags **flags);
int					af_per_d(va_list arg, t_flags flags, const char *format);
int					af_per_o(va_list arg, t_flags flags, const char *format);
int					af_per_x(va_list arg, t_flags flags, const char *format);
int					af_per_u(va_list arg, t_flags flags, const char *format);
int					af_per_s(va_list arg, t_flags flags, const char *format);
int					af_per_c(va_list arg, t_flags flags, const char *format);
int					af_per_b(va_list arg, t_flags flags, const char *format);
void				find_flags(const char **format,
								t_flags *flags, va_list arg);
int					parse_con(const char *format, va_list arg, t_flags flags);
int					ft_print_wchar(wchar_t c, t_flags flags);
int					ft_str_printw(wchar_t *str, t_flags flags);
int					ft_wstrlen(wchar_t *ws, int max);
int					ft_wcharlen(wchar_t ws, int max);
int					ft_zero_strwchar(wchar_t *str, t_flags flags);
int					ft_aligment_s_wchar(wchar_t *str, t_flags flags);
int					if_pl_sp(t_flags *flags, long long tmp);
int					check_format(char c);
int					get_next_line(const int fd, char **line);
int					ft_fnd_min(int a, int b);
int					ft_fnd_max(int a, int b);

#endif
