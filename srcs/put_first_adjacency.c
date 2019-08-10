/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first_adjacency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:41:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:42:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	get_first_name(char *line, int i, t_graph *graph, size_t count)
{
	while (count)
	{
		if (ft_strncmp((graph[count - 1]).name, line, i) == 0)
			return (count - 1);
		count--;
	}
	return (count);
}

static size_t	get_second_link(char *line, t_graph *graph, size_t count)
{
	while (count)
	{
		if (ft_strcmp((graph[count - 1]).name, line) == 0)
			return (count - 1);
		count--;
	}
	return (count);
}

void			put_first_adjacency(char *line, t_graph **asd, size_t count)
{
	int		i;
	char	*c;
	int		first_link;
	int		second_link;
	t_graph	*graph;

	graph = *asd;
	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	first_link = get_first_name(line, i, graph, count);
	c = ft_strnew(ft_strlen(line) - i);
	c = ft_strcpy(c, line + i + 1);
	second_link = get_second_link(c, graph, count);
	(graph[first_link]).adjacency =
		ft_lstnew_no_copy(&(graph[second_link]), sizeof(t_graph));
	(graph[second_link]).adjacency =
		ft_lstnew_no_copy(&(graph[first_link]), sizeof(t_graph));
	ft_strdel(&c);
	ft_strdel(&line);
}
