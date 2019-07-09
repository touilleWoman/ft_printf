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

#define FUNS_NB 2

typedef struct	s_ptr_funs
{
	char		symbol;
	int			(*f)();
}				t_ptr_funs;




char		*deal_with_double_percentage(const char*format, int *unit_nb, int *new_len);
t_list		*parse_string(const char *format, int *printed_nb, int *unit_nb);


#endif
