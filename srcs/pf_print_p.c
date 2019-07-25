/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:58:57 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/23 18:59:01 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char		*pf_itoa_base(uintmax_t nbr, int base, t_unit *unit)
{
	int		posi;
	char	buf[100];

	posi_handler = 0;
	posi = 99;
	buf[posi] = '\0';
	if (nbr == 0)
	{
		posi--;
		buf[posi] = '0';
	}
	while (nbr > 0 )
	{
		posi--;
		if (base == 16 && unit->type.val.oxx.x_majusclue == TRUE)
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'A'- 10);
		else
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'a'- 10);
		nbr = nbr / base;
	}
	if ((unit->type == TYPE_P) || (base == 16 && unit->type == TYPE_OXX &&  unit->val.oxx.flag_hash == TRUE))
	{
		posi--;
		if (unit->val.oxx.x_majuscule == TRUE)
			buf[posi] = 'X';
		else
			buf[posi] = 'x';
		posi--;
		buf[posi] = '0';
	}
	if (base == 8 && unit->val.oxx.flag_hash == TRUE)
	{
		posi--;
		buf[posi] = '0'; 
	}
	return (ft_strdup(buf + 99 - posi));
}


int				print_p(int fd, t_unit *unit)
{
	char	*s;
	int		len;

	s = pf_itoa_base(unit->val.p.pointer, 16, unit);
	ft_putstr_fd(s, fd);
	len = ft_strlen(s);
	free (s);
	s = NULL;
	return (len);
}
