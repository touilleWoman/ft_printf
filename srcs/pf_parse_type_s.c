
#include "ft_printf.h"


static char		*type_s_get_flags_and_width(char *buf,
	t_unit *unit, int buf_len)
{
	int		digits;
	int		digits_len;
	char	flags[buf_len];
	int		flags_len;

	flags_len = get_flags(flags, buf, "-");
	if (flags_len)
	{
		unit->val.s.flag_minus = TRUE;
		buf += flags_len;
	}
	digits = 0;
	digits_len = get_digits(&digits, buf, ft_strlen(buf));
	if (digits_len)
	{
		unit->val.s.width = digits;
		buf += digits_len;
	}
	return (buf);
}

static char		*type_s_get_precision_and_modifier(char *buf, t_unit *unit)
{
	int		digits;
	int		digits_len;

	digits = 0;
	if (*buf == '.')
	{
		buf++;
		if ((digits_len = get_digits(&digits, buf, ft_strlen(buf))))
		{
			unit->val.s.precision = digits;
			buf += digits_len;
		}
	}
	if (*buf == 'l')
	{
		unit->val.s.modifier_l = TRUE;
		buf++;
	}
	return (buf);
}

int			parse_s(t_list **alst, char *buf, va_list args)
{
	t_unit	unit;

	ft_bzero(&unit, sizeof(t_unit));
	buf = type_s_get_flags_and_width(buf, &unit, ft_strlen(buf));
	buf = type_s_get_precision_and_modifier(buf, &unit);
	if (*buf != 's')
	{
		freelst_and_errormsg(*alst, "error: %s format wrong\n");
		return (ERROR);
	}
	unit.type = TYPE_S;
	if ((unit.val.s.string = va_arg(args, char *)) == NULL)
		unit.val.s.string = "(null)";
	unit_lstadd_bot(alst, &unit);
	return (0);
}