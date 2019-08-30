/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:29:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:30:21 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_chain(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void		free_ways(t_list *ways)
{
	t_list	*temp;

	temp = ways;
	while (ways)
	{
		free_chain(ways->content);
		ways = ways->next;
	}
	free_chain(temp);
}
