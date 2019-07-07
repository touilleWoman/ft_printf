#ifndef UNIT_H
# define UNIT_H

typedef	enum 		e_unit_type
{
	LITERAL = 0,
}					t_unit_type;

typedef struct 		s_literal
{
	char			*text;
}					t_literal;


typedef	union		u_unit_union
{
	t_literal		ltr;
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

typedef struct 					s_unit
{
		t_unit_union	val;
		t_unit_type		type;
}								t_unit;	

# endif
