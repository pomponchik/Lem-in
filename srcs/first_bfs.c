/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:07:05 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/13 18:52:00 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void recursive_bfs_up(t_graph *end)
// {
// 	size_t level;
// 	size_t hight;
//
// 	level = start->level;
// 	hight = hight_up(end);
// 	while (end)
// 	{
//
// 		end = end->up;
// 	}
// }

static void recursive_bfs_to_end(t_list *level, char *end)
{
	t_list *next_level;
	t_list *head_level;
	t_graph *node;

	next_level = NULL;
	head_level = level;
	while (level)
	{
		node = (t_graph *)(level->content);
		next_level = ft_lst_join(next_level, list_copy_without_flag(node->adjacency));
		if (node->end)
			*end = 1;
		level = level->next;
	}
	free_chain_no_content(head_level);
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
		ft_putstr(node->name);
		ft_putstr("->");
		if (level_num && !node->level && !node->end)
			node->level = level_num;
		next_level = ft_lst_join(next_level, list_copy_without_flag_2(node->adjacency));
		level = level->next;
	}
	if (next_level)
	{
		ft_putstr("\n");
		((t_graph *)(next_level->content))->right = next_level;
		((t_graph *)(level_temp->content))->up = next_level->content;
		recursive_bfs_to_start(next_level, level_num + 1);
	}
}

void first_bfs(t_graph *graph, size_t count, t_graph *start, t_graph *finish)
{
	t_list *l_0;
	char end;

	end = 0;
	l_0 = ft_lstnew_no_copy(start, sizeof(t_graph));
	graph->flag = 1;
	recursive_bfs_to_end(l_0, &end);
	if (!end)
	{
		ft_exit_adjacency(&graph, &count);
		ft_putstr_fd("Error: no way from start to finish.\n", 2);
		exit(1);
	}
	l_0 = ft_lstnew_no_copy(finish, sizeof(t_graph));
	recursive_bfs_to_start(l_0, 0);
	disflagger_first(graph, count);
	disflagger_second(graph, count, start->level);
	free_chain_no_content(l_0);
}
