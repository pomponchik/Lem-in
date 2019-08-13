/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:35:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:18:36 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf	*filling_buf_str(t_print *print, t_buf *for_buf, char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (for_buf->i <= BUFF_SIZE)
			for_buf->buf[for_buf->i++] = str[i];
		else
		{
			print_buf(print, for_buf, 0);
			for_buf->buf[for_buf->i++] = str[i];
		}
		i++;
	}
	return (for_buf);
}

t_buf	*buffer(t_print *print, t_buf *for_buf, char *str)
{
	for_buf->len = ft_strlen(str);
	if (print->minus == '-')
	{
		filling_buf(print, for_buf, &str);
		filling_buf_str(print, for_buf, str);
		filling_buf_byspace(print, for_buf);
	}
	else
	{
		filling_buf_2(print, for_buf, &str);
		filling_buf_byspace(print, for_buf);
		filling_buf_start(print, for_buf, ft_strlen(str));
		filling_buf_str(print, for_buf, str);
	}
	return (for_buf);
}
