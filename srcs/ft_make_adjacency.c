/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_adjacency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:35:58 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:12:00 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_first_name(char *line, int i, t_graph *graph, size_t count)
{
	while (count)
	{
		if (ft_strncmp((graph[count - 1]).name, line, i) == 0
				&& (graph[count - 1].name)[i] == 0)
			return ((int)(count - 1));
		count--;
	}
	return (-1);
}

static int	get_second_link(char *line, t_graph *graph, size_t count)
{
	while (count)
	{
		if (ft_strcmp((graph[count - 1]).name, line) == 0)
			return ((int)(count - 1));
		count--;
	}
	return (-1);
}

static void	connect_link(t_graph **graph, int first_link, int second_link)
{
	if (!(*graph)[first_link].adjacency)
		(*graph)[first_link].adjacency =
			ft_lstnew_no_copy(&((*graph)[second_link]), sizeof(t_graph));
	else
		ft_lstadd(&(((*graph)[first_link]).adjacency),
				ft_lstnew_no_copy(&((*graph)[second_link]), sizeof(t_graph)));
	if (!(*graph)[second_link].adjacency)
		(*graph)[second_link].adjacency =
			ft_lstnew_no_copy(&((*graph)[first_link]), sizeof(t_graph));
	else
		ft_lstadd(&(((*graph)[second_link]).adjacency),
				ft_lstnew_no_copy(&((*graph)[first_link]), sizeof(t_graph)));
}

int			ft_make_adjacency(char *line, t_graph **graph, size_t *count)
{
	int		i;
	char	*c;
	int		first_link;
	int		second_link;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	first_link = get_first_name(line, i, *graph, *count);
	if (first_link == -1)
		return (ft_exit_adjacency_error_two(graph, count));
	c = ft_strnew(ft_strlen(line) - i);
	c = ft_strcpy(c, line + i + 1);
	second_link = get_second_link(c, *graph, *count);
	if (first_link == second_link || second_link == -1)
		return (ft_exit_adjacency_error(c, graph, count));
	connect_link(graph, first_link, second_link);
	return (ft_exit_adjacency_norm(c));
}
