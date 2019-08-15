/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disflagger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:35:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/11 21:35:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int not_start(t_graph *node)
{
    t_list *adjacency;
	t_graph *temp;

    adjacency = node->adjacency;
    while (adjacency)
	{
		temp = adjacency->content;
		if (!temp->start)
			return (1);
		adjacency = adjacency->next;
	}
	return (0);
}

int not_low(t_graph *node, size_t level_start)
{
	t_list *adjacency;
	t_graph *temp;

	adjacency = node->adjacency;
	while (adjacency)
	{
		temp = adjacency->content;
		if (!temp->start && temp->level <= level_start)
			return (1);
		adjacency = adjacency->next;
	}
	return (0);
}

char check_connections(t_graph *node, t_graph *all, size_t size_all, size_t level_start)
{
	if (!not_start(node))
		return (1);
	if (not_low(node, level_start))
		return (0);
	if (!dijkstra_prove(node))
	{
		disflagger_base(all, size_all);
		return (1);
	}
	disflagger_base(all, size_all);
	return (0);
}

void disflagger_second(t_graph *graph, size_t count, size_t level_start)
{
	size_t index;
	t_graph *temp;

	index = 0;
	temp = graph;
	while (index < count)
	{
		if (!(&(graph[index]))->stop && (&(graph[index]))->level > level_start)
            (&(graph[index]))->stop = check_connections((&(graph[index])), temp, count, level_start);
		index++;
	}
}

//функция сильно изменена
void disflagger_first(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
	    if ((&(graph[index]))->end || (&(graph[index]))->start)
            (&(graph[index]))->stop = 0;
		else if ((&(graph[index]))->flag && (&(graph[index]))->stop)
			(&(graph[index]))->stop = 0;
		else
			(&(graph[index]))->stop = 1;
        (&(graph[index]))->flag = 0;
		index++;
	}
}

void disflagger_base(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
        (&(graph[index]))->flag = 0;
		index++;
	}
}
