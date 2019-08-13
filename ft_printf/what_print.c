/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:49:14 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:25:00 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	what_print(t_print *print, t_buf *for_buf)
{
	char *str;

	if (print->type == 'd' || print->type == 'i')
		buffer(print, for_buf, (str = ft_int(print)));
	else if (print->type == 'o')
		buffer(print, for_buf, (str = ft_octal(print)));
	else if (print->type == 'X' || print->type == 'x')
		buffer(print, for_buf, (str = ft_hex(print)));
	else if (print->type == 'u')
		buffer(print, for_buf, (str = ft_unsigned_int(print)));
	else if (print->type == 'f')
		buffer(print, for_buf, (str = ft_float(print)));
	else if (print->type == 'e' || print->type == 'E')
		buffer(print, for_buf, (str = ft_type_e(print)));
	else if (print->type == 's')
		buffer(print, for_buf, (str = ft_create_str(print)));
	else if (print->type == 'p')
		buffer(print, for_buf, (str =
				ft_point((long int)va_arg(print->ap, void *), print)));
	else if (print->type == 'c')
		ft_char(print, for_buf, va_arg(print->ap, int));
	if (print->type != 'c')
		ft_strdel(&str);
}
