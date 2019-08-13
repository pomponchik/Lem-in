/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:04:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 19:12:30 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_map(t_organiser *organizer)
{
	t_graph *graph;
	size_t	i;

	i = 0;
	graph = organiser->graph;
	ft_putnbr(organizer->ants);
	while (i < organiser->size)
	{
		ft_printf("%s %d %d\n", graph[i].name, graph[i].x, graph[i].y);
		i++;
	}

