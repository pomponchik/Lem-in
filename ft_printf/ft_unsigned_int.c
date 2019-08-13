/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:23:01 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ten_count_numbers(uintmax_t n, int k)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= k;
		i++;
	}
	i++;
	return (i);
}

static char			*ft_ten(uintmax_t d)
{
	char	*c;
	int		i;
	char	*k;

	if (d == 0)
		return (ft_strdup("0"));
	c = "0123456789";
	i = ten_count_numbers(d, 10) - 2;
	k = ft_strnew(i + 1);
	while (i != -1)
	{
		k[i] = c[d % 10];
		d /= 10;
		i--;
	}
	return (k);
}

char				*ft_unsigned_int(t_print *print)
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
	return ((ft_ten(d)));
}
