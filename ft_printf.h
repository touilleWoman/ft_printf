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


typedef	union		u_conversion_union
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	o;
	unsigned int	u;
	unsigned int	x;
	unsigned int	mj_x;
	float			f;
}					t_conversion_union;

typedef struct  	s_unit
{
	char					*before;
	char					*after;
	t_conversion_union		type;
}					t_unit;

int		parse_string(const char *str, va_list args);
int		count_true_percentage(const char*str);



#endif