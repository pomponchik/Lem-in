/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_recipient_over.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:41:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/19 23:41:54 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_graph *search_new_way(t_graph *node, t_organiser *organiser)
{
	t_list *adjacency;
	t_graph *node_temp;
	size_t temp_steps;
	size_t steps;
	t_graph *result;

	adjacency = node->adjacency;
	steps = 0;
	result = NULL;
	while (adjacency)
	{
		node_temp = adjacency->content;
		if (!node->stop && !node->start && !node->ant)
		{
			if (node_temp->level <= organiser->level_start)
				return (node_temp);
			temp_steps = go_down(node_temp, organiser);
			if (temp_steps)
			{
				if (temp_steps < steps || !steps)
				{
					steps = temp_steps;
					result = node;
				}
			}
		}
		adjacency = adjacency->next;
	}
	return (result);
}

t_graph *search_recipient_over(t_graph *node, t_organiser *organiser)
{
	t_graph *result;

	if ((result = search_recipient_over_do(node)))
		return (result);
	if ((result = search_new_way(node, organiser)))
	{
		if (result->level > node->level)
			result->do_up = 1;
		if (result->level < node->level)
			result->do_down = 1;
		if (result->level == node->level)
			result->do_this = 1;
		return (result);
	}
	return (NULL);
}
