/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:02:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/31 23:32:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	help_helper(t_graph *graph, size_t i, t_graph *tmp)
{
	ft_putstr(graph[i].name);
	ft_putchar('-');
	ft_putstr(tmp->name);
	ft_putchar('\n');
}

static void	help_print_connections(t_organiser *organizer)
{
	t_graph *graph;
	size_t	i;
	t_list	*adjacency;
	t_graph	*tmp;

	graph = organizer->graph;
	i = 0;
	while (i < organizer->size)
	{
		adjacency = graph[i].adjacency;
		while (adjacency)
		{
			tmp = adjacency->content;
			if (tmp->index > (graph[i]).index)
				help_helper(graph, i, tmp);
			adjacency = adjacency->next;
		}
		i++;
	}
}

static void	fill_graph(t_graph *graph, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		graph[i].index = i;
		i++;
	}
}

void		print_map(t_organiser *organizer)
{
	t_graph *graph;
	size_t	i;

	i = 0;
	graph = organizer->graph;
	fill_graph(graph, organizer->size);
	ft_putnbr(organizer->ants);
	ft_putchar('\n');
	while (i < organizer->size)
	{
		if (graph[i].end == 1)
			ft_putstr("##end\n");
		if (graph[i].start == 1)
			ft_putstr("##start\n");
		ft_putstr(graph[i].name);
		ft_putchar(' ');
		ft_putnbr(graph[i].x);
		ft_putchar(' ');
		ft_putnbr(graph[i].y);
		ft_putchar('\n');
		i++;
	}
	help_print_connections(organizer);
}
