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
*/


int		find_conversion_in_capsule(t_list **alst, const char *capsule)
{
	int		len;
	int		posi;

	posi = 0;
	len = ft_strlen(capsule);
	while (posi < len)
	{
		if (is_conversion(capsule[posi]))
			break;
		posi++;
	}
	if (posi != len)
		return (posi);
	freelst_and_errormsg(*alst, "format error: no conversion found\n");
	return (ERROR);
}

/*
** 	seperate literal part with the rest when parsing capsul
*/

int			parse_capsule(t_list **alst, const char *capsule, va_list args)
{
	int					index;
	int					posi;
	char				buf[ft_strlen(capsule)];
	int					len;
	static t_parse_funs	funs[PARSE_FUNS_NB] = {
		{'c', parse_c},{'s', parse_s}, {'d', parse_d}, {'i', parse_d},
		{'f', parse_f}, {'p', parse_p}, {'o', parse_oxx}, {'x', parse_oxx}, {'X', parse_oxx},
		{'u', parse_u}};

	len = ft_strlen(capsule);
	index = 0;
	posi = find_conversion_in_capsule(alst, capsule);
	if (posi == ERROR)
		return (ERROR);
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
	if (posi != len - 1) // if there are literal after conversion, add the literal unit
		unit_lstadd_literal(alst, ft_strdup(capsule + posi + 1));
	return(0);
}

t_list		*cut_to_capsule(char *s, int len, va_list args)
{
	int		len_cnt;
	t_list	*lst;
	char	*capsule;
	int		err_check;

	lst = NULL;
	if (*s != '\0')
		unit_lstadd_literal(&lst, ft_strdup(s));
	// len_cnt = ft_strlen(s) + 1;
	// while (len_cnt < len)
	// {
	// 	capsule = s + len_cnt;
	// 	err_check = parse_capsule(&lst, capsule, args);
	// 	if (err_check == ERROR)
	// 		return (NULL);
	// 	len_cnt += ft_strlen(s + len_cnt) + 1;
	// }
	len_cnt = 0;
	while (1)
	{
		len_cnt += ft_strlen(s + len_cnt) + 1;
		if (len_cnt > len)
			break;
		if (s[ft_strlen(s + len_cnt) + 1] == 0 && (len_cnt + ft_strlen(s + len_cnt) + 1) < len)
		{
			printf("type percentage\n");
		}
		capsule = s + len_cnt;
		err_check = parse_capsule(&lst, capsule, args);
		if (err_check == ERROR)
			break;
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
	lst = cut_to_capsule(new_format, new_len, args);
	free(new_format);
	new_format = NULL;
	// show_list(lst);
	return (lst);
}

