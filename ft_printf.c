/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:17:56 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/04 10:18:10 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_string(const char *str, va_list args)
{
	int		pos;

	(void)args;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			pos++;

		}
		else
			write(1, &(str[pos]), 1);
		pos++;
	}
	return(pos);
}


int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			result;

	va_start(args, str);
	// The va_list is nothing more than a byte pointer.
	// #define va_start(list, param) (list = (((va_list)&param) + sizeof(param)))
	result = parse_string(str, args);
	va_end(args);
	return (result);
}


int		main()
{
	ft_printf("test\n");
	return (0);
}