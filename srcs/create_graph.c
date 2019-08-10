/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:21:12 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:23:27 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t		count_elem(t_help *help)
{
	t_help	*tmp;
	int		i;

	i = 0;
	tmp = help;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void			copy_data_from_help(t_graph *graph, t_help *tmp)
{
	(graph)->name = ft_strdup(tmp->name);
	(graph)->start = tmp->start;
	(graph)->end = tmp->end;
	(graph)->x = tmp->x;
	(graph)->y = tmp->y;
	(graph)->adjacency = NULL;
	graph->flag = 0;
}

t_graph				*create_graph(t_help *help, int n, size_t *count)
{
	t_graph		*graph;
	t_help		*tmp;
	t_help		*swap;
	int			i;

	i = 0;
	tmp = help;
	*count = count_elem(help);
	graph = (t_graph *)ft_memalloc(sizeof(t_graph) * (*count));
	while (tmp)
	{
		swap = tmp->next;
		copy_data_from_help(&(graph[i]), tmp);
		ft_strdel(&(tmp->name));
		free(tmp);
		tmp = swap;
		i++;
	}
	(graph[0]).ant_number = n;
	return ((t_graph *)graph);
}
