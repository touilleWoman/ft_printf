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


int			print_p(int fd, t_unit *unit)
{
	int		len;
	char	s[unit->val.p.width + 30];
	char	str_p[30];

	ft_memset(s, ' ', unit->val.p.width + 30);
	if (unit->val.p.precision == PRECISION_NULL)
		*str_p = 0;
	else
		pf_itoa_base(unit->val.p.pointer, 16, unit, str_p);
	len = ft_strlen(str_p) + 2;
	if (unit->val.p.width > len && unit->val.p.flag_minus == FALSE)
	{
		ft_strncpy(s + unit->val.p.width - len, "0x", 2);
		ft_strncpy(s + unit->val.p.width - len + 2, str_p, len - 2);
		s[unit->val.p.width] = 0;
	}
	else
	{
		ft_strncpy(s, "0x", 2);
		ft_strncpy(s + 2, str_p, len - 2);
		if (unit->val.p.width > len)
			s[unit->val.p.width] = 0;
		else
			s[len] = 0;
	}
	ft_putstr_fd(s, fd);
	return (unit->val.p.width > len ? unit->val.p.width : len);
}
