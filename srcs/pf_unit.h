/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:33:18 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/09 10:33:56 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_UNIT_H
# define PF_UNIT_H

#include "libft.h"

typedef	enum 		e_unit_type
{
	TYPE_LTR = 1,
	TYPE_C,
	TYPE_S,
	TYPE_D,
}					t_unit_type;

typedef enum 		e_modifier
{
	MD_H = 1,
	MD_HH,
	MD_L,
	MD_LL,
}					t_modifier;

typedef struct 		s_type_ltr
{
	const char		*literal;
}					t_type_ltr;

typedef struct 		s_type_c
{
	t_bool			flag_minus;
	unsigned int	width;
	t_bool			modifier_l;
	unsigned char	character;
}					t_type_c;

typedef struct 		s_type_s
{
	t_bool			flag_minus;
	unsigned int	width;
	unsigned int	precision;
	t_bool			modifier_l;
	char			*string;
}					t_type_s;

typedef struct 		s_type_d
{
	t_bool			flag_minus;
	t_bool			flag_plus;
	t_bool			flag_zero;
	t_bool			flag_blank;
	unsigned int	width;
	unsigned int	precision;
	int				modifier;
	intmax_t		integer;
}					t_type_d;

typedef	union		u_unit_union
{
	t_type_ltr		ltr;
	t_type_c		c;
	t_type_s		s;
	t_type_d		d;
}					t_unit_union;

typedef struct		s_unit
{
		t_unit_union	val;
		t_unit_type		type;
}					t_unit;

t_unit				*unit_access(t_list *lst);
void				unit_lstadd_bot(t_list **alst, t_unit const *unit);
void				unit_lstadd_literal(t_list **alst, const char *literal_piece);


//test functions
void 				show_list(t_list   *lst);

# endif
