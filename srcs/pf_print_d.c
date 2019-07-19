/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:13:40 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/17 18:13:42 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 		warning: flag ' ' is ignored when flag '+' is present"
**		warning: flag '0' is ignored when flag '-' is present"
*/

static char		*deal_with_precision(char *str_int, unsigned int *print_nb, unsigned int precision)
{
	char *ret;

	if (*print_nb >= precision)
		return (str_int);
	ret = ft_memalloc(precision + 1);
	ft_memset(ret, '0', precision - (*print_nb));
	ft_strncpy(ret + precision - (*print_nb), str_int, *print_nb);
	free(str_int);
	str_int = NULL;
	*print_nb = precision;
	return (ret);
}

int				print_d(t_unit *unit)
{
	char	*str_int;
	unsigned int	print_nb;
	char	s[unit->val.d.width];
	int		step;

	step = 0;
	str_int = ft_itoa(unit->val.d.integer);
	print_nb = ft_strlen(str_int);
	str_int = deal_with_precision(str_int, &print_nb, unit->val.d.precision);
	if (unit->val.d.width > print_nb)
	{
		ft_memset(s, ' ', unit->val.d.width);
		if (unit->val.d.flag_minus == FALSE)
		{
			if (unit->val.d.flag_zero == TRUE)
			{
				ft_memset(s, '0', unit->val.d.width);
				ft_strncpy((s +  unit->val.d.width - print_nb), str_int, print_nb);
				if (unit->val.d.flag_plus == TRUE)
					*s = '+';
				else if (unit->val.d.flag_blank == TRUE)
					*s = ' ';
			}
			else
			{
				ft_strncpy((s +unit->val.d.width - print_nb), str_int, print_nb);
				if (unit->val.d.flag_plus == TRUE)
					s[unit->val.d.width - print_nb - 1] = '+';
				else if (unit->val.d.flag_blank == TRUE)
					s[unit->val.d.width - print_nb - 1] = ' ';
			}
		}
		else
		{
			if (unit->val.d.flag_plus == TRUE)
			{
				*s = '+';
				step = 1;
			}
			else if (unit->val.d.flag_blank == TRUE)
			{
				*s = ' ';
				step = 1;
			}
			ft_strncpy(s + step, str_int, print_nb);
		}
		write(1, s, unit->val.d.width);
		return( unit->val.d.width);
	}
	if (unit->val.d.flag_plus == TRUE)
	{
		write(1, "+", 1);
		print_nb++;
	}
	else if (unit->val.d.flag_blank == TRUE)
	{
		write(1, " ", 1);
		print_nb++;
	}
	write(1, str_int, print_nb);
	return (print_nb);
}

