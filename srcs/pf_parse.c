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

// t_list		*cut_to_unit(char *s, int real_p_nb, int len, int *unit_nb)
// {
// 	int		start;
// 	int		i;
// 	int		end;

// 	i = 0
// 	start = 0;
// 	end = 0;
// 	while ( start < len)
// 	{
// 		if (s[start] == '\0')
// 		{
// 			piece = ft_strcpy(s + start);

// 			end = start + 1;
// 			while (s[end] != '\0')
// 				end++;

// 		}
// 		start++;
// 	}

// }

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


t_list		*parse_string(const char *format, int *printed_nb, int *unit_nb)
{
	char			*new_format;
	int				new_len;
	int				real_p_nb;
	t_list			*lst;

	new_format = deal_with_double_percentage(format, &real_p_nb, &new_len);
	if (real_p_nb == 0)
	{
		write(1, new_format, new_len);
		*unit_nb = 1;
		*printed_nb = new_len;
		return (NULL);
	}
	// lst = cut_to_unit(new_format, real_p_nb, new_len, unit_nb);
	return (lst = NULL);
}