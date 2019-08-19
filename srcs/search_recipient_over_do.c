/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_recipient_over_do.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:10:37 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/20 00:10:41 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_graph *search_do_down(t_list *down)
{
	t_graph *node;

	while (down)
	{
		node = down->content;
		if (node->do_down)
			return (node);
		down = down->next;
	}
	return (NULL);
}

static t_graph *search_do_up(t_list *up)
{
	t_graph *node;

	while (up)
	{
		node = up->content;
		if (node->do_up)
			return (node);
		up = up->next;
	}
	return (NULL);
}

static t_graph *search_do_this(t_list *this)
{
	t_graph *node;

	while (this)
	{
		node = this->content;
		if (node->do_this)
			return (node);
		this = this->next;
	}
	return (NULL);
}

t_graph *search_recipient_over_do(t_graph *node)
{
	t_graph *result;

	if ((result = search_do_down(node->down)))
		return (result);
	if ((result = search_do_up(node->start_up)))
		return (result);
	if ((result = search_do_this(node->this)))
		return (result);
	return (NULL);
}
