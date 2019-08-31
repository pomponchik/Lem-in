/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:32:46 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 16:26:41 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

void	find_values(t_visu *visu, t_organiser *organizer)
{
	t_graph	*graph;
	size_t	i;

	graph = (t_graph *)(organizer->graph);
	i = 0;
	while (i < organizer->size)
	{
		if (graph[i].x < visu->x_min)
			visu->x_min = graph[i].x;
		if (graph[i].x > visu->x_max)
			visu->x_max = graph[i].x;
		if (graph[i].y < visu->y_min)
			visu->y_min = graph[i].y;
		if (graph[i].y > visu->y_max)
			visu->y_max = graph[i].y;
		i++;
	}
}
