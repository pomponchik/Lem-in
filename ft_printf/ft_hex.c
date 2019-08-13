/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:39:02 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:20:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex(uintmax_t n, char a)
{
	char				*c;
	size_t				i;
	char				*x;

	c = (a == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	i = count_numbers(n, 16) - 1;
	x = ft_strnew(i + 1);
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	return (x);
}

char	*ft_hex(t_print *print)
{
	uintmax_t	d;
	char		a;

	a = print->type;
	d = 0;
	if (ft_strcmp(print->p_size, "") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned int);
	else if (ft_strcmp(print->p_size, "h") == 0)
		d = (uintmax_t)((unsigned short int)va_arg(print->ap, unsigned int));
	else if (ft_strcmp(print->p_size, "ll") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned long long);
	else if (ft_strcmp(print->p_size, "hh") == 0)
		d = (uintmax_t)((unsigned char)va_arg(print->ap, unsigned int));
	else if (ft_strcmp(print->p_size, "l") == 0)
		d = (uintmax_t)va_arg(print->ap, unsigned long);
	else if (ft_strcmp(print->p_size, "z") == 0)
		d = (uintmax_t)va_arg(print->ap, size_t);
	else if (ft_strcmp(print->p_size, "j") == 0)
		d = (uintmax_t)va_arg(print->ap, uintmax_t);
	print->lattice = (d == 0) ? 0 : print->lattice;
	if (d == 0 && (print->precision == 0))
		return (ft_strdup(""));
	return ((d == 0) ? ft_strdup("0") : hex(d, a));
}
