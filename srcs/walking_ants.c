/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/22 20:43:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void walking_on_way(t_list *way, t_organiser *organiser)
{
	t_graph *node;
	t_list *previous;

	previous = NULL;
	while (way)
	{
		node = way->content;
		if ((node->ant || node->start) && previous)
			swap(node, previous->content, organiser);
		previous = way;
		way = way->next;
	}
}

void walking_ants(t_organiser *organiser)
{
	t_list *ways;

	ways = organiser->ways;
	while (ways)
	{
		//if (ways->content_size <= 2 || organiser->ants >= ways->content_size - 2)
			walking_on_way(ways->content, organiser);
		ways = ways->next;
	}
}
