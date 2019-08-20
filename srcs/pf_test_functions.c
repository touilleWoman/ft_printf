// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pf_test_functions.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/07/11 12:09:17 by jleblond          #+#    #+#             */
// /*   Updated: 2019/07/11 12:09:19 by jleblond         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"

// void 	show_list(t_list   *lst)
// {
// 	t_unit		*unit;
// 	int			index;

// 	index = 0;
// 	while (lst != NULL)
// 	{
// 		printf("unit index: %d\n", index);
// 		unit = unit_access(lst);
// 		if (unit->type == TYPE_LTR)
// 			printf("\tcontent of TYPE_LTR is: `%s`\n", unit->val.ltr.literal);
// 		if (unit->type == TYPE_C)
// 		{
// 			printf("\tcontent of TYPE_C is:\n");
// 			printf("\tflag_minus: %d\n", unit->val.c.flag_minus);
// 			printf("\twidth: %d\n", unit->val.c.width);
// 			printf("\tmodifier_l: %d\n", unit->val.c.modifier_l);
// 			printf("\tcharacter: '%c'\n", unit->val.c.character);
// 		}
// 		if (unit->type == TYPE_D)
// 		{
// 			printf("\tcontent of TYPE_D is:\n");
// 			printf("\tflag_minus: %d\n", unit->val.d.flag_minus);
// 			printf("\tflag_plus: %d\n", unit->val.d.flag_plus);
// 			printf("\tflag_zero: %d\n", unit->val.d.flag_zero);
// 			printf("\tflag_blank: %d\n", unit->val.d.flag_blank);
// 			printf("\twidth: %d\n", unit->val.d.width);
// 			printf("\tprecision: %d\n", unit->val.d.precision);
// 			printf("\tmodifier: %d\n", unit->val.d.modifier);
// 			printf("\tint: %ld\n", (long int)unit->val.d.integer);
// 		}
// 		if (unit->type == TYPE_S)
// 		{
// 			printf("\tcontent of TYPE_S is:\n");
// 			printf("\tflag_minus: %d\n", unit->val.s.flag_minus);
// 			printf("\twidth: %d\n", unit->val.s.width);
// 			printf("\tprecision: %d\n", unit->val.s.precision);
// 			printf("\tmodifier_l: %d\n", unit->val.s.modifier_l);
// 			printf("\tstring: `%s`\n", unit->val.s.string);
// 		}
// 		if (unit->type == TYPE_F)
// 		{
// 			printf("\tcontent of TYPE_F is:\n");
// 			printf("\tflag_minus: %d\n", unit->val.f.flag_minus);
// 			printf("\tflag_plus: %d\n", unit->val.f.flag_plus);
// 			printf("\tflag_zero: %d\n", unit->val.f.flag_zero);
// 			printf("\tflag_blank: %d\n", unit->val.f.flag_blank);
// 			printf("\tflag_hash: %d\n", unit->val.f.flag_hash);
// 			printf("\twidth: %d\n", unit->val.f.width);
// 			printf("\tprecision: %d\n", unit->val.f.precision);
// 			printf("\tmodifier: %d\n", unit->val.f.modifier);
// 			printf("\tdouble: %Lf\n", unit->val.f.doub);
// 		}
// 		if (unit->type == TYPE_OXX)
// 		{
// 			printf("\tcontent of TYPE_OXX is:\n");
// 			printf("\tflag_minus: %d\n", unit->val.oxx.flag_minus);
// 			printf("\tflag_zero: %d\n", unit->val.oxx.flag_zero);
// 			printf("\tflag_hash: %d\n", unit->val.oxx.flag_hash);
// 			printf("\twidth: %d\n", unit->val.oxx.width);
// 			printf("\tprecision: %d\n", unit->val.oxx.precision);
// 			printf("\tmodifier: %d\n", unit->val.oxx.modifier);
// 			printf("\tunsigned int: %ju\n", unit->val.oxx.un_int);
// 		}

// 		// printf("\n\n");
// 		lst = lst->next;
// 		index++;
// 	}

// }
