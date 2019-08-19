/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_recipient_usual.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:42:45 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/19 21:42:47 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_graph *search_recipient_usual_down(t_list *down)
{
	t_graph *node;

	if (!down)
		return (NULL);
	while (down)
	{
		node = down->content;
		if (!node->stop && !node->ant)
			return (node);
		down = down->next;
	}
	return (NULL);
}

static t_graph *search_recipient_usual_this(t_list *this)
{
	t_graph *node;

	if (!this)
		return (NULL);
	while (this)
	{
		node = this->content;
		if (!node->stop && !node->ant && down_is(node->down))
			return (node);
		this = this->next;
	}
	return (NULL);
}


t_graph *search_recipient_usual(t_graph *node, t_organiser *organiser)
{
	t_graph *result;

	if (node->level > organiser->level_start)
		return (search_recipient_over(node, organiser));
	if ((result = search_recipient_usual_down(node->down)))
		return (result);
	if ((result = search_recipient_usual_this(node->this)))
		return (result);
	return (NULL);
}

// static t_graph *search_recipient_this(t_list *this)
// {
// 	t_graph *node;
//
// 	if (!this)
// 		return (NULL);
// 	while (this)
// 	{
// 		node = this->content;
// 		if (!node->stop && !node->ant && down_is(node->down) && !node->start)
// 			return (node);
// 		this = this->next;
// 	}
// 	return (NULL);
// }
//
// static t_graph *search_recipient(t_list *down, t_list *this/*, size_t level_start, t_graph *node*/)
// {
// 	t_graph *recipient;
// 	t_graph *temp;
// 	t_list *down_temp;
//
// 	recipient = NULL;
// 	down_temp = down;
// 	while (down)
// 	{
// 		temp = down->content;
// 		if (!temp->ant && !temp->stop && !temp->start)
// 		{
// 			recipient = temp;
// 			break ;
// 		}
// 		down = down->next;
// 	}
// 	if (!recipient)
// 		return (search_recipient_this(this));
// 	return (recipient);
// }
