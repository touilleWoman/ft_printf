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
