/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:13:37 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:21:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*octal(uintmax_t n)
{
	char		*c;
	size_t		i;
	char		*d;

	c = "01234567";
	i = count_numbers(n, 8) - 1;
	d = ft_strnew(i + 1);
	if (n == 0)
		return (ft_strdup("0"));
	while (n)
	{
		d[i] = c[n % 8];
		n /= 8;
		i--;
	}
	return (d);
}

char	*ft_octal(t_print *print)
{
	uintmax_t	d;

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
	if (d == 0 && (print->precision == 0))
		return (ft_strdup(""));
	print->lattice = (d == 0) ? 0 : print->lattice;
	return (octal(d));
}
