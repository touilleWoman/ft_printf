/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_type_c_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:23:31 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/14 16:23:41 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			get_width(char *s, int *width_len)
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
	*width_len = i;
	s1[i] = '\0';
	return (ft_atoi(s1));
}

void		pf_parse_type_c(t_list **alst, char *buf, va_list args)
{
 	t_unit	unit;
 	int		i;
 	int		width;
 	int		width_len;

 	i = 0;
 	ft_bzero(&unit, sizeof(t_unit));
	if (buf[0] == '-')
	{
		unit.val.c.flag_minus = TRUE;
		i++;
	}
	width = get_width(buf + i, &width_len);
	if (width != FALSE)
	{
		unit.val.c.width = width;
		i += width_len;
	};
	if (buf[i] == 'l')
	{
		unit.val.c.modifier_l = TRUE;
		i++;
	}
	if (buf[i] == 'c')
	{
		unit.type = TYPE_C;
		if (unit.val.c.modifier_l == TRUE)
			unit.val.c.character = va_arg(args, wint_t);
		else
			unit.val.c.character = va_arg(args, int);
		unit_lstadd_bot(alst, &unit);
		return ;
	}
 	printf("error: %%c format wrong\n");
 	exit(0);
}





/*
** one capsule is [flags][width][.precision][modifier][conversion][literal],
** excepte the one in the begining, it contains only literal
**	Ex "literal%+4dliteral%fliteral" cut to capsule will be
**	 "literal|+4dliteral|fliteral"
**  PS: % are already replaced by '\0'
*/

