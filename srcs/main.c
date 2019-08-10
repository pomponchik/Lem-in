/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:43:09 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_graph	*graph;
	size_t	count;

	graph = NULL;
	count = 0;
	if (argc == 1)
		return (arg_equal_one());
	if (ft_validate(&graph, argv, &count) < 0)
		return (main_error());
	print_adjacency(graph, count);
	first_bfs(graph, count);
	return (0);
}
