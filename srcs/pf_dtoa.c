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

static long long			round_int_part(long double nbr)
{
	long long		int_part;

	if (((long long)(nbr * 10.0)) % 10 < 5)
		int_part = (long long)nbr;
	else
		int_part = ((long long)nbr) + 1;
	return (int_part);
}

static long double			round_fractional_part(long double frac, int preci)
{
	int			i;
	long double	round_val;
	long double keep_frac;

	keep_frac = frac;
	i = 0;
	while (i < preci + 1)
	{
		frac = frac * 10;
		i++;
	}
	if (((long int)frac) % 10 < 5)
		return (keep_frac);
	i = 0;
	round_val = 1.0;
	while (i < preci)
	{
		round_val = round_val * 0.1;
		i++;
	}
	return (keep_frac + round_val);
}

static void					write_fractionl_on_buf(char *buf, long double nbr,
							int precision, int posi)
{
	long double frac_part;

	buf[posi] = '.';
	frac_part = nbr - (long long)nbr;
	frac_part = round_fractional_part(frac_part, precision);
	while (precision > 0)
	{
		posi++;
		buf[posi] = (int)(frac_part * 10) + '0';
		frac_part = frac_part * 10 - (int)(frac_part * 10);
		precision--;
	}
	posi++;
	buf[posi] = '\0';
}

void						pf_dtoa(long double nbr, int precision,
							char *buf, t_bool flag_hash)
{
	int				posi;
	long long		int_part;

	precision = (precision == 0 ? 6 : precision);
	if (precision == PRECISION_NULL)
		int_part = round_int_part(nbr);
	else
		int_part = (long long)nbr;
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
		write_fractionl_on_buf(buf, nbr, precision, posi);
}
