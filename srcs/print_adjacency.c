/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adjacency.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:39:36 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:41:02 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_adjacency(t_graph *graph, size_t count)
{
	t_list	*temp;
	t_graph	*temp2;

	while (count != 0)
	{
		printf("%s->", graph[count - 1].name);
		temp = (graph[count - 1]).adjacency;
		while (temp)
		{
			temp2 = temp->content;
			printf("%s->", (*temp2).name);
			temp = temp->next;
		}
		printf("\n");
		count--;
	}
}
