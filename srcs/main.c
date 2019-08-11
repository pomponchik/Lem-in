/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 20:54:43 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_organiser	organiser;

	if (argc == 1)
		return (arg_equal_one());
	if (ft_validate(argv, &organiser) < 0)
		return (main_error());
	print_adjacency(organiser.graph, organiser.size);
	//first_bfs(graph, count);
	return (0);
}
