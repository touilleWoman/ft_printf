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
#include "./libft/libft.h"

typedef enum 		e_bool
{
	TRUE = 1,
	FALSE = 0,
}					t_bool;

typedef	enum 		e_conversion
{
	LITERAL = 0,
}					t_conversion;

typedef struct 		s_literal
{
	char			*text;
	int				len;
}					t_literal;

typedef	union		u_conversion_unit
{
	t_literal		ltr;
	// char			c;
	// char			*s;
	// void			*p;
	// int				d;
	// int				i;
	// unsigned int	o;
	// unsigned int	u;
	// unsigned int	x;
	// unsigned int	mj_x;
	// float			f;
}					t_conversion_unit;

typedef struct 					s_stock
{
		t_conversion_unit		unit;
		int						type;
}							t_stock;

char				*deal_with_double_percentage(const char*format, int *unit_nb, int *new_len);

t_stock		**parse_string(const char *format, int *unit_nb);



#endif