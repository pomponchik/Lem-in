/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_with_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:55:07 by rpizpot           #+#    #+#             */
/*   Updated: 2019/07/28 12:55:07 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_help_with_precision(char **d, int k)
{
	char	*x;
	char	*c;
	char	*a;
	char	*y;

	c = *d;
	x = ft_strjoin(ft_strdup("0."), ft_strnew_zero(k));
	a = ft_strjoin(x, ft_strdup("1"));
	y = ft_long_sum_dot(c, a);
	ft_strdel(&c);
	*d = y;
	ft_strdel(&a);
}
