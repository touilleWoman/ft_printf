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

/*
**	a capsule is defined as :
** 	[flags][width][precision][modifier][conversion][litetral]
**	excepte the first capsule which may contains only literal
** 	then we seperate literal part with the rest
*/

int		find_conversion_in_capsule(const char *capsule)
{
	int		len;
	int		posi;

	posi = 0;
	len = ft_strlen(capsule);
	while (posi < len)
	{
		if (is_conversion(capsule[posi]) == TRUE)
			break;
		posi++;
	}
	if (posi == len)
	{
		printf("format error: no conversion in capsule");
		exit(0);
		//need to free the list
		// return (FALSE) ;
	}
	else
		return (posi);
}

int			seperate_conversion_and_literal(t_list **alst, const char *capsule, va_list args)
{
	int					index;
	int					posi;
	char				buf[ft_strlen(capsule)];
	int					len;
	static t_parse_funs	funs[PARSE_FUNS_NB] = {
		{'c', parse_type_c},{'s', parse_type_s}, {'d', parse_type_d},
		{'f', parse_type_f}, {'p', parse_type_p}
		};

	len = ft_strlen(capsule);
	index = 0;
	posi = find_conversion_in_capsule(capsule);
	while (index < PARSE_FUNS_NB)
	{
		if(capsule[posi] ==  funs[index].type)
		{
			ft_strncpy(buf, capsule, posi + 1); //check later
			buf[posi + 1] = '\0';
			if (funs[index].f(alst, buf, args) == ERROR)
				return (ERROR);
		}
		index++;
	}
	if (posi != len - 1) // if there are literal after conversion, add ne literal unit
		unit_lstadd_literal(alst, ft_strdup(capsule + posi + 1));
	return(0);
}

t_list		*cut_to_capsule(char *s, int len, va_list args)
{
	int		start;
	t_list	*lst;
	char	*capsule;
	int		err_check;

	lst = NULL;
	if (*s != '\0')
		unit_lstadd_literal(&lst, ft_strdup(s));
	start = ft_strlen(s) + 1;
	while (start < len)
	{
		capsule = ft_strdup(s + start);
		err_check = seperate_conversion_and_literal(&lst, capsule, args);
		free(capsule);
		capsule = NULL;
		if (err_check == ERROR)
			return (NULL);
		start += ft_strlen(s + start) + 1;
	}
	return (lst);
}

t_list		*parse_string(const char *format, va_list args)
{
	char			*new_format;
	int				new_len;
	int				real_p_nb;
	t_list			*lst;

	new_format = deal_with_double_percentage(format, &real_p_nb, &new_len);
	lst = cut_to_capsule(new_format,new_len, args);
	free(new_format);
	new_format = NULL;
	// show_list(lst);
	return (lst);
}

