/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:48:00 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:23:48 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_exit_checking(t_help **our_list)
{
	t_help	*tmp;
	t_help	*help;

	help = *our_list;
	while (help)
	{
		tmp = help->next;
		ft_strdel(&(help->name));
		free(help);
		help = tmp;
	}
	return (-1);
}
