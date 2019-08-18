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
		if (!node->ant && node->do_up)
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
	size_t temp_distance;

	if (!up)
		return (NULL);
	if ((result = search_recipient_start_do(up)))
		return (result);
	result_distance = 0;
	while (up)
	{
		node = up->content;
		temp_distance = go_down(start, organiser);
		if (!result_distance)
		{
			result_distance = temp_distance;
			result = node;
		}
		else if (temp_distance < result_distance)
		{
			result_distance = temp_distance;
			result = node;
		}
		up = up->next;
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
		if (!node->ant)
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
		if (!node->ant)
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
	if ((result = search_recipient_start_this(start->down)))
		return (result);
	if ((result = search_recipient_start_up(start->down, start, organiser)))
		return (result);
	return (NULL);
}
