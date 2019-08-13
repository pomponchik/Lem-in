/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:21:30 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:45:08 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*round_one(int *j, char *c)
{
	char	*d;

	d = ft_long_sum_dot(c, "1.0");
	*j = (ft_strlen(d) > ft_strlen(c)) ? *j + 1 : *j;
	ft_strdel(&c);
	c = d;
	return (c);
}

char	*round_two(int *j, char *c)
{
	char	*d;

	d = ft_long_sum_dot(c, "1.0");
	d[(*j) - 1] = ((d[(*j) - 1] - '0') % 2 != 0) ?
			d[(*j) - 1] - 1 : d[(*j) - 1];
	*j = (ft_strlen(d) > ft_strlen(c)) ? *j + 1 : *j;
	ft_strdel(&c);
	c = d;
	return (c);
}

char	*only_before_dot(char *c, t_print *print)
{
	int		i;
	int		j;
	char	*d;

	j = get_before_dot_float(c);
	if (c[j + 1] > '5' || (c[j + 1] == '5' && ft_strlen(c) > (size_t)(j + 2)))
		c = round_one(&j, c);
	else if (c[j + 1] == '5')
		c = round_two(&j, c);
	j = (print->lattice == '#') ? j + 1 : j;
	d = ft_strnew(j + 1);
	i = 0;
	while (i <= j - 1)
	{
		d[i] = c[i];
		i++;
	}
	ft_strdel(&c);
	if (ft_strlen(d) == 0)
	{
		ft_strdel(&d);
		d = ft_strdup("0");
	}
	return (d);
}

char	*ft_make_precision(char *c, int i, t_print *print)
{
	int		j;

	j = get_after_dot_float(c);
	if (i == -1)
		c = only_before_dot(c, print);
	else if (i == j)
		c = ft_strjoin_fr_both(c, ft_strdup("0"));
	else if (i > j)
		c = ft_strjoin_fr_both(c, ft_strnew_zero(i - j + 1));
	else if (i < j)
		c = ft_right_precision(c, i);
	return (c);
}
