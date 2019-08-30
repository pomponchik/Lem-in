/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:09:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:23:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	swap_start(t_graph *recipient, t_organiser *organiser, size_t go)
{
	if (!recipient || !organiser->ants || !go)
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

void		swap(t_graph *donor, t_graph *recipient, \
	t_organiser *organiser, size_t go)
{
	if (!recipient)
		return ;
	if (donor->start)
	{
		swap_start(recipient, organiser, go);
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
