/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:37:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/10 21:37:03 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_remake_str(char *c)
{
	char	*d;
	int		i;
	int		x;

	d = ft_strnew(ft_strlen(c) + 1);
	i = 0;
	x = 0;
	while (c[i])
	{
		if (i == 1)
		{
			d[i] = '.';
			i++;
			x = 1;
		}
		if (c[i - x] == '.')
			x = 0;
		d[i] = c[i - x];
		i++;
	}
	ft_strdel(&c);
	return (d);
}
