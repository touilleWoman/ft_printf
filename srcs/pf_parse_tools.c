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

int			get_digits(char *s, int *digits_len)
{
	int		i;
	char	s1[100];

	i = 0;
	if (ft_isdigit(*s) == FALSE)
		return (FALSE);
	while (ft_isdigit(s[i]))
	{
		s1[i] = s[i];
		i++;
	}
	*digits_len = i;
	s1[i] = '\0';
	return (ft_atoi(s1));
}