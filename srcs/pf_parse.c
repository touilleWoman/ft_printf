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



t_list		*parse_string(const char *format, int *printed_nb, va_list args)
{
	char			*new_format;
	int				new_len;
	int				real_p_nb;
	t_list			*lst;

	(void)printed_nb;
	new_format = deal_with_double_percentage(format, &real_p_nb, &new_len);
	lst = cut_to_capsule(new_format,new_len, args);
	show_list(lst);
	// t_unit *unit = unit_access(lst);
	// printf("c:%c\n", unit->val.c.character);
	// printf("type:%d\n", unit->type);
	return (lst);
}