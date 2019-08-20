/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_connections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:15:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/11 20:15:02 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list *down_links(t_list *lst, size_t level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (node->level < level && !node->stop)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		lst = lst->next;
	}
	return (result);
}

static t_list *this_links(t_list *lst, size_t level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (node->level == level && !node->stop)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		lst = lst->next;
	}
	return (result);
}

static t_list *up_links(t_list *lst, size_t level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (node->level > level && !node->stop)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		lst = lst->next;
	}
	return (result);
}

static void replacing_links(t_graph *levels, size_t level_start)
{
	t_list *temp;
	t_graph *node;
	size_t level;

	while (levels)
	{
		temp = levels->right;
		level = levels->level;
		while (temp)
		{
			node = temp->content;
			if (!node->start && !node->stop)
				node->this = this_links(node->adjacency, level);
			if (!node->start && !node->stop && node->level > level_start)
				node->start_up = up_links(node->adjacency, level);
			if (!node->start && !node->stop)
				node->down = down_links(node->adjacency, level);
			temp = temp->next;
		}
		levels = levels->up;
	}
}

void building_connections(t_organiser *organiser)
{
	first_bfs(organiser->graph, organiser->size, organiser->end, organiser);
	replacing_links(organiser->end, organiser->level_start);
	replacing_links_start(organiser->start);
	organiser->excess = excess_filler(organiser->graph, organiser->size, organiser->level_start);
	organiser->sorted = NULL;
	organiser->commands = NULL;
}
