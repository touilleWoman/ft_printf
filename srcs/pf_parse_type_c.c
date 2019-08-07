#include "ft_printf.h"

static char		*type_c_get_flags(char *buf, t_unit *unit, int buf_len)
{
	char	flags[buf_len];
	int		flags_len;

	flags_len = get_flags(flags, buf, "-0+ #");
	if (flags_len)
	{
		(ft_strchr(flags, '-')) ? unit->val.c.flag_minus = TRUE : 0;
		if (ft_strchr(flags, ' '))
			ft_putstr_fd("warning : flag' ' is ignored with %c\n", 2);
		if (ft_strchr(flags, '+'))
			ft_putstr_fd("warning : flag'+' is ignored with %c\n", 2);
		if (ft_strchr(flags, '#'))
			ft_putstr_fd("warning : flag'#' is ignored with %c\n", 2);
		if (ft_strchr(flags, '0'))
			ft_putstr_fd("warning : flag'0' is ignored with %c\n", 2);
		buf += flags_len;
	}
	return (buf);
}

static char		*type_c_width_precision_handler(char *buf, t_unit *unit)
{
	int		digits;
	int		digits_len;

	digits = 0;
	digits_len = get_digits(&digits, buf, ft_strlen(buf));
	if (digits_len)
	{
		unit->val.c.width = digits;
		buf += digits_len;
	}
	if (*buf == '.')
	{
		ft_putstr_fd("warning : precesion value is ignored with %c\n", 2);
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
	buf = type_c_width_precision_handler(buf, &unit);
	buf = type_c_get_modifier(buf, &unit);
	// if (*buf != 'c')
	// {
	// 	freelst_and_errormsg(*alst, "error: %c format wrong\n");
	// 	return (ERROR);
	// }
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
	buf = type_c_width_precision_handler(buf, &unit);
	buf = type_c_get_modifier(buf, &unit);
	unit.type = TYPE_C;
	unit.val.c.character = '%';
	// Width doesn't seem to be taken into account...
	// unit.val.c.width = 1;
	unit_lstadd_bot(alst, &unit);
	return (0);
}
