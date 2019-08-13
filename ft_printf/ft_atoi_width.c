/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:28:58 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:26:12 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_atoi_width(t_print *print)
{
	if (print->copy[print->i] == '*')
	{
		print->width = va_arg(print->ap, unsigned int);
		print->i++;
		if (print->width < 0)
		{
			print->width *= -1;
			print->minus = '-';
		}
	}
	if (print->copy[print->i] >= '0' && print->copy[print->i] <= '9')
		print->width = 0;
	while (print->copy[print->i] >= '0' && print->copy[print->i] <= '9')
	{
		print->width = print->width * 10 + (print->copy[print->i] - '0');
		print->i++;
	}
	return (print);
}
