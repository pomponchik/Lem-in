/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 19:00:54 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_organiser	organiser;

	argv = NULL;
	if (argc != 1)
		return (arg_equal_one());
	if (ft_validate(&organiser) < 0)
		return (main_error(&organiser));
	bfs(&organiser);
	print_map(&organiser);
	algorithm(&organiser);
	ft_del_map(&organiser);
	return (0);
}
