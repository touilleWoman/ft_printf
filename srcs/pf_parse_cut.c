/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_cut_to_unit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:40:28 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/07 16:40:32 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		unit_lstadd_literal(t_list **alst, const char *literal_piece)
{
	t_unit		unit;

	unit.type = TYPE_LTR;
	unit.val.ltr.string = literal_piece;
	unit_lstadd_bot(alst, &unit);
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
		printf("format error: no conversion in capsule");
		exit(0);
		//need to free the list
		// return (FALSE) ;
	}
	else
		return (posi);
}

t_ptr_funs		funs[FUNS_NB] = {
{'c', pf_parse_type_c}
// {'c', pf_parse_type_c},{'s', pf_parse_type_s}
};

void		pf_parse_type_c(t_list **alst, char *buf, va_list args)
{
 	t_unit	unit;

 	if (*buf != 'c')
 		printf("error, %%c don't takes flags\n");
 	unit.type = TYPE_C;
 	unit.val.c.character = va_arg(args, int);
 	unit_lstadd_bot(alst, &unit);
}


void		cut_conversion_and_literal(t_list **alst, const char *capsule, va_list args)
{
	int			index;
	int			posi;
	char		buf[50];
	int			len;

	len = ft_strlen(capsule);
	index = 0;
	posi = find_conversion_in_capsule(capsule);
	while (index < FUNS_NB)
	{
		if(capsule[posi] ==  funs[index].symbol)
		{
			// buf = (char*)malloc(sizeof(char) * (posi + 2));

			ft_strncpy(buf, capsule, posi + 1); //check later
			buf[posi + 1] = '\0';
			funs[index].f(alst, buf, args);
		}
		index++;
	}
	if (posi != len - 1) // if there are literal after conversion, add ne literal unit
		unit_lstadd_literal(alst, ft_strdup(capsule + posi + 1));
}

/*
** one capsule is [flags][width][.precision][modifier][conversion][literal],
** excepte the one in the begining, it contains only literal
**	Ex "literal%+4dliteral%fliteral" cut to capsule will be
**	 "literal|+4dliteral|fliteral"
**  PS: % are already replaced by '\0'
*/

t_list		*cut_to_capsule(char *s, int len, va_list args)
{
	int		start;
	t_list	*lst;
	char	*capsule;

	lst = NULL;
	if (*s != '\0')
		unit_lstadd_literal(&lst, ft_strdup(s));
	start = ft_strlen(s) + 1;
	while (start < len)
	{
		capsule = ft_strdup(s + start);
		cut_conversion_and_literal(&lst, capsule, args);
		free(capsule);
		capsule = NULL;
		start += ft_strlen(s + start) + 1;
	}
	return (lst);
}