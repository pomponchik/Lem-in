/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:57:51 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_do_work(char *d, int j, int k, char a)
{
	char	*c;
	char	*number;

	c = ft_strnew(1);
	c[0] = a;
	number = ft_itoa(j);
	if (ft_strlen(number) == 1)
		number = ft_strjoin_fr_both(ft_strdup("0"), number);
	if (k == -1)
		d = ft_strjoin_fr_both(ft_strjoin_fr_both
(ft_strjoin_fr_both(d, c), ft_strdup("-")), number);
	else if (k == 1 || k == 0)
		d = ft_strjoin_fr_both(ft_strjoin_fr_both
(ft_strjoin_fr_both(d, c), ft_strdup("+")), number);
	return (d);
}

static char		*ft_work(char *c, t_print *print, int precision)
{
	int		j;
	int		k;
	char	*d;
	char	*x;

	if ((j = (get_before_dot_float(c) - 1)) > 1)
	{
		d = ft_remake_str(c);
		k = 1;
	}
	else if (c[1] == '.' && c[2] != '0' && c[0] != '0')
	{
		d = c;
		k = 0;
	}
	else
	{
		j = ft_count_until_one(c);
		k = -1;
		d = ft_make_minus_str(c);
	}
	d = ft_make_precision(d, precision, print);
	x = ft_do_work(d, j, k, print->type);
	return (x);
}

static char		*ft_create_float(long double d, int i, t_print *print)
{
	char					*c;
	unsigned long long		k;
	int						s;
	long long				e;

	i--;
	u_q.ld = d;
	s = (u_q.x[1] & 0x8000) >> 15;
	e = (u_q.x[1] & 0x7FFF) - 16383;
	k = (u_q.x[0] & 0xffffffffffffffff);
	c = ft_pow_long_x(e, k);
	c = ft_work(c, print, i);
	c = (s == 1) ? ft_strjoin_fr_both(ft_strdup("-"), c) : c;
	return (c);
}

char			*ft_type_e_l(t_print *print)
{
	long double	d;
	int			i;

	i = 6;
	d = (long double)va_arg(print->ap, long double);
	if (print->precision != -1)
		i = print->precision;
	return (ft_create_float(d, i, print));
}
