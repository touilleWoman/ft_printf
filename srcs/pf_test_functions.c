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
		if (unit->type == TYPE_D)
		{
			printf("content of TYPE_D is:\n");
			printf("flag_minus:%d|\n", unit->val.d.flag_minus);
			printf("flag_plus:%d|\n", unit->val.d.flag_plus);
			printf("flag_zero:%d|\n", unit->val.d.flag_zero);
			printf("flag_blank:%d|\n", unit->val.d.flag_blank);
			printf("width:%d|\n", unit->val.d.width);
			printf("precision:%d|\n", unit->val.d.precision);
			printf("modifier:%d|\n", unit->val.d.modifier);
			printf("int:%ld|\n", (long int)unit->val.d.integer);
		}
		if (unit->type == TYPE_S)
		{
			printf("content of TYPE_S is:\n");
			printf("flag_minus:%d|\n", unit->val.s.flag_minus);
			printf("width:%d|\n", unit->val.s.width);
			printf("precision:%d|\n", unit->val.s.precision);
			printf("modifier_l:%d|\n", unit->val.s.modifier_l);
			printf("string:%s|\n", unit->val.s.string);
		}
		if (unit->type == TYPE_F)
		{
			printf("content of TYPE_F is:\n");
			printf("flag_minus:%d|\n", unit->val.f.flag_minus);
			printf("flag_plus:%d|\n", unit->val.f.flag_plus);
			printf("flag_zero:%d|\n", unit->val.f.flag_zero);
			printf("flag_blank:%d|\n", unit->val.f.flag_blank);
			printf("flag_hash:%d|\n", unit->val.f.flag_hash);
			printf("width:%d|\n", unit->val.f.width);
			printf("precision:%d|\n", unit->val.f.precision);
			printf("modifier:%d|\n", unit->val.f.modifier);
			printf("double:%Lf|\n", unit->val.f.doub);
		}
		printf("\n\n");
		lst = lst->next;
		index++;
	}

}
