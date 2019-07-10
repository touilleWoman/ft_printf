/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_deal_with_double_percentage.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:35:52 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/09 10:35:58 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** single% are converted to 0 then double % are converted to single%
*/

int				count_single_p_then_to_zero(char *s, int len)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < len)
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i += 2;
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

char			*convert_double_p(char *s, int len, char *new_s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			new_s[j] = s[i];
			i += 2;
			j++;
		}
		else
		{
			new_s[j] = s[i];
			i++;
			j++;
		}
	}
	return (new_s);
}

char			*deal_with_double_percentage(const char *format,
													int *real_p_nb,
													int *new_len)
{
	int			len;
	int			p_cnt;
	int			i;
	char		*new_format;
	char		*s;

	len = ft_strlen(format);
	s = ft_strdup(format);
	*real_p_nb = count_single_p_then_to_zero(s, len);
	i = 0;
	p_cnt = 0;
	while (i < len)
	{
		if (s[i] == '%')
			p_cnt++;
		i++;
	}
	*new_len = len - p_cnt / 2;
	new_format = (char*)malloc(sizeof(char) * ((*new_len) + 1));
	new_format[*new_len] = '\0';
	convert_double_p(s, len, new_format);
	free(s);
	s = NULL;
	return (new_format);
}
