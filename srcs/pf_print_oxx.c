
#include "ft_printf.h"

static unsigned int		d_precision_handler(char *s, char *un_int,
														int precision)
{
	int		neg;
	int		dy_len;

	dy_len = ft_strlen(un_int);
	if (dy_len > precision)
		ft_strcpy(s, un_int);
	else
	{
		neg = ((*un_int == '-') ? 1 : 0);
		s[precision + neg] = '\0';
		ft_memset(s, '0', precision + neg);
		if (neg == 1)
			s[0] = '-';
		ft_strncpy(s + precision + neg - dy_len + neg, un_int + neg, dy_len - neg);
		dy_len = precision + neg;
	}
	return (dy_len);
}

static void				sub_d_width_handler(char *s, int dy_len, t_unit *unit, int width)
{
	char 	s_keep[dy_len + 1];
	int 	mark;

	ft_strcpy(s_keep, s);
	mark = 0;
	if (unit->val.oxx.flag_zero == TRUE && unit->val.oxx.precision == 0)
	{
		ft_memset(s, '0', width);
		if (*s_keep == '-' || *s_keep == '+') 
		{
			s[0] = s_keep[0];
			mark = 1;
		}
		ft_strncpy(s + width + mark - dy_len, s_keep + mark, dy_len - mark);
	}
	else
	{
		ft_memset(s, ' ', width);
		ft_strncpy(s + width - dy_len, s_keep , dy_len);
	}
}

/*
**		flag '0' is ignored when flag '-' or precision present"
*/

static unsigned int		d_width_handler(char *s, int dy_len, t_unit *unit, int width)
{


	if (width <= dy_len)
		return (dy_len);
	if (unit->val.oxx.flag_minus == TRUE)
		ft_memset(s + dy_len, ' ', width - dy_len);
	else
		sub_d_width_handler(s, dy_len, unit, width);
	s[width] = '\0';
	return(width);
}

/*
** 		flag ' ' is ignored when flag '+' is present"
*/

static unsigned int		d_flag_plus_and_blank_handler(char *s, int dy_len, t_unit *unit)
{
	unsigned int 	i;

	if (unit->val.oxx.flag_plus == FALSE && unit->val.oxx.flag_blank == FALSE)
		return (dy_len);
	i = dy_len + 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	if (unit->val.oxx.flag_plus == TRUE)
		s[0] = '+';
	else if (unit->val.oxx.flag_blank == TRUE)
		s[0] = ' ';

	return (dy_len + 1);
}

/*
** 		dy_len is initialted at the lenth of un_int,
**		it will change depending on precision, width, then flags
*/

int				print_oxx(int fd, t_unit *unit)
{
	char			*un_int;
	unsigned int	dy_len;
	char			s[unit->val.oxx.precision + unit->val.oxx.precision + 30];

	un_int = pf_itoa_base(unit->val.oxx.un_int);
	dy_len = d_precision_handler(s, un_int, unit->val.oxx.precision);
	free(un_int);
	un_int = NULL;
	if (unit->val.oxx.un_int >= 0)
		dy_len = d_flag_plus_and_blank_handler(s, dy_len, unit);
	dy_len = d_width_handler(s, dy_len, unit, unit->val.oxx.width);
	ft_putstr_fd(s, fd);
	return (dy_len);
}
