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

void		unit_lstadd_literal(t_list **alst, char *literal_piece)
{
	t_unit		unit;

	unit.type = TYPE_LTR;
	unit.val.ltr.string = literal_piece;
	*alst = unit_list_new(&unit);
}

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
		printf("format error: no conversion")
		exit(0);
		//need to free the list
		// return (FALSE) ;
	}
	else
		return (posi);
}

t_ptr_funs		funs[FUNS_NB] = {
{'c', pf_parse_type_c},{'s', pf_parse_type_s}
};

void		pf_parse_type_c(t_list **alst, char *buf)
{

}

void		seperate_conversion_and_literal(t_list **alst, const char *capsule)
{
	int			index;
	int			posi;
	char		buf[30];
	int			len;

	len = ft_strlen(capsule);
	index = 0
	posi = find_conversion_in_capsule(capsule);
	while (index < FUNS_NB)
	{
		if(capsule[posi] = funs[index].symbol)
		{
			buf = ft_strncpy(buf, capsule, posi + 1);
			buf[posi + 1] = '\0';
			funs[index].f(alst, buf);
		}
		index++;
	}
	if (posi != len - 1) // there are literal after conversion
		unit_lstadd_literal(alst, ft_strdup(capsule + posi + 1))
}




t_list		*cut_to_unit(char *s, int len)
{
	int		start;
	t_list	*lst;

	if (*s != '\0')
	{
		unit_lstadd_literal(&lst, ft_strdup(s));
		start = ft_strlen(s) + 1;
	}
	else
		start = 1;
	while (start < len)
	{
		seperate_conversion_and_literal(&lst, ft_strcpy(s + start));
		start += ft_strlen(s + start) + 1;
	}
	return (lst);
}

t_list		*parse_string(const char *format, int *printed_nb, int *unit_nb)
{
	char			*new_format;
	int				new_len;
	int				real_p_nb;
	t_list			*lst;

	new_format = deal_with_double_percentage(format, &real_p_nb, &new_len);
	if (real_p_nb == 0)
	{
		write(1, new_format, new_len);
		*unit_nb = 1;
		*printed_nb = new_len;
		return (NULL);
	}
	lst = cut_to_unit(new_format, real_p_nb, new_len, unit_nb);
	t_unit *unit = unit_access(lst);
	printf("string:%s\n", unit->val.ltr.string );
	printf("type:%d\n", unit->type);
	return (lst = NULL);
}