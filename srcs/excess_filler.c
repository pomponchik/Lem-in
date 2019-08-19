/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excess_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:57:50 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/19 23:57:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list *excess_filler(t_graph *graph, size_t size, size_t level_start)
{
	size_t index;
	t_list *result;

	index = 0;
	result = NULL;
	while (index < size)
	{
		if ((graph[index]).level > level_start)
			ft_lstadd(&result, ft_lstnew_no_copy(&(graph[index]), sizeof(t_graph)));
		index++;
	}
	return (result);
}
