/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:57:12 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:26:02 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf	*parser_str(t_print *print, t_buf *for_buf)
{
	char *str;

	str = NULL;
	while (print->copy[print->i])
	{
		if (print->copy[print->i] == '%')
		{
			parser(print, for_buf);
			if (print->copy[print->i])
				print->i++;
		}
		else
		{
			reinicialization(print, &for_buf);
			buffer(print, for_buf, (str = ft_until_per(&print)));
			ft_strdel(&str);
		}
	}
	return (for_buf);
}

int		ft_printf(const char *format, ...)
{
	t_print	*print;
	t_buf	*for_buf;
	int		len;

	if (!(print = (t_print *)malloc(sizeof(t_print))) ||
	!(for_buf = (t_buf *)malloc(sizeof(t_buf))))
		return (0);
	print->copy = format;
	inicialization(print, &for_buf);
	va_start(print->ap, format);
	parser_str(print, for_buf);
	va_end(print->ap);
	write(1, for_buf->buf, for_buf->i);
	if (print->color)
		ft_strdel(&(print)->color);
	if (for_buf->buf)
		ft_strdel(&(for_buf)->buf);
	len = print->len + for_buf->i;
	free(print);
	free(for_buf);
	return (len);
}
