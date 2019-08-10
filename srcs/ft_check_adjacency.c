/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_adjacency.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:56:26 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:08:29 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_adjacency(t_graph *graph, size_t count)
{
	t_list	*temp;
	t_graph	*temp_two;
	t_graph	*temp_three;

	while (count)
	{
		temp = (graph[count - 1]).adjacency;
		if (temp && temp->next)
		{
			while (temp->next)
			{
                temp_two = temp->content;
                temp_three = temp->next->content;
				if (ft_strcmp((*temp_two).name, (*temp_three).name) == 0)
					return (-1);
				temp = temp->next;
			}
		}
		count--;
	}
	return (0);
}	
