
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

int		print_list(int fd, t_list *lst)
{
	t_unit				*unit;
	static t_print_funs	funs[PRINT_FUNS_NB] = {{TYPE_LTR, print_ltr},
	{TYPE_C, print_c}, {TYPE_S, print_s}, {TYPE_D, print_d}, {TYPE_P, print_p},
	{TYPE_OXX, print_oxx}, {TYPE_U, print_u}, {TYPE_F, print_f}
};
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
				printed_nb += funs[index].f(fd, unit);
			index++;
		}
		lst = lst->next;
	}
	return (printed_nb);
}

int		ft_vdprintf(int fd, const char * restrict format, va_list args)
{
	t_list			*lst;
	int				printed_nb;
	int				format_ok;

	if (format == NULL)
		return (-1);
	printed_nb = 0;
	lst = parse_string(format, args, &format_ok);
	if (lst != NULL)
	{
		printed_nb = print_list(fd, lst);
		freelst_and_errormsg(lst, NULL);
	}
	// if (format_ok)
		return (printed_nb);
// 	else
// 		return (-1);
}


int		ft_printf(const char * restrict format, ...)
{
	va_list			args;
	int				printed_nb;


	va_start(args, format);
	printed_nb = ft_vdprintf(STD_OUT, format, args);
	va_end(args);
	return (printed_nb);
}

/*	The va_list is nothing more than a byte pointer.
**	#define va_start(args, param) (args = (((va_list)&param) + sizeof(param)))
*/
