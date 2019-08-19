/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:37:57 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/19 21:37:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int down_is(t_list *down)
{
	t_graph *node;

	while (down)
	{
		node = down->content;
		if (!node->ant)
			return (1);
		down = down->next;
	}
	return (0);
}
