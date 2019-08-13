/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:20:48 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ten_count_numbers(intmax_t n, int k)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= k;
		i++;
	}
	i++;
	return (i);
}

char			*ft_ten(intmax_t d)
{
	char		*c;
	int			i;
	char		*k;
	size_t		j;

	if (d == 0)
		return (ft_strdup("0"));
	if (d == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	c = "0123456789";
	j = 0;
	i = ten_count_numbers(d, 10) - 1;
	(d < 0) ? j++ : j;
	d = (d < 0) ? d * (-1) : d;
	k = ft_strnew(i + j);
	(d < 0) ? i : i--;
	k[0] = (j == 1) ? '-' : k[0];
	while (i != -1)
	{
		k[i + j] = c[d % 10];
		d /= 10;
		i--;
	}
	return (k);
}

char			*ft_int(t_print *print)
{
	intmax_t d;

	d = 0;
	if (ft_strcmp(print->p_size, "") == 0)
		d = (intmax_t)va_arg(print->ap, int);
	else if (ft_strcmp(print->p_size, "h") == 0)
		d = (intmax_t)((short int)va_arg(print->ap, int));
	else if (ft_strcmp(print->p_size, "ll") == 0)
		d = (intmax_t)va_arg(print->ap, long long);
	else if (ft_strcmp(print->p_size, "hh") == 0)
		d = (intmax_t)((char)va_arg(print->ap, int));
	else if (ft_strcmp(print->p_size, "l") == 0)
		d = (intmax_t)va_arg(print->ap, long);
	else if (ft_strcmp(print->p_size, "z") == 0)
		d = (intmax_t)va_arg(print->ap, size_t);
	else if (ft_strcmp(print->p_size, "j") == 0)
		d = (intmax_t)va_arg(print->ap, intmax_t);
	if (d == 0)
		print->zero = (print->precision == -1) ? print->zero : ' ';
	if (d == 0 && (print->precision == 0))
		return (ft_strdup(""));
	return (ft_ten(d));
}
