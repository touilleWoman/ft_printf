/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:27:27 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/07 10:27:32 by jleblond         ###   ########.fr       */
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

int		print_list(t_list *lst)
{
	t_unit				*unit;
	static t_print_funs	funs[PRINT_FUNS_NB] = {{TYPE_LTR, print_ltr},
	{TYPE_C, print_c}, {TYPE_S, print_s}};
	int					index;
	int					printed_nb;

	printed_nb = 0;
	while (lst != NULL)
	{
		unit = unit_access(lst);
		index = 0;
		while (index < PRINT_FUNS_NB)
		{
			if (funs[index].type == unit->type)
				printed_nb += funs[index].f(unit);
			index++;
		}
		lst = lst->next;
	}
	return (printed_nb);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list			args;
	int				printed_nb;
	t_list			*lst;

	va_start(args, format);
	lst = parse_string(format, args);
	va_end(args);
	printed_nb = print_list(lst);
	return (printed_nb);
}

/*
**	The va_list is nothing more than a byte pointer.
**	#define va_start(args, param) (args = (((va_list)&param) + sizeof(param)))
*/
