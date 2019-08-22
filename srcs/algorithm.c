/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:09:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/21 20:39:09 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void algorithm(t_organiser *organiser)
{
	size_t ants;
	char *str;

	ants = organiser->ants;
	ft_putstr("\n");
	while (organiser->ants_end != ants)
	{
		walking_ants(organiser);
		str = ft_strdup("\n");
		ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, 1));
	}
	ft_lst_putstr_free_cs(ft_lst_turn(organiser->commands));
	ft_exit_adjacency(&(organiser->graph), &(organiser->size));
}
