/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:26:56 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:19:56 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_color_print(t_print *print)
{
	if (!ft_strcmp(print->color, "{red}"))
		return (1);
	if (!ft_strcmp(print->color, "{green}"))
		return (2);
	if (!ft_strcmp(print->color, "{yellow}"))
		return (3);
	if (!ft_strcmp(print->color, "{blue}"))
		return (4);
	if (!ft_strcmp(print->color, "{purple}"))
		return (5);
	if (!ft_strcmp(print->color, "{cyan}"))
		return (6);
	if (!ft_strcmp(print->color, "{eoc}"))
		return (7);
	return (0);
}
