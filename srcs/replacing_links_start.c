/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacing_links_start.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:36:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/18 22:36:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list *replacing_links_start_down(t_list *adjacency, size_t start_level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (adjacency)
	{
		node = adjacency->content;
		if (node->level < start_level && !node->stop)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		adjacency = adjacency->next;
	}
	return (result);
}

static t_list *replacing_links_start_this(t_list *adjacency, size_t start_level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (adjacency)
	{
		node = adjacency->content;
		if (node->level == start_level && !node->stop)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		adjacency = adjacency->next;
	}
	return (result);
}

static t_list *replacing_links_start_start_up(t_list *adjacency, size_t start_level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (adjacency)
	{
		node = adjacency->content;
		//printf("name: %s\n", node->name);
		if (node->level > start_level && !node->stop)
		{
			//printf("j1\n");
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		}

		adjacency = adjacency->next;
	}
	return (result);
}

void replacing_links_start(t_graph *start)
{
	t_list *adjacency;

	adjacency = start->adjacency;
	start->down = replacing_links_start_down(adjacency, start->level);
	start->this = replacing_links_start_this(adjacency, start->level);
	start->start_up = replacing_links_start_start_up(adjacency, start->level);
}
