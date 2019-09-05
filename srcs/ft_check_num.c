/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:46:25 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:09:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_num(t_help *help, t_help *tmp)
{
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->x == help->x && tmp->y == help->y)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
