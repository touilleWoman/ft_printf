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

int		count_single_p_then_to_zero(char *s, int len)
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

char	*convert_double_p(char *s, int len, char *new_s)
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
			i+= 2;
			j++;
		}
		else
		{
			new_s[j] = s[i];
			i++;
			j++;
		}
	}
	free (s);
	s = NULL;
	return (new_s);
}

/*
** single% are converted to 0 then double % are converted to single%
*/

char			*deal_with_double_percentage(const char*format, int *real_p_nb, int *new_len)
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
	new_format[*new_len] ='\0';
	convert_double_p(s, len, new_format);
	return (new_format);
}

t_stock		**only_one_literal_unit(char *s, int *unit_nb, int len)
{

	return (stock);
}

void			detect_conversion(char *s, int len, int *unit_nb)
{
	int		i;

	i = 0;
	while (i < len)
	{

		i++;
	}
}

t_stock		**cut_to_unit(char *s, int real_p_nb, int len, int *unit_nb)
{
	t_stock	**stock;

	if (real_p_nb == 0)
	{
		stock = only_one_literal_unit(s, unit_nb, len);
		return (stock);
	}
	else
	{
		detect_conversion(s, len, unit_nb);
		return (NULL);
	}
}


t_stock		**parse_string(const char *format, int *unit_nb)
{
	char			*new_format;
	int				new_len;
	int				real_p_nb;
	t_list			*list;

	new_format = deal_with_double_percentage(format, &real_p_nb, &new_len);
	if (real_p_nb == 0)
	{
		only_one_literal_unit(new_format, len)
		return (NULL);
	}
	list = cut_to_unit(new_format, real_p_nb, new_len, unit_nb);
	return (list);
}