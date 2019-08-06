/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first_adjacency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:09:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/03 17:09:57 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t get_first_name(char *line, int i, t_graph *graph, size_t count)
{
    while (count)
    {
        if (ft_strncmp((graph[count - 1]).name, line, i) == 0)
            return (count - 1);
        count--;
    }
    return (count);
}

static size_t get_second_link(char *line,  t_graph *graph, size_t count)
{
    while (count)
    {
        if (ft_strcmp((graph[count - 1]).name, line) == 0)
            return (count - 1);
        count--;
    }
    return (count);
}
/*
static t_graph      *copy_inform(t_graph *graph)
{
    t_graph *tmp;

    tmp = (t_graph *)malloc(sizeof(t_graph));
    tmp->name = ft_strdup(graph->name);
    tmp->x = graph->x;
    tmp->end = graph->end;
    tmp->y = graph->y;
    tmp->start = graph->start;
    tmp->ant_number = graph->ant_number;
    tmp->adjacency = NULL;
    return (tmp);
}*/

void        put_first_adjacency(char *line, t_graph **asd, size_t count)
{
    int     i;
    char    *c;
    int     first_link;
    int     second_link;
    t_graph *graph;

    graph = *asd;
    i = 0;
    while (line[i] && line[i] != '-')
        i++;
    first_link = get_first_name(line, i, graph, count);
    c = ft_strnew(ft_strlen(line) - i);
    c = ft_strcpy(c, line + i + 1);
    second_link = get_second_link(c, graph, count);
    (graph[first_link]).adjacency = ft_lstnew(&(graph[second_link]), sizeof(t_graph *));
    (graph[second_link]).adjacency = ft_lstnew(&(graph[first_link]), sizeof(t_graph *));
    ft_strdel(&c);
    ft_strdel(&line);
}