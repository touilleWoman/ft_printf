/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:36:10 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/27 14:36:13 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


static void				sub_f_width_handler(char *s, int dy_len, t_unit *unit, int width)
{
	char 	s_keep[dy_len + 1];
	int		mark;

	ft_strcpy(s_keep, s);
	mark = 0;
	if (unit->val.f.flag_zero == TRUE)
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

static unsigned int		f_width_handler(char *s, int dy_len, t_unit *unit, int width)
{
	if (width <= dy_len)
		return (dy_len);
	if (unit->val.f.flag_minus == TRUE)
		ft_memset(s + dy_len, ' ', width - dy_len);
	else
		sub_f_width_handler(s, dy_len, unit, width);
	s[width] = '\0';
	return(width);
}

/*
** 		flag ' ' is ignored when flag '+' is present"
*/

static unsigned int		f_flag_plus_and_blank_handler(char *s, int dy_len, t_unit *unit)
{
	unsigned int 	i;

	if (unit->val.f.flag_plus == FALSE && unit->val.f.flag_blank == FALSE)
		return (dy_len);
	i = dy_len + 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	if (unit->val.f.flag_plus == TRUE)
		s[0] = '+';
	else if (unit->val.f.flag_blank == TRUE)
		s[0] = ' ';
	return (dy_len + 1);
}

/*
** 		dy_len is initialted at the lenth of integer,
**		it will change depending on precision, width, then flags
*/

long double	round_fractional_part(long double frac, int precision)
{
	int			i;
	long double	round_val;
	long double keep_frac;

	keep_frac = frac;
	if (precision <= 0)
		precision = 6;
	i = 0;
	while (i < precision + 1)
	{
		frac = frac * 10;
		i++;
	}
	if (((long int)frac) % 10 < 5)
		return (keep_frac);
	i = 0;
	round_val = 1.0;
	while (i < precision)
	{
		round_val = round_val * 0.1;
		i++;
	}
	return (keep_frac + round_val);
}

long double	pf_double_abs(long double nbr)
{
	return (nbr >= 0 ? nbr : -nbr);
}

void		pf_dtoa(long double nbr, int precision, char *buf)
{
	int			posi;
	long double frac_part;
	char		*str_int_part;
	int 		count;

	count = (precision > 0 ? precision : 6);
	str_int_part = ft_itoa((long long)nbr);
	frac_part = pf_double_abs(nbr - (long long)nbr);
	frac_part = round_fractional_part(frac_part, precision);
	ft_strcpy(buf, str_int_part);
	free(str_int_part);
	str_int_part = NULL;
	posi = ft_strlen(buf);
	buf[posi] = '.';
	while (count > 0)
	{
		posi++;
		buf[posi] =(int)(frac_part * 10) + '0';
		frac_part = frac_part * 10 - (int)(frac_part * 10);
		count--;
	}
	posi++;
	buf[posi] = '\0';
}



int				print_f(int fd, t_unit *unit)
{
	unsigned int	dy_len;
	char			s[unit->val.f.precision + unit->val.f.precision + 30];

	pf_dtoa(unit->val.f.doub, unit->val.f.precision, s);
	dy_len = ft_strlen(s);
	if (unit->val.f.doub >= 0)
		dy_len = f_flag_plus_and_blank_handler(s, dy_len, unit);
	dy_len = f_width_handler(s, dy_len, unit, unit->val.f.width);
	ft_putstr_fd(s, fd);
	return (dy_len);
}
