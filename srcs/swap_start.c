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

static void swap_start_swap(t_graph *recipient, t_organiser *organiser)
{
	if (!recipient)
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

void swap_start(t_organiser *organiser)
{
	t_graph *recipient;

	while (organiser->ants && (recipient = search_recipient_start(organiser->start, organiser)))
	{
		if (recipient->level > organiser->level_start)
		{
			if (organiser->level_start + recipient->excess_level > organiser->ants)
				return ;
		}
		swap_start_swap(recipient, organiser);
	}
}
