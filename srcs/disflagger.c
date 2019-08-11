/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disflagger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:35:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/11 21:35:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void disflagger(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
		(&(graph[index]))->flag = 0;
		index++;
	}
}
