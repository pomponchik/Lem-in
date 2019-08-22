/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:04:24 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/22 20:04:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void no_way(t_graph **graph, size_t *count)
{
	ft_exit_adjacency(graph, count);
	ft_putstr_fd("Error: no way from start to finish.\n", 2);
	exit(1);
}
