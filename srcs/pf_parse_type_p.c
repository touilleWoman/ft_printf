/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:00:14 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/23 10:00:28 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 	*type_p_flags_check(char *buf, int buf_len)
{
	char	flags[buf_len];
	int		flags_len;


 	if ((flags_len = get_flags(flags, buf, "+- 0#")))
	{
		ft_putstr("warning : 'p' conversion specifier doesn't take flags\n");
		buf += flags_len;
	}
	return (buf);
}

static char *type_p_width_precision_check(char *buf)
 {
	int		digits;
	int		digits_len;

 	digits = 0;
	if ((digits_len = get_digits(&digits, buf, ft_strlen(buf))))
	{
		ft_putstr("warning:'p' conversion specifier doesn't take width\n");
		buf += digits_len;
	}
	if (*buf == '.')
	{
		buf++;
		digits_len = get_digits(&digits, buf, ft_strlen(buf));
		if (digits_len)
		{
			ft_putstr("warning:'p' conversion specifier doesn't take precision\n");
			buf += digits_len;
		}
	}
	return (buf);
}

static char		*type_p_modifier_check(char *buf)
{
	if (*buf == 'l' && buf[1] == 'l')
	{
		ft_putstr("warning:'p' conversion specifier doesn't take 'll' modifier\n");
		buf += 2;
	}
	else if (*buf == 'h' && buf[1] == 'h')
	{
		ft_putstr("warning:'p' conversion specifier doesn't take 'hh' modifier\n");
		buf += 2;
	}
	else if (*buf == 'l')
	{
		ft_putstr("warning:'p' conversion specifier doesn't take 'l' modifier\n");
		buf++;
	}
	else if (*buf == 'h')
	{
		ft_putstr("warning:'p' conversion specifier doesn't take 'h' modifier\n");
		buf++;
	}
	return (buf);
}

int			parse_type_p(t_list **alst, char *buf, va_list args)
{
	t_unit	unit;

	ft_putstr("bbbbb:");
	ft_bzero(&unit, sizeof(t_unit));
	buf = type_p_flags_check(buf, ft_strlen(buf));
	buf = type_p_width_precision_check(buf);
	buf = type_p_modifier_check(buf);
	if (*buf != 'p')
	{
		freelst_and_errormsg(*alst, "error: %%p format wrong\n");
		return (ERROR);
	}
	unit.type = TYPE_P;
	unit.val.p.pointer = (uintmax_t)va_arg(args, void *);
	unit_lstadd_bot(alst, &unit);
	return (0);
}

