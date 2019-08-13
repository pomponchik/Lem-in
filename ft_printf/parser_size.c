/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:04:18 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:24:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*parser_size(t_print *print)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (print->size[i])
	{
		if (print->copy[print->i] == print->size[i])
		{
			print->p_size[j] = print->copy[print->i];
			j++;
			print->i++;
			i = -1;
		}
		i++;
	}
	return (print);
}
