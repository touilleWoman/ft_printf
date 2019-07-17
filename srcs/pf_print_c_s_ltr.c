/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_c_s_ltr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:45:57 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/16 16:46:00 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ltr(t_unit *unit)
{
	ft_putstr(unit->val.ltr.literal);
	return (ft_strlen(unit->val.ltr.literal));
}

int		print_c(t_unit *unit)
{
	char	s[unit->val.c.width + 1];
	int		width;

	width = unit->val.c.width;
	if (width != FALSE)
	{
		s[width] = '\0';
		ft_memset(s, ' ', width);
		if (unit->val.c.flag_minus == FALSE)
			s[width - 1] = unit->val.c.character;
		else
			s[0] = unit->val.c.character;
		ft_putstr(s);
		return (ft_strlen(s));
	}
	write(1, &(unit->val.c.character), 1);
	return (1);
}

int		print_s(t_unit *unit)
{
	int		width;
	int		precision;
	int		print_len;
	char	s[unit->val.s.width];


	print_len = ft_strlen(unit->val.s.string);
	precision = unit->val.s.precision;
	width = unit->val.s.width;
	if (precision != FALSE && precision < print_len)
		print_len = precision;
	if (width != FALSE && width > print_len)
	{
		ft_memset(s, ' ', width);
		if (unit->val.s.flag_minus == FALSE)
			ft_strncpy((s + width - print_len), unit->val.s.string, print_len);
		else
			ft_strncpy(s, unit->val.s.string, print_len);
		write(1, s, width);
		return (width);
	}
	write(1, unit->val.s.string, print_len);
	return (print_len);
}