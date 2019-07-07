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
	t_stock			**stock;
	int				unit_nb;

	stock = parse_string(format, &unit_nb);
	if (unit_nb == 1)
	{
		write(1, ((*stock)->unit.ltr.text), (*stock)->unit.ltr.len);
		printf("printed_nb:%d\n", (*stock)->unit.ltr.len);

		return ((*stock)->unit.ltr.len);
	}
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
