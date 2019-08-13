/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_right_alignment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:20:59 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:18:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf		*sign_space_buf_2(t_print *print, t_buf *for_buf, char **str)
{
	if (print->plus != '+' && print->space == ' ' && (print->type == 'd'
	|| print->type == 'i' || print->type == 'e' || print->type == 'f'))
		if (!((*str)[0] == '-'))
			for_buf->for_space = 1;
	if (print->plus == '+' && (print->type == 'd' || print->type == 'i'
	|| print->type == 'f' || print->type == 'e'))
		if (!((*str)[0] == '-'))
		{
			for_buf->sign = '+';
			for_buf->for_space = 1;
		}
	if ((*str)[0] == '-')
	{
		for_buf->sign = '-';
		for_buf->for_space = 1;
		for_buf->len--;
		(*str)++;
	}
	if (print->lattice == '#' && print->type == 'o')
		for_buf->for_space = 1;
	return (for_buf);
}

t_buf		*filling_buf_2(t_print *print, t_buf *for_buf, char **str)
{
	sign_space_buf_2(print, for_buf, str);
	if (print->lattice == '#' && print->type == 'x')
		for_buf->for_space = 2;
	if (print->lattice == '#' && print->type == 'X')
		for_buf->for_space = 2;
	if (print->type == 'p')
		for_buf->for_space = 2;
	if ((int)(print->precision - for_buf->len) > 0 && print->type != 's' &&
	(print->type == 'd' || print->type == 'i' || print->type == 'u' ||
	print->type == 'x' || print->type == 'X'))
		for_buf->len += (int)(print->precision - for_buf->len);
	if ((int)(print->precision - for_buf->len - for_buf->for_space) > 0 &&
	print->type != 's' && print->type == 'o')
		for_buf->len += (int)(print->precision - for_buf->len -
				for_buf->for_space);
	return (for_buf);
}

t_buf		*filling_sign_space_buf_2(t_print *print, t_buf *for_buf, int *len)
{
	if (print->zero != '0')
	{
		if (for_buf->sign == '-')
			for_buf->buf[for_buf->i++] = for_buf->sign;
		else if (for_buf->for_space && print->plus == '+')
			for_buf->buf[for_buf->i++] = for_buf->sign;
	}
	if (print->lattice == '#' && print->type == 'o')
	{
		for_buf->buf[for_buf->i++] = '0';
		(*len)++;
	}
	return (for_buf);
}

t_buf		*filling_hex_point_buf_2(t_print *print, t_buf *for_buf)
{
	if (print->zero != '0')
	{
		if (print->lattice == '#' && print->type == 'x')
		{
			for_buf->buf[for_buf->i++] = '0';
			for_buf->buf[for_buf->i++] = 'x';
		}
		if (print->lattice == '#' && print->type == 'X')
		{
			for_buf->buf[for_buf->i++] = '0';
			for_buf->buf[for_buf->i++] = 'X';
		}
		if (print->type == 'p')
		{
			for_buf->buf[for_buf->i++] = '0';
			for_buf->buf[for_buf->i++] = 'x';
		}
	}
	return (for_buf);
}

t_buf		*filling_buf_start(t_print *print, t_buf *for_buf, int len)
{
	if (for_buf->i <= BUFF_SIZE)
		filling_sign_space_buf_2(print, for_buf, &len);
	else
	{
		print_buf(print, for_buf, 0);
		filling_sign_space_buf_2(print, for_buf, &len);
	}
	if (for_buf->i <= BUFF_SIZE)
		filling_hex_point_buf_2(print, for_buf);
	else
	{
		print_buf(print, for_buf, 0);
		filling_hex_point_buf_2(print, for_buf);
	}
	while ((int)(print->precision - len) > 0 && print->type != 's')
	{
		for_buf->buf[for_buf->i++] = '0';
		len++;
	}
	return (for_buf);
}
