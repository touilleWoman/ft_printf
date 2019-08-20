#include "ft_printf.h"

static char		*type_c_get_flags(char *buf, t_unit *unit, int buf_len)
{
	char	flags[buf_len];
	int		flags_len;

	flags_len = get_flags(flags, buf, "-0+ #");
	if (flags_len)
	{
		(ft_strchr(flags, '-')) ? unit->val.c.flag_minus = TRUE : 0;
		// if (ft_strchr(flags, ' '))
		// 	ft_putstr_fd("format error : flag' ' is ignored with %c\n", 2);
		// if (ft_strchr(flags, '+'))
		// 	ft_putstr_fd("format error : flag'+' is ignored with %c\n", 2);
		// if (ft_strchr(flags, '#'))
		// 	ft_putstr_fd("format error : flag'#' is ignored with %c\n", 2);
		// if (ft_strchr(flags, '0'))
		// 	ft_putstr_fd("format error : flag'0' is ignored with %c\n", 2);
		buf += flags_len;
	}
	return (buf);
}

static char		*type_c_width_precision_handler(char *buf, t_unit *unit, va_list args)
{
	int		digits;
	int		digits_len;

	digits = 0;
	digits_len = get_digits_or_star(&digits, buf, ft_strlen(buf), args);
	if (digits_len)
	{
		unit->val.c.width = digits;
		buf += digits_len;
	}
	if (*buf == '.')
	{
		buf++;
		while (ft_isdigit(*buf))
			buf++;
	}
	return (buf);
}


static char		*type_c_get_modifier(char *buf, t_unit *unit)
{
	if (*buf == 'l')
	{
		unit->val.c.modifier_l = TRUE;
		buf++;
	}
	return (buf);
}

int				parse_c(t_list **alst, char *buf, va_list args)
{
	t_unit	unit;

	ft_bzero(&unit, sizeof(t_unit));
	buf = type_c_get_flags(buf, &unit, ft_strlen(buf));
	buf = type_c_width_precision_handler(buf, &unit, args);
	buf = type_c_get_modifier(buf, &unit);
	if (*buf != 'c')
		return (ERROR);
	unit.type = TYPE_C;
	if (unit.val.c.modifier_l == TRUE)
		unit.val.c.character = (wchar_t)va_arg(args, wint_t);
	else
		unit.val.c.character = (char)va_arg(args, int);
	unit_lstadd_bot(alst, &unit);
	return (0);
}

int				parse_percent(t_list **alst, char *buf, va_list args)
{
	t_unit	unit;

	ft_bzero(&unit, sizeof(t_unit));
	buf = type_c_get_flags(buf, &unit, ft_strlen(buf));
	buf = type_c_width_precision_handler(buf, &unit, args);
	buf = type_c_get_modifier(buf, &unit);
	unit.type = TYPE_C;
	unit.val.c.character = '%';
	unit_lstadd_bot(alst, &unit);
	return (0);
}
