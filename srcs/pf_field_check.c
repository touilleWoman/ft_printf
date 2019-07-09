/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_field_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:45:37 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/09 16:45:42 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_option(char c)
{
	if (ft_strchr("-+0 ", c) == 0)
		return (FALSE);
	return (TRUE);
}

int		is_conversion(char c)
{
	if (ft_strchr("cspdiouxX", c) == 0)
		return (FALSE);
	return (TRUE);
}

int		is_valid(char c)
{
	if (is_flag(c) || is_conversion(c))
		return (TRUE)
	return (FALSE);
}

void	field_check(char c, int *cnt_printed_chars)
{
	if (is_conversion(c))
	{
		conversion_manage(c);
	}
}
