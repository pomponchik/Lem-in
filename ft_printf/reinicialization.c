/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinicialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:24:27 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:24:43 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*reinicialization(t_print *print, t_buf **buf)
{
	print->type = '\0';
	print->minus = '\0';
	print->plus = '\0';
	print->space = '\0';
	print->lattice = '\0';
	print->zero = ' ';
	print->p_size[0] = '\0';
	print->p_size[1] = '\0';
	print->p_size[2] = '\0';
	print->width = 0;
	print->precision = -1;
	(*buf)->for_space = 0;
	(*buf)->sign = '\0';
	return (print);
}
