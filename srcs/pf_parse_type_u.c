/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_type_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:37:37 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/27 13:37:41 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*type_u_get_flags_and_width(char *buf, t_unit *unit, int buf_len)
{
	int		digits;
	int		digits_len;
	char	flags[buf_len];
	int		flags_len;

 	if ((flags_len = get_flags(flags, buf, "-0+ #")))
	{
		(ft_strchr(flags, '-')) ? unit->val.u.flag_minus = TRUE : 0;
		(ft_strchr(flags, '0')) ? unit->val.u.flag_zero = TRUE : 0;
		if (ft_strchr(flags, ' '))
			ft_putstr_fd("%u doesn't accept flag' '\n", 2);
		if (ft_strchr(flags, '+'))
			ft_putstr_fd("%u doesn't accept flag'+'\n", 2);
		if (ft_strchr(flags, '#'))
			ft_putstr_fd("%u doesn't accept flag'#'\n", 2);
		buf += flags_len;
	}
 	digits = 0;
	if ((digits_len = get_digits(&digits, buf, ft_strlen(buf))))
	{
		unit->val.u.width = digits;
		buf += digits_len;
	}
	return (buf);
}

static char		*type_u_get_precision(char *buf, t_unit *unit)
{
		int		digits;
		int		digits_len;

		digits = 0;
		if (*buf == '.')
		{
			buf++;
			digits_len = get_digits(&digits, buf, ft_strlen(buf));
			if (digits_len)
			{
				unit->val.u.precision = digits;
				buf += digits_len;
			}
		}
		return (buf);
}

static char		*type_u_get_modifier(char *buf, t_unit *unit)
{
	if (*buf == 'l' && buf[1] == 'l')
	{
		unit->val.u.modifier = MD_LL;
		buf += 2;
	}
	else if (*buf == 'h' && buf[1] == 'h')
	{
		unit->val.u.modifier = MD_HH;
		buf += 2;
	}
	else if (*buf == 'l')
	{
		unit->val.u.modifier= MD_L;
		buf++;
	}
	else if (*buf == 'h')
	{
		unit->val.u.modifier= MD_H;
		buf++;
	}
	return (buf);
}

int			parse_u(t_list **alst, char *buf, va_list args)
{
	t_unit	unit;

	ft_bzero(&unit, sizeof(t_unit));
	buf = type_u_get_flags_and_width(buf, &unit, ft_strlen(buf));
	buf = type_u_get_precision(buf, &unit);
	buf = type_u_get_modifier(buf, &unit);
	if (*buf != 'u')
	{
		freelst_and_errormsg(*alst, "error : %u format wrong\n");
		return (ERROR);
	}
	unit.type = TYPE_U;
	if (unit.val.u.modifier == MD_LL)
		unit.val.u.un_int = va_arg(args,  unsigned long long);
	else if (unit.val.u.modifier == MD_L)
		unit.val.u.un_int = va_arg(args, unsigned long);
	else if (unit.val.u.modifier == MD_HH)
		unit.val.u.un_int = (unsigned char)va_arg(args, unsigned int);
	else if (unit.val.u.modifier == MD_H)
		unit.val.u.un_int =(unsigned short)va_arg(args, unsigned int);
	else
		unit.val.u.un_int =va_arg(args, unsigned int);
	unit_lstadd_bot(alst, &unit);
	return (0);
}