/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:29 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:24:06 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*parser_flag(t_print *print)
{
	size_t i;

	i = 0;
	while (print->flag[i])
	{
		if (print->flag[i] == print->copy[print->i])
		{
			if (print->copy[print->i] == '-' && print->i++)
				print->minus = '-';
			if (print->copy[print->i] == '+' && print->i++)
				print->plus = '+';
			if (print->copy[print->i] == ' ' && print->i++)
				print->space = ' ';
			if (print->copy[print->i] == '#' && print->i++)
				print->lattice = '#';
			if (print->copy[print->i] == '0' && print->i++)
				print->zero = '0';
			i = -1;
		}
		i++;
	}
	return (print);
}
