/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/31 21:11:35 by hlarson          ###   ########.fr       */
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
	bfs(&organiser, argv[1]);
	print_file(argv[1]);
	algorithm(&organiser);
	return (0);
}
