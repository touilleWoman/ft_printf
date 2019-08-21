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

static long double			round(long double nbr, int preci)
{
	int			i;
	long double	round_val;
	long double keep_nbr;

	keep_nbr = nbr;
	i = 0;
	while (i < preci + 1)
	{
		nbr = nbr * 10.0;
		i++;
	}
	if (((long long)nbr) % 10 < 5)
		return (keep_nbr);
	i = 0;
	round_val = 1.0;
	while (i < preci)
	{
		round_val = round_val * 0.1;
		i++;
	}
	return (keep_nbr + round_val);
}

static void					write_fractionl_on_buf(char *buf, long double nbr,
							int precision, int posi)
{
	buf[posi] = '.';

	// printf("nbr:%Lf, frac:%LF, precision%d\n", nbr, frac_part, precision);
	while (precision > 0)
	{
		posi++;
		buf[posi] = ((unsigned long long)(nbr * 10.0)) % 10 + '0';
		// printf("buf:%c, int:%lld\n", buf[posi], ((unsigned long long)(nbr * 10.0)) % 10 );

		nbr = nbr * 10.0;
		precision--;
	}
	posi++;
	buf[posi] = '\0';
}

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
	int				posi;
	long long		int_part;
	long double		nbr_rounded;

	if (is_inf_or_nan(nbr, buf))
		return ;
	precision = (precision == 0 ? 6 : precision);
	if (precision == PRECISION_NULL)
		nbr_rounded = round(nbr, 0);
	else
		nbr_rounded = round(nbr, precision);
	int_part = (long long)nbr_rounded;
	pf_itoa_base(int_part, 10, NULL, buf);
	posi = ft_strlen(buf);
	if (precision == PRECISION_NULL && flag_hash == FALSE)
		return ;
	else if (precision == PRECISION_NULL && flag_hash == TRUE)
	{
		buf[posi] = '.';
		buf[posi + 1] = 0;
	}
	else
		write_fractionl_on_buf(buf, nbr_rounded, precision, posi);
}
