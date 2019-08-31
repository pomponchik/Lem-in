/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:59:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:40:02 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*create_way(t_graph *start)
{
	t_list		*result;

	result = NULL;
	while (start)
	{
		ft_lstadd(&result, ft_lstnew_no_copy(start, sizeof(t_graph)));
		start = start->parent;
	}
	return (result);
}

static t_list	*new_way(t_list *level)
{
	t_list		*next_level;
	t_list		*level_temp;
	t_list		*result;
	t_graph		*node;

	next_level = NULL;
	result = NULL;
	level_temp = level;
	while (level)
	{
		node = level->content;
		if (node->start)
			result = create_way(node);
		next_level = ft_lst_join(next_level, list_copy(node->adjacency, node));
		level = level->next;
	}
	free_chain(level_temp);
	if (result)
	{
		free_chain(next_level);
		return (result);
	}
	if (next_level)
		return (new_way(next_level));
	return (NULL);
}

static t_list	*get_ways(t_graph *end, t_organiser *organiser)
{
	t_list		*result;
	t_list		*way;
	t_list		*temp;

	result = NULL;
	while ((way = new_way(ft_lstnew_no_copy(end, sizeof(t_graph)))))
	{
		stopper(way);
		temp = ft_lstnew_no_copy(way, ft_lst_chain_len(way));
		ft_lstadd(&result, temp);
		disflagger(organiser->graph, organiser->size);
	}
	return (ft_lst_turn(result));
}

void			bfs(t_organiser *organiser)
{
	t_list		*ways;

	if (one_to_one(organiser))
		one_way(&(organiser->graph), &(organiser->size));
	ways = get_ways(organiser->end, organiser);
	if (!ways)
		no_way(&(organiser->graph), &(organiser->size));
	organiser->short_way = ways->content_size;
	organiser->ways = ways;
}
