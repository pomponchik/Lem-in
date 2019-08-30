/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:09:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:34:00 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*list_copy(t_list *lst, t_graph *parent)
{
	t_graph	*node;
	t_list	*result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (!node->end && !node->flag && !node->stop)
		{
			node->parent = parent;
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
			node->flag = 1;
		}
		lst = lst->next;
	}
	return (result);
}
