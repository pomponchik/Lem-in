/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:07:05 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/10 22:07:08 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t search_start(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
		if ((graph[index]).start)
			return (index);
		index++;
	}
	return (0);
}

static size_t search_end(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
		if ((graph[index]).end)
			return (index);
		index++;
	}
	return (0);
}

static void recursive_bfs_to_end(t_list *level, char *end)
{
	t_list *next_level;
	t_graph *node;

	next_level = NULL;
	while (level)
	{
		node = (t_graph *)(level->content);
		next_level = ft_lst_join(next_level, list_copy_without_flag(node->adjacency));
		ft_putstr(node->name);
		ft_putstr("->");
		if (node->end)
			*end = 1;
		level = level->next;
	}
	free_chain_no_content(level);
	ft_putstr("\n");
	if (next_level)
		recursive_bfs_to_end(next_level, end);
}

static void recursive_bfs_to_start(t_list *level, size_t level_num)
{
	t_list *next_level;
	t_list *level_temp;
	t_graph *node;

	next_level = NULL;
	level_temp = level;
	while (level)
	{
		node = (t_graph *)(level->content);
		node->level = level_num;
		next_level = ft_lst_join(next_level, list_copy_without_flag_2(node->adjacency));
		ft_putstr(node->name);
		ft_putstr("->");
		level = level->next;
	}
	ft_putstr("\n");
	if (next_level)
	{
		((t_graph *)(next_level->content))->right = next_level;
		((t_graph *)(level_temp->content))->up = next_level->content;
		recursive_bfs_to_start(next_level);
	}
}

void first_bfs(t_graph *graph, size_t count)
{
	t_list *l_0;
	char end;

	end = 0;
	l_0 = ft_lstnew_no_copy(&graph[search_start(graph, count)], sizeof(t_graph));
	graph->flag = 1;
	ft_putstr("\n\nbfs to end:\n\n");
	recursive_bfs_to_end(l_0, &end);
	if (!end)
	{
		ft_exit_adjacency(&graph, &count);
		ft_putstr_fd("Error: no way from start to finish.\n", 2);
		exit(1);
	}
	l_0 = ft_lstnew_no_copy(&graph[search_end(graph, count)], sizeof(t_graph));
	ft_putstr("\nbfs to start:\n");
	recursive_bfs_to_start(l_0);
}