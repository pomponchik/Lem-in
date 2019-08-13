/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:50:17 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:21:55 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_point(long int n, t_print *print)
{
	char				*c;
	size_t				i;
	char				*x;

	c = "0123456789abcdef";
	i = count_numbers(n, 16) - 1;
	x = ft_strnew(i + 1);
	if (n == 0)
		return ((print->precision == 0) ? ft_strdup("") : ft_strdup("0"));
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	return (x);
}
