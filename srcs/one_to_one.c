/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:57:08 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/31 17:27:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		one_to_one_prove(t_list *links)
{
	t_graph		*node;

	if (!links)
		return (0);
	while (links)
	{
		node = links->content;
		if (node->end)
			return (1);
		links = links->next;
	}
	return (0);
}

int				one_to_one(t_organiser *organiser, char *filename)
{
	if (!(one_to_one_prove((organiser->start)->adjacency)))
		return (0);
	print_file(filename);
	ft_putchar('\n');
	while (organiser->ants)
		swap_start(organiser->end, organiser, 1);
	return (1);
}
