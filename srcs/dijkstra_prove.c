/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_prove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:31:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/15 14:31:04 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int dijkstra_prove(t_graph *node)
{
	t_list *adjacency;
	t_list *adjacency_2;
	t_graph *temp;

	if (!node)
		return (0);
	node->flag = 1;
	adjacency = node->adjacency;
	adjacency_2 = adjacency;
	while (adjacency)
	{
		temp = adjacency->content;
		if (!temp->start && !temp->flag && temp->end)
			return (1);
		adjacency = adjacency->next;
	}
	while (adjacency_2)
	{
		temp = adjacency_2->content;
		if (!temp->start && !temp->flag)
			dijkstra_prove(temp);
		adjacency_2 = adjacency_2->next;
	}
	return (0);
}
