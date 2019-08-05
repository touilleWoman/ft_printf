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
		if (base == 16 && unit->val.oxx.sub_type == TYPE_X_MAJ)
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'A'- 10);
		else
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'a'- 10);
		nbr = nbr / base;
	}
	return (ft_strdup(buf + posi));
}

int				print_p(int fd, t_unit *unit)
{
	char	*s;
	int		len;

	s = pf_itoa_base(unit->val.p.pointer, 16, unit);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(s, fd);
	len = ft_strlen(s) + 2;
	free (s);
	s = NULL;
	return (len);
}
