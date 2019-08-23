/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:09:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/19 20:09:37 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void swap_start(t_graph *recipient, t_organiser *organiser, size_t way_size)
{
	if (!recipient || !organiser->ants)
		return ;
	if (!((way_size == organiser->short_way) || (organiser->short_way - 1 + organiser->ants - 1 >= way_size - 1)))
		return ;
	print_swap(organiser->start, recipient, organiser);
	if (!recipient->end)
		organiser->ants_field++;
	else
		organiser->ants_end++;
	organiser->ants--;
	recipient->ant = 1;
	recipient->ant_number = (organiser->start)->ant_number;
	(organiser->start)->ant_number++;
}

void swap(t_graph *donor, t_graph *recipient, t_organiser *organiser, size_t way_size)
{
	if (!recipient)
		return ;
	if (donor->start)
	{
		swap_start(recipient, organiser, way_size);
		return ;
	}
	print_swap(donor, recipient, organiser);
	if (recipient->end)
	{
		organiser->ants_field--;
		organiser->ants_end++;
		donor->ant = 0;
		return ;
	}
	donor->ant = 0;
	recipient->ant = 1;
	recipient->ant_number = donor->ant_number;
}
