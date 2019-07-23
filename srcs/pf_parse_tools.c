/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:24:02 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/14 16:24:07 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int				get_digits(int *digits, char *buf, int buf_len)
{
	int		i;
	char	s1[buf_len];

	i = 0;
	if (ft_isdigit(*buf) == FALSE)
		return (0);
	while (ft_isdigit(buf[i]))
	{
		s1[i] = buf[i];
		i++;
	}
	s1[i] = '\0';
	*digits = ft_atoi(s1);
	return (i);
}

static int		is_flags(char c, char *valid_flags)
{
	if (ft_strchr(valid_flags, c) == 0)
		return (FALSE);
	return (TRUE);
}

int				get_flags(char *flags, char *buf, char *valid_flags)
{
	int		i;

	i = 0;
	if (is_flags(*buf, valid_flags) == FALSE)
		return(0);
	while(is_flags(buf[i], valid_flags))
	{
		flags[i] = buf[i];
		i++;
	}
	flags[i] = '\0';
	return (i);
}

