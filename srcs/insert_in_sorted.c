/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:25:46 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/20 21:25:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char insert(t_list *new, t_list *current, t_list *previous)
{
	t_graph *node_new;
	t_graph *node_current;
	t_graph *node_previous;

	node_new = new->content;
	node_current = current->content;
	node_previous = previous->content;
	if (node_new->excess_level >= node_previous->excess_level && node_new->excess_level <= node_current->excess_level)
	{
		new->next = current;
		previous->next = new;
		return (1);
	}
	return (0);
}

t_list *insert_in_sorted(t_list *sorted, t_graph *node)
{
	t_list *new;
	t_list *previous;
	t_list *sorted_temp;
	t_graph *node_temp;
	char flag;

	if (!node)
		return (sorted);
	new = ft_lstnew_no_copy(node, sizeof(t_graph));
	if (!sorted)
		return (new);
	node_temp = sorted->content;
	if (node->excess_level < node_temp->excess_level)
	{
		new->next = sorted;
		return (new);
	}
	flag = 0;
	previous = NULL;
	sorted_temp = sorted;
	while (sorted->next)
	{
		if ((flag = insert(new, sorted->next, previous)))
			break ;
		previous = sorted;
		sorted = sorted->next;
	}
	if (!flag)
		ft_lstadd_to_end(&(sorted), new);
	return (sorted_temp);
}
