/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unit_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:51:15 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/09 10:51:19 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*unit_list_new(t_unit const *unit)
{
	t_list *lst;

	lst = ft_lstnew((void const *)unit, sizeof(t_unit));
	return (lst);
}

void		unit_lstadd_bot(t_list **alst, t_unit const *unit)
{
	ft_lstadd_bot(alst, unit_list_new(unit));
}

t_unit		*unit_access(t_list *lst)
{
	return ((t_unit*)lst->content);
}

void		unit_lstadd_literal(t_list **alst, const char *literal_piece)
{
	t_unit		unit;

	unit.type = TYPE_LTR;
	// printf("add typeLTR%d\n", unit.type );
	unit.val.ltr.literal = literal_piece;
	unit_lstadd_bot(alst, &unit);
}
