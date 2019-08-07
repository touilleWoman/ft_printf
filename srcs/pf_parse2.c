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
** 	[flags][width][precision][modifier][conversion][literal]
**	excepte the first capsule which may contains only literal
*/


static int		find_end_of_capsule(const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (is_conversion(format[i]))
			break;
			// return (i + 1);
		i++;
	}
	return (i);
}


// static int		find_conversion_in_capsule(const char *capsule)
// {
// 	int		len;
// 	int		posi;

// 	posi = 0;
// 	len = ft_strlen(capsule);
// 	while (posi < len)
// 	{
// 		if (is_conversion(capsule[posi]))
// 			break;
// 		posi++;
// 	}
// 	if (posi != len)
// 		return (posi);
// 	return (ERROR);
// }


/*
** 	seperate literal part with the rest when parsing capsul
*/


static int			parse_capsule(t_list **alst, const char *capsule, int end, va_list args)
{
	int					index;
	// int					posi;
	char				buf[ft_strlen(capsule)];
	int					len;
	static t_parse_funs	funs[PARSE_FUNS_NB] = {
		{'c', parse_c},{'s', parse_s}, {'d', parse_d}, {'i', parse_d},
		{'f', parse_f}, {'p', parse_p}, {'o', parse_oxx}, {'x', parse_oxx}, {'X', parse_oxx},
		{'u', parse_u}, {'%', parse_percent}
	};

	len = ft_strlen(capsule);
	index = 0;
	// posi = find_conversion_in_capsule(capsule);
	// if (posi == ERROR)
	// {
	// 	// freelst_and_errormsg(*alst, "format error: no conversion found\n");
	// 	return (ERROR);
	// }
	if (capsule[end] == '\0')
		return (ERROR);

	while (index < PARSE_FUNS_NB)
	{
		if(capsule[end] ==  funs[index].type)
		{
			ft_strncpy(buf, capsule, end + 1); //check later
			buf[end + 1] = '\0';
			if (funs[index].f(alst, buf, args) == ERROR)
				return (ERROR);
			break;
		}
		index++;
	}
	return(0);
}

void		unit_lstadd_literal(t_list **alst, const char *literal_piece, int len)
{
	t_unit		unit;

	ft_bzero(&unit, sizeof(t_unit));
	unit.type = TYPE_LTR;
	unit.val.ltr.len = len;
	unit.val.ltr.literal = literal_piece;
	unit_lstadd_bot(alst, &unit);
}


static int		parse_literal_substring(const char *capsule, t_list **alst, int *r_capsule_ok)
{
	int		i;
	// char	*buff;

	*r_capsule_ok = TRUE;
	i = 0;
	while (capsule[i] != '\0' && capsule[i] != '%')
		i++;
	// buff = (char*)malloc(sizeof(char) * (i + 1));
	// if (buff == NULL)
	// 	*r_capsule_ok = FALSE;
	// ft_strncpy(buff, capsule, i);
	// buff[i] = '\0';
	unit_lstadd_literal(alst, capsule, i);
	// TODO: missing free in list teardown
	return (i);
}


static int		parse_percent_substring(const char *capsule, t_list **alst, va_list args, int *r_capsule_ok)
{
	int end;
	int ret;

	*r_capsule_ok = TRUE;
	end = find_end_of_capsule(capsule);

	// {
	// 	char buff[i + 1];

	// 	ft_strncpy(buff, capsule, i);
	// 	buff[i] = '\0';

		ret = parse_capsule(alst, capsule, end, args);
		if (ret == ERROR)
		{
			*r_capsule_ok = FALSE;
		}
	// }
	return (end + 1);
}


t_list		*parse_string(const char *format, va_list args, int *r_format_ok)
{
	int		i;
	int		ret;
	int		substring_format_ok;
	t_list	*lst;

	*r_format_ok = TRUE;
	lst = NULL;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;  // Ignore percent
			i += parse_percent_substring(format + i, &lst, args, &substring_format_ok);
		}
		else
			i += parse_literal_substring(format + i, &lst, &substring_format_ok);
		if (!substring_format_ok)
			*r_format_ok = FALSE;
	}
	// show_list(lst);
	return (lst);
}
