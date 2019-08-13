/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:04:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 20:39:07 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	help_print_connections(t_organiser *organizer)
{
	t_graph *graph;
	size_t	i;
	size_t	j;
	t_list	*adjacency;
	t_graph	*tmp;

	graph = organizer->graph;
	i = 0;
	while (i < organizer->size)
	{
		adjacency = graph[i].adjacency;
		while (adjacency)
		{
			tmp = (t_graph *)(adjacency->content);
			j = 0;
			while (tmp->x != graph[i + j].x && (i + j) < organizer->size)
				j++;
			if (j > 0 && (j + i) < organizer->size)
				ft_printf("%s-%s\n", graph[i].name, tmp->name);
			adjacency = adjacency->next;
		}
		i++;
	}
}

void		print_map(t_organiser *organizer)
{
	t_graph *graph;
	size_t	i;

	i = 0;
	graph = organizer->graph;
	ft_printf("%d\n", organizer->ants);
	while (i < organizer->size)
	{
		ft_printf("%s %d %d\n", graph[i].name, graph[i].x, graph[i].y);
		i++;
	}
	help_print_connections(organizer);
}
