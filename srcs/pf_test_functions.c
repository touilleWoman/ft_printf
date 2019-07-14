/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_test_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:17 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/11 12:09:19 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	show_list(t_list   *lst)
{
	t_unit		*unit;
	int			index;

	index = 0;
	while (lst != NULL)
	{
		printf("unit index%d\n", index);
		unit = unit_access(lst);
		if (unit->type == TYPE_LTR)
			printf("content of TYPE_LTR is:%s|\n", unit->val.ltr.literal);
		if (unit->type == TYPE_C)
		{
			printf("content of TYPE_C is:\n");
			printf("flag_minus:%d|\n", unit->val.c.flag_minus);
			printf("width:%d|\n", unit->val.c.width);
			printf("modifier_l:%d|\n", unit->val.c.modifier_l);
			printf("character:%c|\n", unit->val.c.character);
		}
		printf("\n\n");
		lst = lst->next;
		index++;
	}

}
