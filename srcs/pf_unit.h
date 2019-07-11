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
	TYPE_LTR = 0,
	TYPE_C,
	TYPE_S,
	TYPE_D,
}					t_unit_type;

typedef struct 		s_literal
{
	const char		*string;
}					t_literal;

typedef struct 		s_type_c
{
	unsigned char	character;
}					t_type_c;

typedef	union		u_unit_union
{
	t_literal		ltr;
	t_type_c		c;
	// char			c;
	// char			*s;
	// void			*p;
	// int				d;
	// int				i;
	// unsigned int	o;
	// unsigned int	u;
	// unsigned int	x;
	// unsigned int	mj_x;
	// float			f;
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
