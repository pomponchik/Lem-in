/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:43:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:47:04 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		walking_on_way(t_list *way, t_organiser *organiser, size_t go)
{
	t_graph		*node;
	t_list		*previous;

	previous = NULL;
	while (way)
	{
		node = way->content;
		if ((node->ant || node->start) && previous && \
		!((t_graph *)(previous->content))->ant)
			swap(node, previous->content, organiser, go);
		previous = way;
		way = way->next;
	}
}

void			walking_ants(t_organiser *organiser, size_t **lens)
{
	t_list		*ways;
	size_t		go;

	ways = organiser->ways;
	go = get_num_path(ways, lens, organiser->ants);
	while (ways)
	{
		walking_on_way(ways->content, organiser, go);
		if (go)
			go--;
		ways = ways->next;
	}
}
