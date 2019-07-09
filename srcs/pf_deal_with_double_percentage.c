/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_deal_with_double_percentage.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:35:52 by jleblond          #+#    #+#             */
/*   Updated: 2019/07/09 10:35:58 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** single% are converted to 0 then double % are converted to single%
*/

int				count_single_p_then_to_zero(char *s, int len)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < len)
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i += 2;
		if (s[i] == '%' && s[i + 1] != '%')
		{
			counter++;
			s[i] = '\0';
			i++;
		}
		if (s[i] != '%' && s[i] != 0)
			i++;
	}
	return (counter);
}

char			*convert_double_p(char *s, int len, char *new_s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			new_s[j] = s[i];
			i += 2;
			j++;
		}
		else
		{
			new_s[j] = s[i];
			i++;
			j++;
		}
	}
	return (new_s);
}

char			*deal_with_double_percentage(const char *format,
													int *real_p_nb,
													int *new_len)
{
	int			len;
	int			p_cnt;
	int			i;
	char		*new_format;
	char		*s;

	len = ft_strlen(format);
	s = ft_strdup(format);
	*real_p_nb = count_single_p_then_to_zero(s, len);
	i = 0;
	p_cnt = 0;
	while (i < len)
	{
		if (s[i] == '%')
			p_cnt++;
		i++;
	}
	*new_len = len - p_cnt / 2;
	new_format = (char*)malloc(sizeof(char) * ((*new_len) + 1));
	new_format[*new_len] = '\0';
	convert_double_p(s, len, new_format);
	free(s);
	s = NULL;
	return (new_format);
}
<<<<<<< HEAD:srcs/pf_deal_with_double_percentage.c
=======




// t_list		*cut_to_unit(char *s, int real_p_nb, int len, int *unit_nb)
// {
// 	int		start;
// 	int		i;
// 	int		end;

// 	i = 0;
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

	// list = cut_to_unit(new_format, real_p_nb, new_len, unit_nb);
	lst = NULL;
	return (lst);
}
>>>>>>> 0fca97f66ba6da7912f3d26d8c01072cd31f3657:pf_parse.c
