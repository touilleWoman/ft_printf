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

static char		*deal_with_precision(char *integer,
							unsigned int *print_nb,
							unsigned int precision)
{
	char *ret;

	if (*print_nb >= precision)
		return (integer);
	ret = ft_memalloc(precision + 1);
	ft_memset(ret, '0', precision - (*print_nb));
	ft_strncpy(ret + precision - (*print_nb), integer, *print_nb);
	free(integer);
	integer = NULL;
	*print_nb = precision;
	return (ret);
}

int				print_int_with_flagplus_or_blank(int fd, t_unit *unit,
												char *integer,
												int print_nb)
{
	if (unit->val.d.flag_plus == TRUE)
	{
		write(fd, "+", 1);
		print_nb++;
	}
	else if (unit->val.d.flag_blank == TRUE)
	{
		write(fd, " ", 1);
		print_nb++;
	}
	write(fd, integer, ft_strlen(integer));
	return (print_nb);
}



static int		create_buf_of_width_size_then_print(int fd, t_unit *unit,
							char *integer, int int_len, int width)
{
	char			s[width];
	int				step;

	ft_memset(s, ' ', width);
	step = 0;
	if (unit->val.d.flag_minus == FALSE)
	{
		if (unit->val.d.flag_zero == TRUE)
		{
			ft_memset(s, '0', width);
			ft_strncpy((s +  width - int_len), integer, int_len);
			if (unit->val.d.flag_plus == TRUE)
				*s = '+';
			else if (unit->val.d.flag_blank == TRUE)
				*s = ' ';
		}
		else
		{
			ft_strncpy((s +width - int_len), integer, int_len);
			if (unit->val.d.flag_plus == TRUE)
				s[width - int_len - 1] = '+';
			else if (unit->val.d.flag_blank == TRUE)
				s[width - int_len - 1] = ' ';
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
		ft_strncpy(s + step, integer, int_len);
	}
	write(fd, s, width);
	return (width);
}

/*
** 		print_nb is initialted at the lenth of integer,
**		it will change depending on precision, width, then flags
*/
int				print_d(int fd, t_unit *unit)
{
	char			*integer;
	unsigned int	print_nb;

	integer = ft_itoa(unit->val.d.integer);
	print_nb = ft_strlen(integer);
	integer = deal_with_precision(integer, &print_nb, unit->val.d.precision);
	if (unit->val.d.width > print_nb)
		print_nb = create_buf_of_width_size_then_print(fd, unit, integer, print_nb, unit->val.d.width);
	else
		print_nb = print_int_with_flagplus_or_blank(fd, unit, integer, print_nb);
	free(integer);
	integer = NULL;
	return (print_nb);
}
