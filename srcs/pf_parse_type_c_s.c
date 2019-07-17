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


static char		*type_c_get_flags_width_modifier(char *buf, t_unit *unit, int buf_len)
{
	int		digits;
	int		digits_len;
	char	flags[buf_len];
	int		flags_len;

	flags_len = get_flags(flags, buf, "-");
	if (flags_len != FALSE)
	{
		unit->val.c.flag_minus = TRUE;
		buf += flags_len;
	}
	digits_len = get_digits(&digits, buf, ft_strlen(buf));
	if (digits_len != FALSE)
	{
		unit->val.c.width = digits;
		buf += digits_len;
	};
	if (*buf == 'l')
	{
		unit->val.c.modifier_l = TRUE;
		buf++;
	}
	return (buf);
}

void		parse_type_c(t_list **alst, char *buf, va_list args)
{
 	t_unit	unit;

 	ft_bzero(&unit, sizeof(t_unit));
 	buf = type_c_get_flags_width_modifier(buf, &unit, ft_strlen(buf));
	if (*buf != 'c')
	{
 		printf("error: %%c format wrong\n");
 		exit(0);
 	}
 	unit.type = TYPE_C;
 	if (unit.val.c.modifier_l == TRUE)
 	{
 		if (sizeof(wint_t) < sizeof(int))
 			unit.val.c.character = (wint_t)va_arg(args, int);
 		else
 			unit.val.c.character = va_arg(args, wint_t);
 	}
 	else
 		unit.val.c.character = va_arg(args, int);
 	unit_lstadd_bot(alst, &unit);
}

static char		*type_s_get_flags_and_width(char *buf, t_unit *unit, int buf_len)
{
	 	int		digits;
	 	int		digits_len;
	 	char	flags[buf_len];
	 	int		flags_len;

	 	flags_len = get_flags(flags, buf, "-");
	 	if (flags_len != FALSE)
	 	{
	 		unit->val.s.flag_minus = TRUE;
	 		buf += flags_len;
	 	}
		digits_len = get_digits(&digits, buf, ft_strlen(buf));
		if (digits != FALSE)
		{
			unit->val.s.width = digits;
			buf += digits_len;
		};
		return (buf);
}

static char		*type_s_get_precision_and_modifier(char *buf, t_unit *unit)
{
		int		digits;
		int		digits_len;

		if (*buf == '.')
		{
			buf++;
			digits_len = get_digits(&digits, buf, ft_strlen(buf));
			if (digits_len != FALSE)
			{
				unit->val.s.precision = digits;
				buf += digits_len;
			}
		}
		if (*buf== 'l')
		{
			unit->val.s.modifier_l = TRUE;
			buf++;
		}
		return (buf);
}

void		parse_type_s(t_list **alst, char *buf, va_list args)
{
	 	t_unit	unit;

	 	ft_bzero(&unit, sizeof(t_unit));
	 	buf = type_s_get_flags_and_width(buf, &unit, ft_strlen(buf));
	 	buf = type_s_get_precision_and_modifier(buf, &unit);
		if (*buf != 's')
		{
			printf("error: %%s format wrong\n");
			exit(0);
		}
	 	unit.type = TYPE_S;
	 	unit.val.s.string = va_arg(args, char *);
	 	if (unit.val.s.string == NULL)
	 		unit.val.s.string = "(null)";
	 	// if (unit.val.s.modifier_l == TRUE)
	 	// 	unit.val.s.character = va_arg(args, wint_t);
	 	// else
	 	// 	unit.val.c.character = va_arg(args, int);
	 	unit_lstadd_bot(alst, &unit);
}





/*
** one capsule is [flags][digits][.precision][modifier][conversion][literal],
** excepte the one in the begining, it contains only literal
**	Ex "literal%+4dliteral%fliteral" cut to capsule will be
**	 "literal|+4dliteral|fliteral"
**  PS: % are already replaced by '\0'
*/

