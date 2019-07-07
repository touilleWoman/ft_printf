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

int		ft_printf(const char *format, ...)
{
	va_list			args;
	int				printed_nb;
	t_list			*lst;
	int				unit_nb;

	lst = parse_string(format, &printed_nb);
	if (lst == NULL)
		return (printed_nb);

	va_start(args, format);

	// The va_list is nothing more than a byte pointer.
	// #define va_start(args, param) (args = (((va_list)&param) + sizeof(param)))
	va_end(args);
	printed_nb = 0;
	return (printed_nb);
}


int		main()
{
	int		ret;

	ret = ft_printf("ok%%lala\n");
	printf("ret:%d\n", ret);
	return (0);
}
