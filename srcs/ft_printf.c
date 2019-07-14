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


int		pf_print_type_ltr(t_unit *unit)
{
	ft_putstr(unit->val.ltr.literal);
	return (ft_strlen(unit->val.ltr.literal));
}

int		pf_print_type_c(t_unit *unit)
{
	char s[unit->val.c.width];
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



int		print_list(t_list *lst)
{
	t_unit		*unit;
	static t_print_funs		funs[PRINT_FUNS_NB] = {
	{TYPE_LTR, pf_print_type_ltr}, {TYPE_C, pf_print_type_c}
	};
	int		index;
	int		printed_nb;

	printed_nb = 0;
	while (lst != NULL)
	{
		unit = unit_access(lst);
		index = 0;
		while (index < PRINT_FUNS_NB)
		{
			if (funs[index].type == unit->type)
			{
				printed_nb +=funs[index].f(unit);
			}
			index++;
		}
		lst = lst->next;
	}
	return (printed_nb);
}


int		ft_printf(const char * restrict format, ...)
{
	va_list			args;
	int				printed_nb;
	t_list			*lst;

	va_start(args, format);
	lst = parse_string(format, args);
	// if (lst == NULL)
	// 	return (printed_nb);
	va_end(args);
	printed_nb = print_list(lst);
	return (printed_nb);
}

/*
**	The va_list is nothing more than a byte pointer.
**	#define va_start(args, param) (args = (((va_list)&param) + sizeof(param)))
*/
