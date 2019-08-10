/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_adjacency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:00:49 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/04 17:01:24 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     ft_exit_adjacency(t_graph **graph, size_t *count)
{
    t_list  *adjacency;

    while (*count)
    {
        adjacency = ((*graph)[*count - 1]).adjacency;
        while (adjacency)
            adjacency = ft_free_and_return(adjacency, adjacency->next);
        free(((*graph)[*count - 1]).name);
        *count = *count - 1;
    }
    free(*graph);
    return (-1);
}

int     ft_exit_adjacency_norm(char *c, char *line)
{
	ft_strdel(&c);
	ft_strdel(&line);
	return (0);
}

int     ft_exit_adjacency_error(char *c, char *line, t_graph **graph, size_t *count)
{
	ft_strdel(&c);
	ft_strdel(&line);
	ft_exit_adjacency(graph, count);
	*count = 0;
	return (-1);
}

int     ft_exit_adjacency_error_two(char *line, t_graph **graph, size_t *count)
{
    ft_strdel(&line);
    ft_exit_adjacency(graph, count);
    *count = 0;
    return (-1);
}