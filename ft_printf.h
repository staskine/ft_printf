/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staskine <staskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:30:31 by staskine          #+#    #+#             */
/*   Updated: 2022/09/18 17:03:25 by staskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_struct
{
	int		width;
	int		prec;
	int		zero;
	int		h_tag;
	int		minus;
	int		plus;
	int		space;
	int		percent;
	int		length;
} t_struct;

int		ft_printf(const char *str, ...);

#endif
