/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:25:51 by jleblond          #+#    #+#             */
/*   Updated: 2019/08/21 11:25:55 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static long long			round_int_part(long double nbr)
// {
// 	long long		int_part;

// 	if (((long long)(nbr * 10.0)) % 10 < 5)
// 		int_part = (long long)nbr;
// 	else
// 		int_part = ((long long)nbr) + 1;
// 	return (int_part);
// }

static void				round(long double nbr, int preci, char *buf, t_bool flag_hash)
{
	int			i;
	uintmax_t	frac_to_int;
	uintmax_t	pw;
	uintmax_t	int_part;
	int			len;

	i = 0;
	pw = 1;
	while (i < preci + 1)
	{
		pw = pw * 10;
		i++;
	}
	int_part = (uintmax_t)nbr;
	frac_to_int = ((uintmax_t)((nbr - int_part) * pw));
	// frac_to_int = ((uintmax_t)(nbr * pw)) % pw;
	// printf("111nbr:%Lf, int_part%ju, frac_to_int %ju\n", nbr, int_part, frac_to_int);
	if (frac_to_int % 10 >= 5)
		frac_to_int = frac_to_int + 10;
	int_part = int_part + frac_to_int / pw;
	frac_to_int = frac_to_int % pw;
	// printf("nbr:%Lf, int_part%ju, frac_to_int %ju\n", nbr, int_part, frac_to_int);
	pf_itoa_base(int_part, 10, NULL, buf);
	len = ft_strlen(buf);
	if (preci == 0 && flag_hash == FALSE)
		return ;
	else if (preci == 0 && flag_hash == TRUE)
	{
		buf[len] = '.';
		buf[len + 1] = 0;
		return ;
	}
	buf[len] = '.';
	buf += len + 1;
	while (pw > 10)
	{
		pw = pw / 10;
		*buf = frac_to_int / pw + '0';
		buf++;
		frac_to_int = frac_to_int % pw;
	}
	*buf = 0;
}

// static void					write_fractionl_on_buf(char *buf, long double nbr,
// 							int precision, int posi)
// {
// 	buf[posi] = '.';

// 	// printf("nbr:%Lf, frac:%LF, precision%d\n", nbr, frac_part, precision);
// 	while (precision > 0)
// 	{
// 		posi++;
// 		buf[posi] = ((unsigned long long)(nbr * 10.0)) % 10 + '0';
// 		// printf("buf:%c, int:%lld\n", buf[posi], ((unsigned long long)(nbr * 10.0)) % 10 );

// 		nbr = nbr * 10.0;
// 		precision--;
// 	}
// 	posi++;
// 	buf[posi] = '\0';
// }

int							is_inf_or_nan(long double nbr, char *buf)
{
	if (pf_isinf(nbr))
	{
		ft_strcpy(buf, "inf");
		return (TRUE) ;
	}
	if (pf_isnan(nbr))
	{
		ft_strcpy(buf, "nan");
		return (TRUE) ;
	}
	return (FALSE);
}

void						pf_dtoa(long double nbr, int precision,
							char *buf, t_bool flag_hash)
{
	// int				posi;
	// char			buff[60];

	if (is_inf_or_nan(nbr, buf))
		return ;
	precision = (precision == 0 ? 6 : precision);
	if (precision == PRECISION_NULL)
		round(nbr, 0, buf, flag_hash);
	else
		round(nbr, precision, buf, flag_hash);
	// posi = ft_strlen(buf);
	// if (precision == PRECISION_NULL && flag_hash == FALSE)
	// 	return ;
	// else if (precision == PRECISION_NULL && flag_hash == TRUE)
	// {
	// 	buf[posi] = '.';
	// 	buf[posi + 1] = 0;
	// }
}
