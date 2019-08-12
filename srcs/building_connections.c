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

t_list *prove_links(t_list *lst, size_t level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (node->level < level)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		lst = lst->next;
	}
	return (result);
}

t_list *this_links(t_list *lst, size_t level)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (node->level == level && node->down)
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
		lst = lst->next;
	}
	return (result);
}


static void replacing_links_1(t_graph *levels)
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
			node->down = prove_links(node->adjacency, level);
			temp = temp->next;
		}
		levels = levels->up;
	}
}

static void replacing_links_2(t_graph *levels)
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
			node->this = this_links(node->adjacency, level);
			temp = temp->next;
		}
		levels = levels->up;
	}
}

void building_connections(t_organiser *organiser)
{
	first_bfs(organiser->graph, organiser->size, organiser->start, organiser->end);
	replacing_links_1(organiser->end);
	replacing_links_2(organiser->end);
}
