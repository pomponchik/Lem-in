/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:09:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/10 22:09:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list *list_copy_without_flag(t_list *lst)
{
	t_graph *node;
	t_list *result;

	result = NULL;
	while (lst)
	{
		node = lst->content;
		if (!node->flag)
		{
			ft_lstadd(&result, ft_lstnew_no_copy(node, sizeof(t_graph)));
			node->flag = 1;
		}
		lst = lst->next;
	}
	return (result);
}
