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



char		*pf_itoa_base(uintmax_t nbr, int base)
{
	int		count;
	char	buf[100];

	count = 0;
	buf[99] = '\0';
	if (nbr == 0 && base == 16)
		return (ft_strdup("0x0"));
	while (nbr > 0 )
	{
		count++;
		buf[99 - count] = nbr % base + ((nbr % base < 10) ? '0' : 'a'- 10);
		nbr = nbr / base;
	}
	buf[99 - count - 1] = 'x';
	buf[99 - count - 2] = '0';
	return (ft_strdup(buf + 99 - count - 2));
}


int				print_p(int fd, t_unit *unit)
{
	char	*s;
	int		len;

	s = pf_itoa_base(unit->val.p.pointer, 16);
	ft_putstr_fd(s, fd);
	len = ft_strlen(s);
	free (s);
	s = NULL;
	return (len);
}
