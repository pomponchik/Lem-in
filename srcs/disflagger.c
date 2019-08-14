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

//функция сильно изменена
void disflagger(t_graph *graph, size_t count)
{
	size_t index;

	index = 0;
	while (index < count)
	{
		if ((&(graph[index]))->flag && (&(graph[index]))->stop)
			(&(graph[index]))->stop = 0;
		else
			(&(graph[index]))->stop = 1;
		index++;
	}
}
