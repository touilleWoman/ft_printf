/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_type_c_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:23:31 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/14 16:23:41 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




void		pf_parse_type_c(t_list **alst, char *buf, va_list args)
{
 	t_unit	unit;
 	int		i;
 	int		digits;
 	int		digits_len;

 	i = 0;
 	ft_bzero(&unit, sizeof(t_unit));
	if (buf[0] == '-')
	{
		unit.val.c.flag_minus = TRUE;
		i++;
	}
	digits = get_digits(buf + i, &digits_len);
	if (digits != FALSE)
	{
		unit.val.c.width = digits;
		i += digits_len;
	};
	if (buf[i] == 'l')
	{
		unit.val.c.modifier_l = TRUE;
		i++;
	}
	if (buf[i] == 'c')
	{
		unit.type = TYPE_C;
		if (unit.val.c.modifier_l == TRUE)
			unit.val.c.character = va_arg(args, wint_t);
		else
			unit.val.c.character = va_arg(args, int);
		unit_lstadd_bot(alst, &unit);
		return ;
	}
 	printf("error: %%c format wrong\n");
 	exit(0);
}

void		pf_parse_type_s(t_list **alst, char *buf, va_list args)
{
	 	t_unit	unit;
	 	int		i;
	 	int		digits;
	 	int		digits_len;

	 	i = 0;
	 	ft_bzero(&unit, sizeof(t_unit));
		if (buf[0] == '-')
		{
			unit.val.s.flag_minus = TRUE;
			i++;
		}
		digits = get_digits(buf + i, &digits_len);
		if (digits != FALSE)
		{
			unit.val.s.width = digits;
			i += digits_len;
		};
		if (buf[i] == '.')
		{
			i++;
			digits = get_digits(buf + i, &digits_len);
			if (digits != FALSE)
			{
				unit.val.s.precision = digits;
				i += digits_len;
			}
		}
		if (buf[i] == 'l')
		{
			unit.val.s.modifier_l = TRUE;
			i++;
		}
		if (buf[i] == 's')
		{
			unit.type = TYPE_S;
			unit.val.s.string = ft_strdup(va_arg(args, char *));
			// if (unit.val.s.modifier_l == TRUE)
			// 	unit.val.s.character = va_arg(args, wint_t);
			// else
			// 	unit.val.c.character = va_arg(args, int);
			unit_lstadd_bot(alst, &unit);
			return ;
		}
	 	printf("error: %%s format wrong\n");
	 	exit(0);
}





/*
** one capsule is [flags][digits][.precision][modifier][conversion][literal],
** excepte the one in the begining, it contains only literal
**	Ex "literal%+4dliteral%fliteral" cut to capsule will be
**	 "literal|+4dliteral|fliteral"
**  PS: % are already replaced by '\0'
*/

