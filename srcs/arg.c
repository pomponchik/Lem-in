/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:51:43 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 19:00:22 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		arg_equal_one(void)
{
	ft_putstr("\n");
	return (1);
}

int		main_error(t_organiser *organizer)
{
	ft_del_map(organizer);
	ft_putstr("Error");
	return (-1);
}
