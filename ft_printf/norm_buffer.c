/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:36:03 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:23:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf	*buf_minus(t_buf *for_buf, char **str)
{
	if ((*str)[0] == '-')
	{
		(*str)++;
		for_buf->buf[for_buf->i++] = '-';
		for_buf->for_space = 1;
		for_buf->len--;
	}
	return (for_buf);
}

t_buf	*sign_space(t_print *print, t_buf *for_buf, char **str)
{
	if (print->plus != '+' && print->space == ' ' && (print->type == 'd'
			|| print->type == 'i' || print->type == 'f' || print->type == 'e'))
		if (!((*str)[0] == '-'))
		{
			for_buf->buf[for_buf->i++] = ' ';
			for_buf->for_space = 1;
		}
	if (print->plus == '+' && (print->type == 'd' || print->type == 'i'
			|| print->type == 'f' || print->type == 'e'))
		if (!((*str)[0] == '-'))
		{
			for_buf->buf[for_buf->i++] = '+';
			for_buf->for_space = 1;
		}
	buf_minus(for_buf, str);
	if (print->lattice == '#' && print->type == 'o')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->len++;
	}
	return (for_buf);
}

t_buf	*oct_hex(t_print *print, t_buf *for_buf)
{
	if (print->lattice == '#' && print->type == 'x')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->buf[for_buf->i++] = 'x';
		for_buf->for_space += 2;
	}
	if (print->lattice == '#' && print->type == 'X')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->buf[for_buf->i++] = 'X';
		for_buf->for_space += 2;
	}
	if (print->type == 'p')
	{
		for_buf->buf[for_buf->i++] = '0';
		for_buf->buf[for_buf->i++] = 'x';
		for_buf->for_space += 2;
	}
	return (for_buf);
}

t_buf	*filling_buf(t_print *print, t_buf *for_buf, char **str)
{
	if (for_buf->i <= BUFF_SIZE)
		sign_space(print, for_buf, str);
	else
	{
		print_buf(print, for_buf, 0);
		sign_space(print, for_buf, str);
	}
	if (for_buf->i + 1 <= BUFF_SIZE)
		oct_hex(print, for_buf);
	else
	{
		print_buf(print, for_buf, 0);
		oct_hex(print, for_buf);
	}
	if ((int)(print->precision - for_buf->len) > 0 && print->type != 's')
		while ((int)(print->precision - for_buf->len) > 0)
		{
			for_buf->buf[for_buf->i++] = '0';
			for_buf->len++;
		}
	return (for_buf);
}
