/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stopper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 23:46:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:46:02 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			stopper(t_list *way)
{
	t_graph		*node;

	while (way)
	{
		node = way->content;
		if (!node->start && !node->end)
			node->stop = 1;
		way = way->next;
	}
}
