/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:13:27 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:24:29 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_print *print, t_buf *for_buf)
{
	print->space = 0;
	if (print->copy[print->i] == '%')
		buffer(print, for_buf, "%");
}
