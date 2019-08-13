/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:39:16 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/10 22:39:18 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_minus_str(char *c)
{
	char	*d;
	int		i;
	int		x;

	d = ft_strnew(ft_strlen(c));
	i = ft_count_until_one(c) + 1;
	d[0] = c[i];
	d[1] = '.';
	x = 2;
	while (c[i])
	{
		d[x] = c[i];
		i++;
		x++;
	}
	return (d);
}
