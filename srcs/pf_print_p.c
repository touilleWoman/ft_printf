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
	char	*str_p;
	int		len;
	char	s[unit->val.p.width + 30];
	int		width;

	width =  unit->val.p.width;
	ft_memset(s, ' ', width + 30);
	str_p = pf_itoa_base(unit->val.p.pointer, 16, unit);
	len = ft_strlen(str_p) + 2;
	if (width > len && unit->val.p.flag_minus == FALSE)
	{
		ft_strncpy(s + width - len, "0x", 2);
		ft_strncpy(s + width - len + 2, str_p, len - 2);
		s[width] = 0;
	}
	else
	{
		ft_strncpy(s, "0x", 2);
		ft_strncpy(s + 2, str_p, len - 2);
		if (width > len)
			s[width] = 0;
		else
			s[len] = 0;
	}
	ft_putstr_fd(s, fd);
	free (str_p);
	str_p = NULL;
	return(width > len ? width : len);


	// ft_putstr_fd("0x", fd);
	// ft_putstr_fd(str_p, fd);
	// len = ft_strlen(str_p) + 2;

	// return (len);
}
