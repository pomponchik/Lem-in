/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:19:06 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_creation_of_str(char *c, t_print *print)
{
	char	*d;
	size_t	i;
	size_t	j;

	d = (c == NULL) ? ft_strdup("(null)") : ft_strdup(c);
	j = ft_strlen(d);
	if (print->precision < -1)
		print->precision *= -1;
	if (print->precision != -1 && j != 0 && (int)(j - print->precision) > 0)
	{
		i = print->precision;
		while (i != j)
		{
			d[i] = '\0';
			i++;
		}
	}
	return (d);
}

char	*ft_create_str(t_print *print)
{
	char	*c;

	c = va_arg(print->ap, char *);
	return (ft_creation_of_str(c, print));
}
