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

void		pf_itoa_base(uintmax_t nbr, int base, t_unit *unit,
							char *str, int str_size)
{
	int		posi;
	char	buf[str_size];

	posi = str_size - 1;
	buf[posi] = '\0';
	if (nbr == 0)
	{
		posi--;
		buf[posi] = '0';
	}
	while (nbr > 0)
	{
		posi--;
		if (base == 16 && unit->val.oxx.sub_type == TYPE_X_MAJ)
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'A' - 10);
		else
			buf[posi] = nbr % base + ((nbr % base < 10) ? '0' : 'a' - 10);
		nbr = nbr / base;
	}
	ft_strcpy(str, buf + posi);
}

int			print_p(int fd, t_unit *unit)
{
	int		len;
	char	s[unit->val.p.width + 30];
	int		width;
	char	str_p[40];

	width = unit->val.p.width;
	ft_memset(s, ' ', width + 30);
	pf_itoa_base(unit->val.p.pointer, 16, unit, str_p, 40);
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
	return (width > len ? width : len);
}
