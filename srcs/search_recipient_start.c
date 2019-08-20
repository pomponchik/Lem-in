/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_recipient_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:25:07 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/18 22:25:10 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_graph *search_recipient_start_do(t_list *up)
{
	t_graph *node;

	while (up)
	{
		node = up->content;
		if (!node->stop && !node->ant && node->do_up)
			return (node);
		up = up->next;
	}
	return (NULL);
}

static t_graph *search_recipient_start_up(t_list *up, t_graph *start, t_organiser *organiser)
{
	t_graph *node;
	t_graph *result;
	size_t result_distance;

	if (!up)
		return (NULL);
	if ((result = search_recipient_start_do(up)))
		return (result);
	result_distance = 0;
	while (up)
	{
		node = up->content;
		if (!node->ant && !node->stop)
		{
			node->excess_level = go_down(start, organiser);
			if (!node->excess_level)
				node->stop = 1;
			if (!result_distance && !node->stop)
			{
				result_distance = node->excess_level;
				result = node;
			}
			else if (node->excess_level < result_distance && !node->stop)
			{
				result_distance = node->excess_level;
				result = node;
			}
		}
		up = up->next;
	}
	if (result)
	{
		result->do_up = 1;
		organiser->sorted = insert_in_sorted(organiser->sorted, result);
	}
	return (result);
}

static t_graph *search_recipient_start_down(t_list *down)
{
	t_graph *node;

	if (!down)
		return (NULL);
	while (down)
	{
		node = down->content;
		if (!node->ant && !node->stop)
			return (node);
		down = down->next;
	}
	return (NULL);
}

static t_graph *search_recipient_start_this(t_list *this)
{
	t_graph *node;

	if (!this)
		return (NULL);
	while (this)
	{
		node = this->content;
		if (!node->ant && !node->stop && down_is(node->down))
			return (node);
		this = this->next;
	}
	return (NULL);
}

t_graph *search_recipient_start(t_graph *start, t_organiser *organiser)
{
	t_graph *result;

	if ((result = search_recipient_start_down(start->down)))
		return (result);
	if ((result = search_recipient_start_this(start->this)))
		return (result);
	if ((result = search_recipient_start_up(start->start_up, start, organiser)))
		return (result);
	return (NULL);
}
