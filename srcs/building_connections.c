/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_connections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:15:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/11 20:15:02 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph *building_connections(t_graph *graph, size_t *count)
{
	first_bfs(graph, *count);
}
