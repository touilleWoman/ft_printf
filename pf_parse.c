/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:04 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/06 11:57:19 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_p_and_p_to_zero(char	*s, int	len)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < len)
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i+= 2;
		if (s[i] == '%' && s[i + 1] != '%')
		{
			counter++;
			s[i] = '\0';
			i++;
		}
		if (s[i] != '%' && s[i] != 0)
			i++;
	}
	return (counter);
}

t_unit	**cut_string_to_unit(char *s, int len, int	unit_nb)
{

	t_unit	**stock;
	int		i;
	int		start;
	int		unit_id;

	i = 0;
	start = 0;
	unit_id = 0;
	stock = (t_unit**)malloc(sizeof(t_unit*) * unit_nb);
	while (i < len)
	{
		if (s[i] == '\0')
		{
			stock[unit_id]->before
			unit_id++;
			i++;
		}
		if (s[i] != '%' && s[i] != 0)
			i++;
	}
}

int		parse_string(const char *str, va_list args)
{
	char		*s;
	int			len;
	int			unit_nb;

	(void)args;
	len = ft_strlen(str);
	s = ft_strdup(str);
	unit_nb = count_p_and_p_to_zero(s, len);
	cut_string_to_unit(s, len, unit_nb);
	// char		**stock;


	// stock =	cut_string_to_unit(str)

	// void*	value1;
	// int	value2;

	// value1 = va_arg(args, void*);
	// printf("value1:%s\n", (char*)value1);
	// value2 = va_arg(args, int);
	// printf("value2:%d\n", value2);
	// return(unit_nb); //change later
	return (0);
}