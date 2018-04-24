#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myprosku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 16:33:12 by myprosku          #+#    #+#              #
#    Updated: 2017/10/28 16:33:12 by myprosku         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_strndup.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_intlen.c ft_isspace.c ft_swap.c \
	af_per_doxu.c af_per_sc.c alignment_p.c alignment_s.c find_flags.c \
	flag_hljz.c format_c.c format_di_jz.c format_di.c format_dig.c \
	format_o_jz.c format_o.c format_p.c format_s.c format_u_jz.c \
	format_s.c format_u.c format_x_jz.c format_x.c ft_aligment_sharp.c \
	ft_aligment_wchar.c ft_alignment_di.c ft_alignment.c ft_dot.c \
	ft_itoa_base.c ft_itoa_intmax.c \
	ft_printf.c putchar_int.c ft_putnbr_u.c ft_putstr_u.c putstr_int.c \
	ft_zero.c print_addres.c unsigned_itoa.c zero_flags.c \
	format_b.c format_b_jz.c get_next_line.c ft_min_max.c

HEADER = libft.h

OFL = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra 

$(NAME):
	@gcc $(FLGS) -c $(SRC) -I.$(HEADER)
	@ar rc $(NAME) $(OFL)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OFL)

fclean: clean
	@rm -f $(NAME)

re: fclean all