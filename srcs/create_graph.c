/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:21:12 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 20:55:37 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			set_organiser(t_organiser *organiser,
					size_t count)
{
	organiser->size = count;
	organiser->ants_field = 0;
	organiser->ants_end = 0;
}

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
	graph->name = ft_strdup(tmp->name);
	graph->start = tmp->start;
	graph->end = tmp->end;
	graph->x = tmp->x;
	graph->y = tmp->y;
	graph->adjacency = NULL;
	graph->flag = 0;
	graph->up = NULL;
	graph->down = NULL;
	graph->right = NULL;
	graph->ant = 0;
}

t_graph				*create_graph(t_help *help,
					size_t *count, t_organiser *organiser)
{
	t_graph		*graph;
	t_help		*tmp;
	t_help		*swap;
	int			i;

	i = 0;
	tmp = help;
	*count = count_elem(help);
	graph = (t_graph *)ft_memalloc(sizeof(t_graph) * (*count));
	set_organiser(organiser, *count);
	while (tmp)
	{
		swap = tmp->next;
		copy_data_from_help(&(graph[i]), tmp);
		if (graph[i].start)
			organiser->start = &(graph[i]);
		if (graph[i].end)
			organiser->end = &(graph[i]);
		ft_strdel(&(tmp->name));
		free(tmp);
		tmp = swap;
		i++;
	}
	return ((t_graph *)graph);
}
