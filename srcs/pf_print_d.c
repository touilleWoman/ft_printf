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
** 		flag ' ' is ignored when flag '+' is present"
**		flag '0' is ignored when flag '-' is present"
*/

static char		*d_precision_handler(char *integer,
							unsigned int *print_nb,
							unsigned int precision)
{
	char	*new;
	int		neg;

	if (*print_nb > precision)
		return (integer);
	neg = ((*integer == '-') ? 1 : 0);
	new = ft_memalloc(precision + neg + 1);
	ft_memset(new, '0', precision + neg);
	new[precision + neg] = '\0';
	if (neg == 1)
		new[0] = '-';
	ft_strncpy(new + precision + neg - (*print_nb) + neg, integer + neg, (*print_nb) - neg);
	free(integer);
	integer = NULL;
	*print_nb = precision + neg;
	return (new);
}

int				print_int_with_flagplus_or_blank(int fd, t_unit *unit,
												char *integer,
												int print_nb)
{
	if (unit->val.d.flag_plus == TRUE && unit->val.d.integer >= 0)
	{
		write(fd, "+", 1);
		print_nb++;
	}
	else if (unit->val.d.flag_blank == TRUE && unit->val.d.integer >= 0)
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
			if (unit->val.d.flag_plus == TRUE && unit->val.d.integer >= 0)
				s[width - int_len - 1] = '+';
			else if (unit->val.d.flag_blank == TRUE)
				s[width - int_len - 1] = ' ';
		}
	}
	else
	{
		if (unit->val.d.flag_plus == TRUE && unit->val.d.integer >= 0)
		{
			*s = '+';
			step = 1;
		}
		else if (unit->val.d.flag_blank == TRUE && unit->val.d.integer >= 0)
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
	integer = d_precision_handler(integer, &print_nb, unit->val.d.precision);
	if (unit->val.d.width > print_nb)
		print_nb = create_buf_of_width_size_then_print(fd, unit, integer, print_nb, unit->val.d.width);
	else
		print_nb = print_int_with_flagplus_or_blank(fd, unit, integer, print_nb);
	free(integer);
	integer = NULL;
	return (print_nb);
}
