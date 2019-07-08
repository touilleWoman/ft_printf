#ifndef PF_UNIT_H
# define PF_UNIT_H

typedef	enum 		e_specifier
{
	TYPE_C,
	TYPE_D,
	TYPE_S,
	TYPE_F,
}					t_specifier;


typedef struct 		s_literal
{
	char			*text;
}					t_literal;

typedef struct 		s_params
{
	char			*text;
	t_options		option;
	unsigned int	width;
	unsigned int	precision;
	t_length		length;
}					t_params;



typedef	union		u_unit_union
{
	t_literal		ltr;
	t_d				d;
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

t_list		*unit_list_new(t_unit const *unit);
t_unit		*unit_access(t_list *lst);


# endif
