/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staskine <staskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:13:32 by staskine          #+#    #+#             */
/*   Updated: 2022/09/18 16:44:57 by staskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_initialize_tags(t_struct *tags)
{
	tags->width = 0;
	tags->prec = 0;
	tags->zero = 0;
	tags->h_tag = 0;
	tags->minus = 0;
	tags->plus = 0;
	tags->space = 0;
	tags->percent = 0;
	tags->length = 0;

	return (tags);
}

int		ft_printf(const char *str, ...)
{
	t_struct	*tags;
	va_list		list;
	int			ret_v;
	int			i;

	ret_v = 0;
	tags = (t_struct *)malloc(sizeof(t_struct));
	if (!tags)
		return (-1);
	ft_initialize_tags(tags);
	va_start(list, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i = next_function(tags, str, i + 1);
		else
			ret_v += write(1, &str[i], 1);
	}
	va_end(list);
	ret_v += tags->length;
	free (tags);
	return (ret_v);
}