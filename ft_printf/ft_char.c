/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:36:49 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:19:50 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf	*print_buf(t_print *print, t_buf *for_buf, int num)
{
	write(1, for_buf->buf, for_buf->i);
	ft_bzero(for_buf->buf, BUFF_SIZE);
	print->len += for_buf->i;
	if (num == -1)
		for_buf->i = num;
	else if (num == 0)
		for_buf->i = num;
	return (for_buf);
}

t_buf	*ft_char(t_print *print, t_buf *for_buf, int k)
{
	char	c;

	c = (char)k;
	if (print->minus == '-')
	{
		if (for_buf->i <= BUFF_SIZE)
			for_buf->buf[for_buf->i++] = c;
		else
		{
			print_buf(print, for_buf, 0);
			for_buf->buf[for_buf->i++] = c;
		}
		for_buf->len = 1;
		filling_buf_byspace(print, for_buf);
	}
	else
	{
		for_buf->len = 1;
		filling_buf_byspace(print, for_buf);
		for_buf->buf[for_buf->i++] = c;
	}
	return (for_buf);
}
