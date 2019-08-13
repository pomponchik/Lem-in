/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:26:40 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/28 15:04:15 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strjoin(char *a, char *b)
{
	char	*c;
	char	*d;
	char	*x;
	size_t	i;

	d = a;
	x = b;
	i = 0;
	c = ft_strnew(ft_strlen(d) + ft_strlen(x));
	while (*d)
		c[i++] = *d++;
	while (*x)
		c[i++] = *x++;
	ft_strdel(&a);
	ft_strdel(&b);
	return (c);
}
