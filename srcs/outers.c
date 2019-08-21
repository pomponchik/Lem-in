/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:15:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/20 21:15:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void outers(t_organiser *organiser)
{
	t_list *nodes;
	t_graph *node;

	if (!organiser->sorted)
		return ;
	nodes = organiser->sorted;
	while (nodes)
	{
		node = nodes->content;
		if (node->ant)
			swap_ant(node, search_recipient_over(node, organiser), organiser);
		nodes = nodes->next;
	}
}
