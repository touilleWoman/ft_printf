#include "ft_printf.h"


t_list		*unit_list_new(t_unit const *unit)
{
	t_list *lst;

	lst = ft_lstnew((void const *)unit, sizeof(t_unit));
	return (lst);
}

t_unit		*unit_access(t_list *lst)
{
	return ((t_unit*)lst->content);
}
