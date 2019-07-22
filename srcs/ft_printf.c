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
// void	free_unit(t_unit *unit)
// {
// 	unit->type == TYPE_LTR ? free()
// }



// void	freelst_and_errormsg(t_list *list, char *msg)
// {
// 	t_unit		*unit;
// 	t_list		*keep;

// 	while (lst != NULL)
// 	{
// 		keep = lst->next;


// 		lst = keep;

// 	}
// 	ft_putstr(msg);
// }



int		print_list(int fd, t_list *lst)
{
	t_unit				*unit;
	static t_print_funs	funs[PRINT_FUNS_NB] = {{TYPE_LTR, print_ltr},
	{TYPE_C, print_c}, {TYPE_S, print_s}, {TYPE_D, print_d}};
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

	lst = parse_string(format, args);
	printed_nb = print_list(fd, lst);
	return (printed_nb);
}


int		ft_dprintf(int fd, const char * restrict format, ...)
{
	va_list			args;
	int				printed_nb;

	va_start(args, format);
	printed_nb = ft_vdprintf(fd, format, args);
	va_end(args);
	return(printed_nb);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list			args;
	int				printed_nb;

	va_start(args, format);
	printed_nb = ft_vdprintf(1, format, args);
	va_end(args);
	return(printed_nb);
}

// **	The va_list is nothing more than a byte pointer.
// **	#define va_start(args, param) (args = (((va_list)&param) + sizeof(param)))

