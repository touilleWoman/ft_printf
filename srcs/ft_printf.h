/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:11:51 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/04 10:11:55 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "pf_unit.h"
#include "libft.h"
#include <wchar.h>

#define PARSE_FUNS_NB 11
#define PRINT_FUNS_NB 8
#define ERROR -1
#define STD_OUT 1

typedef struct	s_parse_funs
{
	char		type;
	int			(*f)();
}				t_parse_funs;

typedef struct	s_print_funs
{
	t_unit_type	type;
	int			(*f)();
}				t_print_funs;


int			get_digits(int *digits, char *buf, int buf_len);
int			get_flags(char *flags, char *buf, char *valid_flags);


int				ft_printf(const char *restrict format, ...);
int		ft_vdprintf(int fd, const char * restrict format, va_list args);

//parse
t_list			*parse_string(const char *format, va_list args, int *r_format_ok);
t_list			*cut_to_capsule(char *s, int len, va_list args);
int				is_conversion(char c);
int				parse_c(t_list **alst, char *buf, va_list args);
int				parse_percent(t_list **alst, char *buf, va_list args);
int				parse_s(t_list **alst, char *buf, va_list args);
int				parse_d(t_list **alst, char *buf, va_list args);
int				parse_f(t_list **alst, char *buf, va_list args);
int				parse_p(t_list **alst, char *buf, va_list args);
int				parse_oxx(t_list **alst, char *buf, va_list args);
int				parse_u(t_list **alst, char *buf, va_list args);
int				parse_percentage(t_list **alst, char *buf, va_list args);


//print
int				print_ltr(int fd, t_unit *unit);
int				print_c(int fd, t_unit *unit);
int				print_s(int fd, t_unit *unit);
int				print_d(int fd, t_unit *unit);
int				print_p(int fd, t_unit *unit);
int				print_oxx(int fd, t_unit *unit);
int				print_u(int fd, t_unit *unit);
int				print_f(int fd, t_unit *unit);

char			*pf_itoa_base(uintmax_t nbr, int base, t_unit *unit);


#endif
