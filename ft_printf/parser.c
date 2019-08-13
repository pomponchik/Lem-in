/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:35:28 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:23:51 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*parser(t_print *print, t_buf *for_buf)
{
	print->i++;
	if (print->copy[print->i])
	{
		reinicialization(print, &for_buf);
		parser_flag(print);
		ft_atoi_width(print);
		ft_atoi_precision(print);
		parser_size(print);
		parser_type(print);
		what_print(print, for_buf);
		print_percent(print, for_buf);
	}
	return (print);
}
