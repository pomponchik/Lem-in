/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:44:16 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:25:51 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buf	*filling_space(t_print *print, t_buf *for_buf, int i)
{
	while (((int)(print->width - for_buf->len - for_buf->for_space - i)) > 0)
	{
		if (for_buf->i <= BUFF_SIZE)
			for_buf->buf[for_buf->i++] = print->zero;
		else
		{
			print_buf(print, for_buf, 0);
			for_buf->buf[for_buf->i++] = print->zero;
		}
		i++;
	}
	return (for_buf);
}

t_buf	*for_filling_buf_byspace(t_print *print, t_buf *for_buf)
{
	if (print->space == ' ' && !for_buf->sign && print->minus != '-' &&
			print->zero != '0' && print->type != 'u' && print->type != 'c')
	{
		if (for_buf->i <= BUFF_SIZE)
			for_buf->buf[for_buf->i++] = ' ';
		else
		{
			print_buf(print, for_buf, 0);
			for_buf->buf[for_buf->i++] = ' ';
		}
	}
	if (print->zero == '0')
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
	}
	return (for_buf);
}

t_print	*for_filling_buf_byspace_2(t_print *print, t_buf *for_buf)
{
	if (print->minus == '-' || (for_buf->sign && print->zero == '0' &&
			print->type != 'd' && print->type != 'i' && print->type != 'f'))
		print->zero = ' ';
	if (print->minus != '-' && print->precision >= 0 && print->type != 'f')
		print->zero = ' ';
	return (print);
}

int		for_filling_buf_byspace_3(t_print *print, t_buf *for_buf)
{
	if ((for_buf->sign == '+' || for_buf->sign == '-') && print->zero == '0')
	{
		if (for_buf->i <= BUFF_SIZE)
			for_buf->buf[for_buf->i++] = for_buf->sign;
		else
		{
			print_buf(print, for_buf, 0);
			for_buf->buf[for_buf->i++] = for_buf->sign;
		}
		return (1);
	}
	else
		return (0);
}

t_buf	*filling_buf_byspace(t_print *print, t_buf *for_buf)
{
	for_filling_buf_byspace_2(print, for_buf);
	if (!for_filling_buf_byspace_3(print, for_buf))
		if (for_buf->for_space && print->space == ' ' && !for_buf->sign
		&& print->type != 'p' && print->type != 'c' && print->type != 's'
		&& print->zero == '0')
		{
			if (for_buf->i <= BUFF_SIZE)
				for_buf->buf[for_buf->i++] = ' ';
			else
			{
				print_buf(print, for_buf, 0);
				for_buf->buf[for_buf->i++] = ' ';
			}
		}
	for_filling_buf_byspace(print, for_buf);
	filling_space(print, for_buf, 0);
	return (for_buf);
}
